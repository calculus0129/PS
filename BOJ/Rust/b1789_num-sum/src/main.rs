use std::io;
fn main() {
    let mut sum = 0u64;
    let mut n = 0u64;
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().parse::<u64>().unwrap();
    while sum<=s {
        n+=1;
        sum+=n;
    }
    n-=1;
    print!("{}", n);
}
