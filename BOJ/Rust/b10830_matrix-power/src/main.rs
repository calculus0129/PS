use std::{io, io::Write, ops::Mul, str};

#[derive(Clone)]
pub struct Matrix {
    size: usize,
    content: Vec<Vec<i32>>,
}

impl Matrix {
    pub fn new(n: usize, c: Vec<Vec<i32>>) -> Self {
        Self {
            size: n,
            content: c,
        }
    }
}

impl Mul for Matrix {
    fn mul(self, rhs: Self) -> Self::Output {
        let mut ret = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                //let mut a=0;
                for k in 0..self.size {
                    ret[i][j] += self.content[i][k] * rhs.content[k][j];
                }
                ret[i][j] %= 1000;
            }
        }

        Self {
            size: self.size,
            content: ret,
        }
    }

    type Output = Self;
}

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

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();

    let (n, mut b) = (scan.token::<usize>(), scan.token::<u64>());
    let mut m = Matrix::new(
        n,
        (0..n)
            .map(|_i| (0..n).map(|_j| scan.token::<i32>()).collect::<Vec<i32>>())
            .collect::<Vec<Vec<i32>>>(),
    );
    let mut res = Matrix::new(
        n,
        (0..n)
            .map(|i| {
                (0..n)
                    .map(|j| if i == j { 1 } else { 0 })
                    .collect::<Vec<i32>>()
            })
            .collect::<Vec<Vec<i32>>>(),
    );
    while b != 0 {
        if b & 1 == 1 {
            res = res.clone() * m.clone();
        }
        m = m.clone() * m.clone();
        b >>= 1;
    }
    (0..n).for_each(|i| {
        (0..n).for_each(|j| write!(out, "{} ", res.content[i][j]).unwrap());
        write!(out, "\n").unwrap();
    });
}
