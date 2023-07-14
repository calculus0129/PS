use std::io;

fn main() {
    let (mut s1, mut s2) = (String::new(), String::new());
    io::stdin().read_line(&mut s1).unwrap();
    io::stdin().read_line(&mut s2).unwrap();
    let s1 = s1
        .trim_end()
        .to_string()
        .as_mut_str()
        .split_ascii_whitespace()
        .map(|word| word.parse::<i16>().unwrap())
        .fold(0, |acc, x| acc + x);
    let s2 = s2
        .trim_end()
        .to_string()
        .as_mut_str()
        .split_ascii_whitespace()
        .map(|word| word.parse::<i16>().unwrap())
        .fold(0, |acc, x| acc + x);
    println!("{}", if s1 < s2 { s2 } else { s1 });
}
