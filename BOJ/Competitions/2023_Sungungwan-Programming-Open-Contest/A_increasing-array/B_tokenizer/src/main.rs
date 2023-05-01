use std::{io, io::Write, str};
// TLE......

/*pub struct UnsafeScanner<R> {
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
}*/

fn main() {
    let stdout = io::stdout(); //(stdin, stdout) = (io::stdin(), io::stdout());
                               //let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    s = s.trim().replace("&&", "&").replace("||", "|");

    let p = &['<', '>', '&', '|', '(', ')', ' '][..];
    let x: Vec<&str> = s.split(p).collect();
    let mut y: Vec<&str> = s.matches(p).collect();
    let n = x.len();
    y.push("");
    write!(
        out,
        "{}",
        (0..n)
            .fold(Vec::<&str>::new(), |acc, idx| [
                &acc[..],
                &vec![x[idx], y[idx]]
            ]
            .concat())
            .iter()
            .filter(|x| **x != " " && **x != "")
            .map(|x| *x)
            .collect::<Vec<&str>>()
            .join(" ")
            .replace("&", "&&")
            .replace("|", "||")
    )
    .unwrap();
    //let (a, b) = (scan.token::<i64>(), scan.token::<i64>());
    //writeln!(out, "{}", a+b).unwrap();
}
