use std::io;
// https://help.acmicpc.net/language/info
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    let values: Vec<i32> = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    
    println!("{}", values[0]+values[1]);

    /*let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let a = s.trim().parse::<i64>().unwrap();

    let mut s2: String = String::new();
    io::stdin().read_line(&mut s2).unwrap();
    let b = s2.trim().parse::<i64>().unwrap();

    let c = a+b;

    println!("{}", c);
    */

}
