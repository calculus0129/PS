use std::io;
fn main() {
    let mut in1 = String::new();
    io::stdin()
    .read_line(&mut in1)
    .unwrap();
    in1 = (&in1).trim().to_string();

    let mut in2 = String::new();
    io::stdin()
    .read_line(&mut in2)
    .unwrap();
    in2 = (&in2).trim().to_string();

    if in2.ends_with((&in1).to_string())
    {
        println!("go");
    }
    else
    {
        println!("no");
    }

}
