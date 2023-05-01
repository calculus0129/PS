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
    // this fastIO code is essential for rust users. Else, TLE occurs.
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    // https://github.com/utilForever/BOJ/blob/main/Rust/1929%20-%20Get%20Prime%20Numbers.rs
    // The Sieve of Eratosthenes works very faster than I thought!
    // time complexity: O(n)..! (just my thought...)
    // However, the space complexity is also O(n), which increases greater than prime judging.
    let (m, n) = (scan.token::<usize>(), scan.token::<usize>());

    // constructing the Sieve of Eratosthenes.
    let mut prime_num = vec![0;n+1];
    for i in 2..=n {
        prime_num[i] = i;
    }

    for i in 2..=(n as f64).sqrt() as usize {
        if prime_num[i]==0 {
            continue;
        }
        // why from i*i? hmm..
        // my guess is that this is because i*j where j<i is already deleted because
        // j is a multiple of other prime factors all less than i.
        for j in (i * i..=n).step_by(i) {
            prime_num[j] = 0;
        }
    }

    for i in m..=n {
        if prime_num[i] != 0 {
            writeln!(out, "{}", prime_num[i]).unwrap();
        }
    }
    // This algorithm has a O(n^3/2) time complexity.
    // This resulted in TLE.
    /*
    let mut primes = vec![2,];
    primes.reserve(200000);
    let mut i = 3;
    let mut r = true;
    while i<1000000 {
        r = true;//let mut r = true;
        for &j in &primes {
            if i%j == 0 {
                r = false;
                break;
            }
            // this code is essential for Rust users.
            else if j*j > i {
                break;
            }
        }
        if r {
            primes.push(i);
        }
        i+=2;
    }
    let (m, n) = (scan.token::<i32>(), scan.token::<i32>());
    //let mut s = String::new();
    //io::stdin().read_line(&mut s).unwrap();
    //let arr : Vec<i32> = s.trim().split_ascii_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    for i in m..=n {
        if primes.contains(&i) {
            writeln!(out, "{}", i).unwrap();
        }
    }
     */
}
