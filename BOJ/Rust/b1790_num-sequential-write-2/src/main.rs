fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: Vec<u64> = s
        .trim()
        .split_ascii_whitespace()
        .map(|word| word.parse::<u64>().unwrap())
        .collect();
    let (n, mut k) = (s[0], s[s.len()-1]);
    let mut i = 1;
    let mut idx = 1;
    while k > 9 * i * idx {
        k -= 9 * i * idx;
        i *= 10;
        idx += 1;
    }
    k -= 1;
    let (q, r) = (k / idx, k % idx);
    i += q;
    if i > n {
        print!("-1");
    } else {
        print!("{}", i.to_string().chars().nth(r as usize).unwrap());
    }
}
