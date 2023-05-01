use std::io;
use std::collections::HashMap;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let mut m = HashMap::new();
    for i in s.trim().chars() {
        m.entry(i).and_modify(|counter| *counter+=1).or_insert(1);
    }
    for i in 'a'..='z' {
        print!("{} ", if let Some(num) = m.get(&i) {
            num
        } else {
            &0
        });
    }
}
