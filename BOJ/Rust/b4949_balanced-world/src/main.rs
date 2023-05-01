use std::io;
fn main() {
    let mut s = String::new();
    let mut stk = Vec::new();
    io::stdin().read_line(&mut s).unwrap();
    while s.trim_end()!="." {
        let mut r = true;
        for i in s.trim_end().trim_end_matches('.').chars() {
            match i {
                '(' => stk.push(1),
                '[' => stk.push(2),
                ')' | ']' => {
                    if stk.is_empty() {
                        r=false;
                        break;
                    }
                    match i {
                        ')' => {
                            if stk.pop().unwrap() != 1 {
                                r = false;
                                break;
                            }
                        }
                        ']' => {
                            if stk.pop().unwrap() != 2 {
                                r = false;
                                break;
                            }
                        }
                        _ => panic!(),
                    }
                }
                _ => {}
            }
        }
        if r && !stk.is_empty() {r=false}
        if r {
            println!("yes");
        }
        else {
            println!("no");
            stk = Vec::new();
        }
        s = String::new();
        io::stdin().read_line(&mut s).unwrap();
    }
    
}