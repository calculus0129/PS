use std::io;

fn main() {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .unwrap();
    s = s.trim().chars().map(|c| match c.is_ascii_uppercase() {
        true=>c.to_ascii_lowercase(),
        false=>c.to_ascii_uppercase(),
    }).collect::<String>(); //.join("");
    print!("{}", s);
}