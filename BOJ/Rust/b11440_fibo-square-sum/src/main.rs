use std::{io, ops::Mul};
const BIG: i128 = 1000000007;

#[derive(Debug, Clone)]
pub struct Squaremat {
    size: usize,
    content: Vec<Vec<i128>>,
}

impl Squaremat {
    fn new(n: usize, c: Vec<Vec<i128>>) -> Self {
        Self {
            size: n,
            content: c,
        }
    }
}

impl Mul for Squaremat {
    fn mul(self, rhs: Self) -> Self::Output {
        assert_eq!(self.size, rhs.size);
        let n = self.size;
        Self {
            size: n,
            content: (0..n).map(|i| {
                (0..n).map(|j| {
                    let mut ret = 0i128;
                    (0..n).for_each(|k| ret+=(self.content[i][k]*rhs.content[k][j])%BIG);
                    ret%BIG
                }).collect::<Vec<i128>>()
            }).collect(),
        }
    }
    type Output = Self;
}

// Using Telescoping Sum, \sigma_{k=0}^{n}f_{k}^2 == f_{n+1}*f_{n}
fn fibo_square_sum(mut n: usize) -> i128 {
    let (mut res, mut m) = (
        Squaremat::new(2, vec![vec![1,0], vec![0,1]]),
        Squaremat::new(2, vec![vec![0,1], vec![1,1]]),
    );
    while n>0 {
        if n&1==1 {
            res = res.clone() * m.clone();
        }
        m = m.clone() * m.clone();
        n>>=1;
    }
    // Resulting Matrix: vec![vec![f_{n-1}, f_{n}], vec![f_{n}, f_{n+1}]]
    (res.content[0][1] * res.content[1][1])%BIG
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s = s.trim().to_string();
    let n = s.parse::<usize>().unwrap();
    println!("{}", fibo_square_sum(n));
    //let v = s.as_mut_str().split_ascii_whitespace()
    //    .map(|word| word.parse::<usize>().unwrap()).collect::<Vec<usize>>();
}
