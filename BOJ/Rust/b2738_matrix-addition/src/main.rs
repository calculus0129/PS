use std::{io, io::Write, str, ops::Add};

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
struct Matrix {
    data : Vec<Vec<i32>>,
}

impl Matrix {
    fn new(data : Vec<Vec<i32>>) -> Self {
        Self{data}
    }
}

impl Add for Matrix {
    fn add(self, rhs: Self) -> Self::Output {
        let (m, n) = (rhs.data.len(), rhs.data[0].len());
        assert_eq!(self.data.len(), m);
        assert_eq!(self.data[0].len(), n);
        Self {
            data : (0..m).map(|i| (0..n).map(|j| self.data[i][j]+rhs.data[i][j]).collect::<Vec<i32>>()).collect(),
        }
    }
    type Output = Self;
}


fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let (m, n) = (scan.token::<usize>(), scan.token::<usize>());
    let mat = (0..2).map(|_| {
        let mut data = vec![vec![0;n];m];
        (0..m).for_each(|i| (0..n).for_each(|j| {
            data[i][j] = scan.token::<i32>();
        }));
        Matrix::new(data)
    }).collect::<Vec<Matrix>>();
    for i in (mat[0].clone()+mat[1].clone()).data {
        for j in i {
            write!(out, "{} ", j).unwrap();
        }
        writeln!(out, "").unwrap();
    }
}

/*
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

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();

    let (a, b, c) = (
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
    );
    writeln!(out, "{}", a + b + c).unwrap();
}
 */