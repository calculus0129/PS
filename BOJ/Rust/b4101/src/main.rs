use std::io;

fn two_outs() -> (i32, i32)
{
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let v = s
        .trim()
        .split_ascii_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    let a=v[0];
    let b=v[1];
    (a, b)
}

fn main() {
    loop {
        let (first, second) = two_outs();
        if first == 0 && second == 0
        {
            break;
        }
        println!("{}", if first>second {"Yes"} else {"No"});
    }
}
