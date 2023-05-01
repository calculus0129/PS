use std::{io, io::Write};

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut out = io::BufWriter::new(stdout.lock());
    let mut s = String::new();
    let (mut name, mut a, mut b, mut r);
    stdin.read_line(&mut s).unwrap();
    while s.trim() != "# 0 0" {
        let v = s.trim().split_ascii_whitespace().collect::<Vec<&str>>();
        (name, a, b) = (v[0], v[1].parse::<i32>().unwrap(), v[2].parse::<i32>().unwrap(), );
        
        r = a>17 || b>=80;

        writeln!(out, "{} {}", name, if r {"Senior"} else {"Junior"}).unwrap();
        s = String::new();
        stdin.read_line(&mut s).unwrap();
    }
}
