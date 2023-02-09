use std::io;
fn main() {
    // 근데 이거 안되겠다. 왜냐하면 10^1000이거든. 이건 음... 특별한 방법을 써야 할 것 같은데...
    let mut s = String::new();
    io::stdin()
    .read_line(&mut s)
    .unwrap();
    let v = s.trim()
    .split_ascii_whitespace()
    .map(|x| x.parse::<i32>().unwrap())
    .collect::<Vec<i32>>();
    println!("{}", v[0]/v[1]);
    println!("{}", v[0]%v[1]);
}
