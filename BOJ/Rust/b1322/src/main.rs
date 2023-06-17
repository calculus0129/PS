use std::io;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v : Vec<i64> = s.as_mut_str()
        .trim()
        .split_ascii_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();
    let mut num_0: Vec<i32> = vec![];
    for i in 0..63 {
        if v[0] & (1<<i) == 0 {
            num_0.push(i);
        }
    }
    let mut b=0i64;
    let mut k = v[1];
    for &i in num_0.iter() {
        b |= (k & 1) << i;
        k >>= 1;
    }
    println!("{b}");
}
