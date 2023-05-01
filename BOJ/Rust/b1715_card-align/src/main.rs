use std::{io, io::Write, str, collections::BinaryHeap, cmp::Reverse};

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

    let mut rpq = BinaryHeap::new(); // min-heap. min comes out first.
    let n = scan.token::<u32>();
    for _i in 0..n {
        rpq.push(Reverse(scan.token::<u64>()));
    }
    // Wow!
    //let Reverse(mut accum) = rpq.pop().unwrap();
    let mut nxt;
    let mut sum = 0;
    while let (Some(Reverse(f1)), Some(Reverse(f2))) = (rpq.pop(), rpq.pop()) {
        nxt = f1+f2;
        sum += nxt;
        rpq.push(Reverse(nxt));
    }
    write!(out, "{}", sum).unwrap();
}
