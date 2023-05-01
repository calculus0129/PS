use std::{io, io::Write, str, ops::{Add, Mul, Neg, Sub}};
const BIG : u32 = 1000;

#[derive(Clone)]
struct Matrix {
    size : usize,
    data : Vec<Vec<u32>>,
}

impl Matrix {
    fn new(size : usize, data : Vec<Vec<u32>>) -> Self {
        Self {size, data}
    }
}

fn pow(mut a : Matrix, mut exponent : u64) -> Matrix {
    let n = a.size;
    let mut ret = Matrix::new(
        n,
        (0..n).map(|i| (0..n).map(|j| {if i==j {1} else {0}}).collect::<Vec<u32>>()).collect(),
    );
    while exponent!=0 {
        if exponent&1 != 0 {
            ret = ret*a.clone();
        }
        a = a.clone()*a.clone();
        exponent>>=1;
    }
    ret
}

impl Add for Matrix {
    fn add(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size, rhs.size);
        Self {
            size: self.size,
            data: (0..self.size).map(|r| (0..self.size).map(|c| {
                (self.data[r][c] + rhs.data[r][c]) % BIG
            }).collect::<Vec<u32>>()).collect()
        }
    }
    type Output = Self;
}

impl Sub for Matrix {
    fn sub(self, rhs: Self) -> Self::Output {
        self+(-rhs)
    }
    type Output = Self;
}

impl Neg for Matrix {
    fn neg(self) -> Self::Output {
        Self {
            size: self.size,
            data: (0..self.size).map(|r| (0..self.size).map(|c| {
                BIG-self.data[r][c]
            }).collect::<Vec<u32>>()).collect()
        }
    }
    type Output = Self;
}

impl Mul for Matrix {
    fn mul(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size, rhs.size);
        Self {
            size: self.size,
            data: (0..self.size).map(|r| (0..self.size).map(|c| {
                let mut x = 0;
                (0..self.size).for_each(|k| x+=(self.data[r][k]*rhs.data[k][c])%BIG);
                x%BIG
            }).collect::<Vec<u32>>()).collect()
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
    let iden : Matrix = Matrix::new(
        n,
        (0..n).map(|i| (0..n).map(|j| {if i==j {1} else {0}}).collect::<Vec<u32>>()).collect(),
    );
    let zero : Matrix = Matrix::new(
        n,
        (0..n).map(|_i| (0..n).map(|_j| {
            0
        }).collect::<Vec<u32>>()).collect()
    );

    let mut a: Vec<Vec<u32>> = (0..n).map(|_| vec![0;n]).collect();
    (0..n).for_each(|i| (0..n).for_each(|j| a[i][j]=scan.token::<u32>()));

    let mut a = Matrix::new(n, a);
    let mut a_1 = iden.clone();
    let mut res = zero.clone();
    let a_original = a.clone();
    
    while b!=0 {
        if b&1 != 0 {
            res = res.clone()+pow(a.clone(), b-1)*a_1.clone();
        }
        a_1 = a_1.clone() * (iden.clone() + a.clone());
        a = a.clone()*a.clone();
        b>>=1;
    }
    res = res.clone()*a_original;
    (0..n).for_each(|i| {
        (0..n).for_each(|j| write!(out, "{} ", res.data[i][j]).unwrap());
        write!(out, "\n").unwrap();
    });
}
