use std::{io, io::Write, ops::Mul, str};
const BIG: u64 = 1000000000;

#[derive(Clone)]
pub struct Mat {
    size: usize,
    content: Vec<Vec<u64>>,
}

impl Mat {
    fn new(n: usize, c: Vec<Vec<u64>>) -> Self {
        Self {
            size: n,
            content: c,
        }
    }
}

impl Mul for Mat {
    fn mul(self, rhs: Self) -> Self::Output {
        let c: Vec<Vec<u64>> = (0..self.size)
            .map(|i| {
                (0..self.size)
                    .map(|j| {
                        let mut a = 0u64;
                        (0..self.size).for_each(|k| {
                            a += (self.content[i][k] * rhs.content[k][j]) % BIG;
                        });
                        a % BIG
                    })
                    .collect::<Vec<u64>>()
            })
            .collect();
        Self {
            size: self.size,
            content: c,
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

fn fibo(mut n: u64) -> u64 {
    let (mut res, mut m) = (
        Mat::new(2, vec![vec![1, 0], vec![0, 1]]),
        Mat::new(2, vec![vec![1, 1], vec![1, 0]]),
    );
    while n != 0 {
        if n & 1 != 0 {
            res = res.clone() * m.clone();
        }
        m = m.clone() * m.clone();
        n >>= 1;
    }
    res.content[1][0]
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    //let n = 8u64;
    //assert_eq!(fibo(n), 21u64, "Failed at function fibo");
    //assert_eq!(n, 8u64, "Failed to maintain n");
    let (a, b) = (scan.token::<u64>(), scan.token::<u64>());
    write!(
        out,
        "{}",
        (fibo(b - a + 1) * fibo(a) % BIG + (fibo(b - a + 2) + BIG - 1) * fibo(a + 1) % BIG) % BIG
    )
    .unwrap(); // +BIG 이유: 안하면 -1에서 overflow error터질 수 있음! e.g. 1 8999999999999999999 입력.
}
