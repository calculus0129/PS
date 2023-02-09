use std::io;

fn main() {
    let mut s = String::new();
    let mut v = Vec::<i32>::new();
    for _i in 0..10 {
        v.push(0);
    }
    io::stdin().read_line(&mut s).unwrap();
    s.trim().chars().for_each(|x| {
        let mut y = x as u8 - b'0';
        if y == 9 {
            y = 6
        };
        v[y as usize] += 1;
    });
    v[6] = v[6] + 1 >> 1;
    println!("{}", v.iter().max().unwrap());
}
