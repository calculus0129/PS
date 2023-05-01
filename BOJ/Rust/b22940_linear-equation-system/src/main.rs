use std::{io, io::Write, str};

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

/// evaluate the gcd via Euclidean Algorithm. let a<=b!
fn gcd_ab(a: i64, b: i64) -> i64 {
    if a==0 {
        b
    } else {
        gcd_ab(b%a, a)
    }
}

/// evaluate the gcd.
fn gcd(mut a: i64, mut b: i64) -> i64 {
    if a<0 {a = -a};
    if b<0 {b = -b};
    if a<b {
        gcd_ab(b, a)
    }
    else {
        gcd_ab(a, b)
    }
}

/*fn lcm(a: i64, b: i64) -> i64 {
    a*b/gcd(a, b)
}*/

fn gcd_vec(a : &Vec<i64>) -> i64 {
    if a.len()==1 {
        a[0]
    } else {
        let mut m = gcd(a[0], a[1]);
        for &i in &a.as_slice()[2..a.len()] {
            m = gcd(m, i);
        }
        m
    }
}

#[derive(Clone, Debug)]
struct Matrix {
    m : usize,
    n : usize,
    data : Vec<Vec<i64>>,
}

trait RowOperations {
    /// RowOperation1: Exchanging two rows.
    fn row_operation1(&mut self, i: usize, j: usize);
    /// RowOperation2: Multiplying a row k times.
    fn row_operation2(&mut self, i: usize, mul: i64);
    /// RowOperation2_2: Dividing a row with d.
    fn row_operation2_2(&mut self, i: usize, d: i64);
    /// RowOperation2_3: Canceling gcd of a row.
    fn row_operation2_3(&mut self, i: usize);
    /// RowOperation3: For two rows A and B, replacing B with aA+bB.
    fn row_operation3(&mut self, from: usize, to: usize, multipliers : (i64, i64));
}

impl Matrix {
    fn new(data : Vec<Vec<i64>>) -> Self {
        Self{m: data.len(), n: data[0].len(), data}
    }

    fn transpose(&self) -> Self {
        Self {
            m: self.n,
            n: self.m,
            data: (0..self.n).map(|i| (0..self.m).map(|j| self.data[j][i]).collect::<Vec<i64>>()).collect(),
        }
    }

    /*fn concat_r(&self, rhs : &Self) -> Self {
        assert_eq!(self.m, rhs.m);
        Self {
            m: self.m,
            n: self.n+rhs.n,
            data: {
                let mut ret = Vec::new();
                for i in 0..self.m {
                    ret.push([self.data[i].clone(), rhs.data[i].clone()].concat());
                }
                ret
            },
        }
    }

    fn concat_c(&self, rhs : &Self) -> Self {
        self.transpose().concat_r(&rhs.transpose()).transpose()
    }*/
}

impl RowOperations for Matrix {
    fn row_operation1(&mut self, i: usize, j: usize) {
        let row_i = self.data[i].clone();
        self.data[i] = self.data[j].clone();
        self.data[j] = row_i;
    }

    fn row_operation2(&mut self, i: usize, mul : i64) {
        for c in 0..self.n {
            self.data[i][c]*=mul;
        }
        //self.data[i] = (0..self.n).map(|c| mul*self.data[i][c]).collect();
    }

    fn row_operation2_2(&mut self, i: usize, d: i64) {
        for c in 0..self.n {
            self.data[i][c]/=d;
        }
    }

    fn row_operation2_3(&mut self, i: usize) {
        let d = gcd_vec(&self.data[i]);
        //if d==0 {d=1};
        for c in 0..self.n {
            self.data[i][c]/=d;
        }
    }

    fn row_operation3(&mut self, from_idx: usize, to_idx: usize, multipliers : (i64, i64)) {
        self.data[to_idx] = (0..self.n).map(|c| multipliers.0*self.data[from_idx][c] + multipliers.1*self.data[to_idx][c]).collect();
    }
}

fn fowrard_elim(ab : &mut Matrix) {
    let m = ab.m;
    for r in 0..m {
        ab.row_operation2_3(r);
        for i in r+1..m {
            if ab.data[i][r] == 0 {
                continue;
            }
            let (a, b) = (ab.data[r][r], ab.data[i][r]);
            let g = if b<a {gcd(b, a)} else {gcd(a, b)};
            let mul = (-b/g, a/g);
            ab.row_operation3(r, i, mul);
        }
    }
}

fn backward_substitution(ab : &mut Matrix) {
    let m = ab.m;
    for r in (0..m).rev() {
        ab.row_operation2_2(r, ab.data[r][r]);
        for i in 0..r {
            ab.row_operation3(r, i, (-ab.data[i][r], 1));
        }
    }
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n = scan.token::<usize>();
    let mut ab = Matrix::new({
        let mut data = (0..n).map(|_i| {
            (0..=n).map(|_j| {
                scan.token::<i64>()
            }).collect::<Vec<i64>>()
        }).collect::<Vec<Vec<i64>>>();
        data.sort_by(|a, b| {
            let (mut m, mut n) = (0, 0);
            for i in a {
                if i==&0 {
                    m+=1;
                } else {
                    break;
                }
            }
            for i in b {
                if i==&0 {
                    n+=1;
                } else {
                    break;
                }
            }
            m.cmp(&n)
        });
        data
    });
    //writeln!(out, "{:?}", ab.data).unwrap();

    fowrard_elim(&mut ab);

    //writeln!(out, "{:?}", ab.data).unwrap();

    backward_substitution(&mut ab);

    //writeln!(out, "{:?}", ab.data).unwrap();

    for &i in &ab.transpose().data[n] {
        write!(out, "{i} ").unwrap();
    }

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
}
