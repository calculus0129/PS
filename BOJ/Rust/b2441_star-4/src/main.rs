fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().parse::<u8>().unwrap();
    for i in 0..s {
        for _ in 0..i {
            print!(" ")
        }
        for _ in i..s {
            print!("*")
        }
        println!("");
    }
}
