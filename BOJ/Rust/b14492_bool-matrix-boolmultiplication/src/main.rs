use std::{io, io::Write, str, ops::{BitAnd, Index}};

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

struct BoolMatrix {
    data : Vec<Vec<u8>>,
    size : usize,
}

impl IntoIterator for BoolMatrix {
    fn into_iter(self) -> Self::IntoIter {
        self.data.into_iter()
    }
    type IntoIter = std::vec::IntoIter<Self::Item>;
    type Item = Vec<u8>;
}

impl Index<usize> for BoolMatrix {
    fn index(&self, index: usize) -> &Self::Output {
        &self.data[index]
    }
    type Output = Vec<u8>;
}

impl BoolMatrix {
    fn new(data : Vec<Vec<u8>>, size : usize) -> Self {
        Self{data, size}
    }
}

impl BitAnd for BoolMatrix {
    fn bitand(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size, rhs.size);
        let n = self.size;
        Self {
            data: (0..n).map(|i|
                (0..n).map(|j| {
                    let mut ret = 0;
                    (0..n).for_each(|k| ret|=self[i][k]&rhs[k][j]);
                    ret
                }
                ).collect::<Vec<u8>>()
            ).collect(),
            size: n,
        }
    }
    type Output = Self;
}

fn boolmul(a : BoolMatrix, b: BoolMatrix) -> u32 {
    assert_eq!(a.size, b.size);
    let mut ret = 0;
    for i in a&b {
        for j in i {
            ret += j as u32;
        }
    }
    ret
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n = scan.token::<usize>();
    let mut data = vec![vec![0;n];n];
    for i in 0..n {
        for j in 0..n {
            data[i][j] = scan.token::<u8>();
        }
    }
    let a = BoolMatrix::new(data.clone(), n);

    for i in 0..n {
        for j in 0..n {
            data[i][j] = scan.token::<u8>();
        }
    }
    let b = BoolMatrix::new(data, n);

    writeln!(out, "{}", boolmul(a, b)).unwrap();

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
}
