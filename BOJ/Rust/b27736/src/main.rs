use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n = n.trim().parse::<usize>().unwrap();

    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().split_ascii_whitespace();
    let b = s.clone().filter(|x| *x == "0").count();
    let r = b * 2 >= n;
    let s = s.fold(0, |acc, x| acc + x.parse::<i16>().unwrap());
    println!(
        "{}",
        if r {
            "INVALID"
        } else {
            match Some(s) {
                Some(x) if x <= 0 => "REJECTED",
                _ => "APPROVED",
            }
        }
    );
}
