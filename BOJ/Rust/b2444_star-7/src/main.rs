fn main() {
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp).unwrap();
    let n = inp.trim().parse::<i32>().unwrap();
    for i in (0..n).rev() {
        for _ in 0..i {print!(" ")}
        for _ in 0..(n-i)*2-1 {print!("*")}
        println!("");
    }
    for i in 1..n {
        for _ in 0..i {print!(" ")}
        for _ in 0..(n-i)*2-1 {print!("*")}
        println!("");
    }
}
