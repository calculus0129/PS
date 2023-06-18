use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s = s.as_mut_str().trim().to_string();
    println!("{s}??!");
}
