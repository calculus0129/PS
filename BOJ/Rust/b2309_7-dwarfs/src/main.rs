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

    let mut a = vec![
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
    ];
    let mut c = 0;
    // => 소유권 안 뺏김!
    // => if문에서 에러 안 남!
    for &i in &a {
        c+=i;
    }
    c-=100;
    let mut r=false;
    for b1 in 0..9 {
        for b2 in b1+1..9 {
            if a[b1]+a[b2] == c {
                a[b1]=101;
                a[b2]=101;
                r=true;
                break;
            }
        }
        if r {
            break;
        }
    }
    a.sort();

    for i in 0..7 {
        writeln!(out, "{}", a[i]).unwrap()
    }
}
