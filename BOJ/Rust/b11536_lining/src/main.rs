use std::cmp::Ordering::*;

fn main() {
    let mut s = String::new();
    std::io::stdin()
        .read_line(&mut s)
        .unwrap();
    let n = s.trim().parse::<usize>().unwrap();
    let mut v = vec![String::new();n];
    for i in 0..n {
        std::io::stdin()
            .read_line(&mut v[i])
            .unwrap();
        v[i]=v[i].trim().to_string();
    }

    let m = if v[0]<v[1] {
        Less
    } else {Greater};
    let mut r = false;
    for i in 1..n-1 {
        if v[i].partial_cmp(&v[i+1]) != Some(m) {
            r = true;
            break;
        }
    }
    if r {
        print!("NEITHER");
    } else {
        print!("{}", if m == Less {"INCREASING"} else {"DECREASING"});
    }
}
