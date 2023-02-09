use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();

    //let n = s.trim().parse::<i32>().unwrap();
    s.clear();

    io::stdin().read_line(&mut s).unwrap();

    let a: Vec<i32> = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    s.clear();
    
    io::stdin().read_line(&mut s).unwrap();
    let b=s.trim().parse::<i32>().unwrap();

    //print!("{:?}", a);
    let mut c=0;
    for i in 0..a.len() {
        if b==a[i]
        {
            c+=1;
        }
    }
    println!("{c}");

    //format!("{:?}", a); // format is just for string.
}
