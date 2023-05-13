use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let mut a = s.trim()
    .split_ascii_whitespace()
    .map(|word| word.parse::<i32>().unwrap())
    .collect::<Vec<i32>>();
    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let t = s.trim().parse::<i32>().unwrap();
    a[2] += t;
    a[1] += a[2]/60;
    a[2] %= 60;
    a[0] = (a[1]/60+a[0])%24;
    a[1] %= 60;
    println!("{} {} {}", a[0], a[1], a[2]);

}
