fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n = s.trim().parse::<i32>().unwrap();
    for i in 1..=n {
        for _ in 0..n - i {
            print!(" ")
        }
        for _ in 0..2 * i - 1 {
            print!("*")
        }
        println!("");
    }
}
