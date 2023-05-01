use std::{io, io::Write, str, mem::take, ops::{Add, Deref, Index}};

pub struct UnsafeScanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> UnsafeScanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    pub fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

#[derive(Clone)]
struct Pos {
    pos : Vec<i32>
}

impl Pos {
    fn new(pos : Vec<i32>) -> Self {
        Self {pos,}
    }
}

impl Index<usize> for Pos {
    fn index(&self, index: usize) -> &Self::Output {
        &self.pos[index]
    }
    type Output = i32;
}

impl Deref for Pos {
    fn deref(&self) -> &Self::Target {
        &self.pos
    }
    type Target = Vec<i32>;
}

impl Add for Pos {
    /// addition for Pos would be Some(added) if it is non-negative.
    /// else, it would be None.
    fn add(self, rhs: Self) -> Self::Output {
        assert_eq!(self.len(), rhs.len());
        let n = self.len();
        let mut ret = vec![0;n];
        for i in 0..n {
            ret[i] = self[i] + rhs[i];
            if ret[i] < 0 {
                return None;
            }
        }
        Some(Pos::new(ret))
    }
    type Output = Option<Self>;
}

fn work(arr : &mut Vec<Vec<i8>>, v1 : Pos, v2 : Pos) {
    let r#move : Vec<Pos> = vec![Pos::new(vec![0,1]), Pos::new(vec![1,0]), Pos::new(vec![0,-1]), Pos::new(vec![-1,0])];
    let (mut q1, mut q2) = (vec![v1.clone()], vec![v2.clone()]);
    let (m, n) = (arr.len(), arr[0].len());
    let mut spread = vec![vec![false;n];m];
    let mut spread_now = Vec::<Pos>::new();
    // arr : ㅇㅇ
    // spread : ㅇㅇ (미리 온 친구들 저장. true/false)

    spread[v1[0] as usize][v1[1] as usize] = true;
    spread[v2[0] as usize][v2[1] as usize] = true;
    
    while !q1.is_empty() || !q2.is_empty() {
        let (mut tq1, mut tq2, mut cur_spread) =
            (take(&mut q1), take(&mut q2), Vec::<Pos>::new());

        while let Some(f) = tq1.pop() {
            if arr[f[0] as usize][f[1] as usize] == 3 {continue;}
            for dir in &r#move {
                if let Some(nxt) = f.clone()+dir.clone() {
                    let (nx, ny) = (nxt[0] as usize, nxt[1] as usize);
                    if nx<m && ny<n && !spread[nx][ny] && (arr[nx][ny]==0 || arr[nx][ny]==2) {
                        arr[nx][ny]+=1;
                        q1.insert(0, nxt.clone());
                        spread_now.push(nxt);
                    }
                }
            }
        }

        while let Some(f) = tq2.pop() {
            if arr[f[0] as usize][f[1] as usize] == 3 {continue;}
            for dir in &r#move {
                if let Some(nxt) = f.clone()+dir.clone() {
                    let (nx, ny) = (nxt[0] as usize, nxt[1] as usize);
                    if nx<m && ny<n && !spread[nx][ny] && (arr[nx][ny]==0 || arr[nx][ny]==1) {
                        arr[nx][ny]+=2;
                        q2.insert(0, nxt.clone());
                        spread_now.push(nxt);
                    }
                }
            }
        }
        while let Some(i) = cur_spread.pop() {
            spread[i[0] as usize][i[1] as usize]=true;
        }
    }
}

fn count(arr : &Vec<Vec<i8>>) -> Vec<u8> {
    let mut ret = vec![0,0,0];
    for i in arr {
        for j in i {
            match j {
                1 => ret[0]+=1,
                2 => ret[1]+=1,
                3 => ret[2]+=1,
                _ => {}
            }
        }
    }
    ret
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
    let (mut v1, mut v2) = (Pos::new(vec![0,0]), Pos::new(vec![0,0]));
    let (m, n) = (scan.token::<usize>(), scan.token::<usize>());
    let mut arr = vec![vec![0;n];m];
    for i in 0..m {
        for j in 0..n {
            arr[i][j] = scan.token::<i8>();
            if arr[i][j] == 1 {
                v1 = Pos::new(vec![i as i32,j as i32]);
            }
            else if arr[i][j] == 2 {
                v2 = Pos::new(vec![i as i32,j as i32]);
            }
        }
    }

    work(&mut arr, v1, v2);
    //writeln!(out, "{:?}", arr).unwrap();
    let ans = count(&arr);
    for i in ans {
        write!(out, "{} ", i).unwrap();
    }
}
