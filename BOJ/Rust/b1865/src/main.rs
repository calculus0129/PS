use std::io;
use std::str;
use std::io::Write;

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
    
    let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    
    writeln!(out, "{}", a+b).unwrap();

    let mut nums : [i32;3] = [1,2,3];
    let mut inp = String::new();
    io::stdin()
    .read_line(&mut inp)
    .unwrap();
    let mut t = inp.trim().parse::<i32>().unwrap();
    while t!=0
    {
        io::stdin()
        .read_line(&mut inp)
        .unwrap();

        let nums = inp.trim()
        .split_ascii_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
        let n=nums[0];
        let m=nums[1];
        let w=nums[2];

        //unfinished



        t-=1;
    }
}
