use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().parse::<i32>().unwrap();
    for _i in 0..s>>2 {
        print!("long ");
    }
    print!("int");
}
