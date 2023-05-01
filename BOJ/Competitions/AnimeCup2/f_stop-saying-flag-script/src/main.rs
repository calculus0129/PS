use std::{cmp::min, io, io::Write, str};

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
    let (n, k) = (scan.token::<usize>(), scan.token::<usize>());
    let (mut p, mut t) = (vec![0; n], vec![0; n]);
    let mut a;
    for i in 0..n {
        a = scan.token::<u128>();
        p[i] = a;
    }
    for i in 0..n {
        a = scan.token::<u128>();
        t[i] = a;
    }
    let mut ans = 0;
    for i in 0..n {
        if p[i] < t[i] {
            a = (t[i] - p[i]) / k as u128 + if (t[i] - p[i]) % k as u128 != 0 { 1 } else { 0 };
            ans += a;
            for j in 1..min(n - i, k) {
                p[i + j] += a*(k - j) as u128;
            }
        }
    }
    writeln!(out, "{}", ans).unwrap();
    // timeout...
}
