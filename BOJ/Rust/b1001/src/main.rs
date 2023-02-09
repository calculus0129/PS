use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let arr: Vec<i64> = s
        .as_mut_str()
        .split_ascii_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<i64>>();

    
    let out = format!("{}", arr[0]-arr[1]);
    println!("{}",out);
}
