use hex;
fn main() {
    let s = String::from("강한친구 대한육군");
    let string_list = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| hex::encode(s).to_uppercase().unwrap())
        .collect();
    println!("{} {}", string_list[0], string_list[1]);
    // 안된다..
}
