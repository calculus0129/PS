use std::{io, io::Write, ops::Mul, str};
const BIG: u64 = 1000000000;

#[derive(Debug, Clone)]
pub struct Mat {
    size: (usize, usize),
    data: Vec<Vec<u64>>,
}

impl Mat {
    fn new(n: usize, c: Vec<Vec<u64>>) -> Self {
        Self {
            size: (n, n),
            data: c,
        }
    }
}

impl Mul for Mat {
    fn mul(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size.1, rhs.size.0);
        let n = self.size.1;
        Self {
            size: (self.size.0, rhs.size.1),
            data: (0..self.size.0)
                .map(|i| {
                    (0..rhs.size.1)
                        .map(|j| {
                            let mut ret = 0u64;
                            for k in 0..n {
                                ret += (self.data[i][k] * rhs.data[k][j]) % BIG;
                            }
                            ret % BIG
                        })
                        .collect::<Vec<u64>>()
                })
                .collect(),
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

fn fibo(a: usize) -> u64 {
    let mut a = a;
    let (mut res, mut m) = (
        Mat::new(2, vec![vec![1, 0], vec![0, 1]]),
        Mat::new(2, vec![vec![0, 1], vec![1, 1]]),
    );
    /*
    let (mut res, mut m) = (
        Mat {
            size: (2, 2),
            data: vec![vec![1, 0], vec![0, 1]],
        },
        Mat {
            size: (2, 2),
            data: vec![vec![0, 1], vec![1, 1]],
        },
    ); */
    while a != 0 {
        if a & 1 == 1 {
            res = res.clone() * m.clone();
        }
        m = m.clone() * m.clone();
        a >>= 1;
    }
    res.data[0][1]
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());
    let (a, b) = (scan.token::<usize>(), scan.token::<usize>());
    writeln!(out, "{}", (fibo(b + 2) + (BIG - fibo(a + 1))) % BIG).unwrap();
    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
}
