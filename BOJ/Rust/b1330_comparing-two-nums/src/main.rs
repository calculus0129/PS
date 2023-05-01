use std::io;

fn main() {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .unwrap();
    let s: Vec<i32> = s
        .trim()
        .split_ascii_whitespace()
        .map(|word| word.parse::<i32>().unwrap())
        .collect();
    print!("{}", match s[0].partial_cmp(&s[1]) {
        Some(std::cmp::Ordering::Equal) => {
            "=="
        }
        Some(std::cmp::Ordering::Less) => {
            "<"
        }
        Some(std::cmp::Ordering::Greater) => {
            ">"
        }
        None => {
            unimplemented!("WTF");
        }
    });
}
