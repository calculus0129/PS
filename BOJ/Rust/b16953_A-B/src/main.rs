use std::{io, collections::VecDeque};

fn input_integers() -> Vec<i64> {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let values: Vec<i64> = s.as_mut_str().split_ascii_whitespace().map(|s| s.parse().unwrap()).collect();
    values
}

fn process_bfs(a: i64, b: i64) -> i64 {
    let mut queue = VecDeque::new();
    queue.push_back((a, 0));

    while let Some((cur, cnt)) = queue.pop_front() {
        if cur == b {
            return cnt+1;
        }

        if (cur<<1) <= b {
            queue.push_back((cur<<1, cnt+1));
        }
        if 1+cur*10 <= b {
            queue.push_back((1+cur*10, cnt+1));
        }
    }
    -1
}

fn main() {
    let nums = input_integers();
    let (a, b) = (nums[0], nums[1]);
    println!("{}", process_bfs(a, b));
}
