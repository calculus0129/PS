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

    // valid, but TLE... How can I solve like this?
    /*
    let mut a = scan.token::<String>();
    let b = scan.token::<String>();
    let mut cur_a = String::new();
    while a!=cur_a {
        cur_a = a.clone();
        a = a.split(b.as_str()).collect::<Vec<&str>>().join("");//explosion(&a, &b).as_mut_str();
    }
    writeln!(out, "{}", if a.as_str() == "" {"FRULA"} else {a.as_str()}).unwrap();
     */
    
    // 통과한 코드: https://www.acmicpc.net/source/57263634
    /*
    let s = scan.token::<String>();
    let explosion = scan.token::<String>();
    let mut ret = String::new();
    let (mut len_ret, len_explosion) = (0, explosion.len());

    for c in s.chars() {
        ret.push(c);
        len_ret = ret.len();
        if len_ret >= len_explosion {
            if ret[len_ret - len_explosion..].to_string() == explosion {
                ret.replace_range(len_ret - len_explosion.., "");
            }
        }
    } */

    /*  */
    // 이 코드가 더 빠름..!

    let s = scan.token::<String>();
    let explosion = scan.token::<String>();
    let mut ret = String::new();

    for c in s.chars() {
        ret.push(c);

        let len_ret = ret.len();
        let len_explosion = explosion.len();

        if len_ret >= len_explosion {
            let mut is_found = true;

            if ret[len_ret - len_explosion..].to_string() != explosion {
                is_found = false;
            }

            if is_found {
                ret.replace_range(len_ret - len_explosion.., "");
            }
        }
    }

    if ret.is_empty() {
        writeln!(out, "FRULA").unwrap();
    } else {
        writeln!(out, "{}", ret).unwrap();
    }
}
