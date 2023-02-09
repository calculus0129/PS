use std::{io, str, io::Write};
use std::cmp::{min, Ordering::{Equal, Greater, Less}};
use std::collections::HashMap;

pub struct UnsafeScanner<R> {
    reader : R,
    buf_str:Vec<u8>,
    buf_iter:str::SplitAsciiWhitespace<'static>,
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
    let n = scan.token::<i32>();
    let mut v = HashMap::<String, u32>::new();
    for _ in 0..n
    {
        let m = scan.token::<String>().split('.').nth(1).unwrap().to_string();
        v.entry(m).and_modify(|counter| *counter += 1).or_insert(1);
    }
    let mut k = v.keys().map(|x| x.clone()).collect::<Vec<String>>();
    k.sort_by(|a, b| {
        match a==b {
            true => {Equal}
            false => {
                let m = min(a.len(), b.len());
                for i in 0..m {
                    match a.chars().nth(i).unwrap().cmp(&b.chars().nth(i).unwrap()) {
                        Greater => {return Greater;}
                        Less => {return Less;}
                        _ => {continue;}
                    }
                }
                a.len().cmp(&b.len())
            }
        }
    });
    for i in k {
        writeln!(out, "{} {}", i, v[&i]);
    }

}
