use std::{
    cmp::Ordering::{Equal, Greater, Less},
    io,
    io::Write,
    str,
};

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
    let n = scan.token::<usize>();
    let mut a: Vec<u32> = (0..n).map(|_| scan.token::<u32>()).collect();
    let mut b: Vec<u32> = (0..n).map(|_| scan.token::<u32>()).collect();
    a.sort();
    b.sort_by(|a, b| match a.partial_cmp(&b) {
        Some(x) => match x {
            Equal => Equal,
            Greater => Less,
            Less => Greater,
        },
        None => unimplemented!(),
    });

    writeln!(out, "{}", {
        let mut o = 0;
        (0..n).map(|i| a[i] * b[i]).for_each(|i| o += i);
        o
    })
    .unwrap();
}
