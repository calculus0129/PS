use std::io;

fn main() {
    let mut arr = vec![0u64, 1, ];
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().parse::<usize>().unwrap();
    let mut l=arr.len();
    while l<=s {
        arr.push(&arr[l-1]+&arr[l-2]);
        l+=1;
    }
    print!("{}", arr[s]);
}
