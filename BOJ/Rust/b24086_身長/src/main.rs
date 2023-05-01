use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let a = s.trim().parse::<i32>().unwrap();
    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let b = s.trim().parse::<i32>().unwrap();
    println!("{}", b-a);
}
