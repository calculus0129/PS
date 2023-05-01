use std::io;
fn main() {
    let mut a = vec![0; 0];
    let mut r = false;
    for _ in 0..7 {
        let mut s = String::new();
        io::stdin().read_line(&mut s).unwrap();
        let b = s.trim().parse::<u8>().unwrap();
        if b % 2 == 1 {
            r = true;
            a.push(b);
        }
    }
    if !r {
        println!("-1");
    } else {
        let mut c = 0u16;
        a.sort();
        for i in 0..a.len() {
            c += a[i] as u16;
        }
        println!("{}\n{}", c, a[0]);
    }
}
