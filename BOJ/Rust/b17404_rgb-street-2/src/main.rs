use std::{io, io::Write, str, cmp::min};

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
    let mut arr = vec![vec![0;3];n];
    for i in 0..n {
        for j in 0..3 {
            arr[i][j] = scan.token::<u32>();
        }
    }
    const BIG : u32 = 1000000;
    let mut ans = BIG;
    
    for i in 0..3 {
        let mut dp = vec![vec![BIG;3];n];
        dp[0][i]=arr[0][i];
        for j in 1..n {
            dp[j][0] = min(min(dp[j-1][1], dp[j-1][2])+arr[j][0], BIG);
            dp[j][1] = min(min(dp[j-1][2], dp[j-1][0])+arr[j][1], BIG);
            dp[j][2] = min(min(dp[j-1][0], dp[j-1][1])+arr[j][2], BIG);
        }
        dp[n-1][i]=BIG;
        ans = min(ans, min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));
    }
    writeln!(out, "{}", ans).unwrap();
}
