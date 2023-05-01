use std::{io, mem::swap};
fn main() {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .unwrap();
    let s : Vec<i32> = s.trim().split_ascii_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let (mut a, mut b, mut c) = (s[0], s[1], s[2]);
    if a>b {swap(&mut a, &mut b)}
    if b>c {swap(&mut b, &mut c)}
    if a>b {swap(&mut a, &mut b)}
    println!("{} {} {}", a, b, c);
}
