fn main() {
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp).unwrap();
    let n = inp.trim().parse::<i32>().unwrap();
    for i in 1..=n {
        for _ in 0..i {print!("*")}
        for _ in 0..2*n-2*i {print!(" ")}
        for _ in 0..i {print!("*")}
        println!("");
    }
    for i in (1..n).rev() {
        for _ in 0..i {print!("*")}
        for _ in 0..2*n-2*i {print!(" ")}
        for _ in 0..i {print!("*")}
        println!("");
    }

}
