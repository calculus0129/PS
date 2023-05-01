use std::io;
fn main() {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s).unwrap();
    let mut s = s.trim().split_ascii_whitespace().map(|x| x.parse::<u64>().unwrap()).collect::<Vec<u64>>();
    s.sort();
    let (a, b) = (s[0], s[1]);
    println!("{}", (b-a).saturating_sub(1));
    for i in a+1..b {
        print!("{} ", i);
    }
}
