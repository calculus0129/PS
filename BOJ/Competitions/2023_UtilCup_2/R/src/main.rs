use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let n = s.trim().parse::<usize>().unwrap();
    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let a: Vec<u16> = s
        .trim()
        .split(' ')
        .map(|i| i.parse::<u16>().unwrap())
        .collect();
    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let b: Vec<u16> = s
        .trim()
        .split(' ')
        .map(|i| i.parse::<u16>().unwrap())
        .collect();
    let mut ans = 0u16;
    for i in 0..n {
        if a[i] <= b[i] {
            ans += 1;
        }
    }
    print!("{ans}");
}
