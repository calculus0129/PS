use std::{io, io::Write, str, ops::Mul};

struct Matrix {
    size1 : usize,
    size2 : usize,
    data : Vec<Vec<i32>>,
}

impl Matrix {
    fn new(size1 : usize, size2 : usize, data : Vec<Vec<i32>>) -> Self {
        Self {size1, size2, data}
    }
}

impl Mul for Matrix {
    fn mul(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size2, rhs.size1);
        Self {
            size1 : self.size1,
            size2 : rhs.size2,
            data : (0..self.size1).map(|r| {
                (0..rhs.size2).map(|c| {
                    let mut x = 0;
                    (0..self.size2).for_each(|k| x+=self.data[r][k]*rhs.data[k][c]);
                    x
                }).collect::<Vec<i32>>()
            }).collect(),
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

    let (a, b,) = (
        scan.token::<usize>(),
        scan.token::<usize>(),
    );
    let mat_a = Matrix::new(a, b, (0..a).map(|_i| (0..b).map(|_j| {
        scan.token::<i32>()
    }).collect::<Vec<i32>>()).collect());

    let (a, b,) = (
        scan.token::<usize>(),
        scan.token::<usize>(),
    );
    let mat_b = Matrix::new(a, b, (0..a).map(|_i| (0..b).map(|_j| {
        scan.token::<i32>()
    }).collect::<Vec<i32>>()).collect());
    
    for i in (mat_a*mat_b).data {
        for j in i {
            write!(out, "{} ", j).unwrap();
        }
        writeln!(out, "").unwrap();
    }
}
