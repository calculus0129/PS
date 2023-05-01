use std::{io, io::Write, str, collections::HashMap, mem::swap};

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

    let mut arr = Vec::new();
    let n = scan.token::<usize>();
    for _ in 0..n {
        arr.push(scan.token::<String>());
    }
    let mut s = scan.token::<usize>();

    let mut sorted = arr.clone();
    sorted.sort_by(|a, b| {
        let l = std::cmp::min(a.len(), b.len());
        let (mut a_chars, mut b_chars) = (a.chars(), b.chars());
        for i in 0..l {
            if a_chars.nth(i)!=b_chars.nth(i) { // this code requires a_chars and b_chars to be mutable!
                return a_chars.nth(i).cmp(&b_chars.nth(i)).reverse();
            }
        }
        a.len().cmp(&b.len()).reverse()
    });
    let mut now: HashMap<String, usize> = (0..n).map(|i| (arr[i].clone(), i)).collect();
    let mut l=0;
    for i in (0..n) {
        l = now[&sorted[i]]-i;
        if s<l {
            l = i;
            break;
        }
        s-=l;
        let (a, b, l) = (arr[i].clone(), sorted[i].clone(), now[&sorted[i]]);
        now.insert(b.clone(), i);
        now.insert(a.clone(), l);
        arr[i] = b;
        arr[l] = a;
    }

    while s>0 {
        todo!();
    }
    /*
    let (a, b, c) = (
        scan.token::<i32>(),
        scan.token::<i32>(),
        scan.token::<i32>(),
    );
    writeln!(out, "{}", a + b + c).unwrap(); */
}
