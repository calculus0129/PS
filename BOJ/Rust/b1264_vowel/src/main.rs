use std::{io, io::Write};
/*
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
} */

fn main() {
    let stdout = io::stdout();
    //let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut s = String::new();
    let mut n;
    io::stdin().read_line(&mut s).unwrap();
    while s != "#" {
        n=0;
        for i in s.trim().chars() {
            match i {
                'a'|'e'|'i'|'o'|'u'|'A'|'E'|'I'|'O'|'U' => {
                    n+=1;
                }
                _ => {}
            }
        }
        writeln!(out, "{}", n).unwrap();
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        s = s.trim().to_string();
    }

    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
}
