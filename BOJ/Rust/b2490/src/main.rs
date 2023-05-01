use std::io;
fn main() {
    for _ in 0..3 {
        let mut s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let mut a = 0;
        s.trim()
            .split_ascii_whitespace()
            .for_each(|x| a += x.parse::<i32>().unwrap());
        println!(
            "{}",
            match a {
                0 => "D",
                1 => "C",
                2 => "B",
                3 => "A",
                4 => "E",
                _ => panic!(),
            }
        );
    }
}
