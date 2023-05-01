use std::io;

#[derive(Clone, PartialEq, Debug)]
struct Dungchi {
    height : u32,
    weight : u32,
}

impl PartialOrd for Dungchi {
    fn lt(&self, other: &Self) -> bool {
        self.height < other.height && self.weight < other.weight
    }

    // it was said that it is necessary to implement this, though it won't be necessary for our code.
    // That's because we only need lt in order to see if a person has less Dungchi than another.
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        match self.height.partial_cmp(&other.height) {
            Some(core::cmp::Ordering::Equal) => {}
            ord => return ord,
        }
        self.weight.partial_cmp(&other.weight)
    }
}

fn main() {
    assert!(Dungchi{height:0, weight:0}<Dungchi{height:1, weight:1}, "The lt method is not implemented well!");

    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .unwrap();
    let n = s.trim().parse::<usize>().unwrap();
    let mut v = vec![Dungchi{height: 0, weight: 0,}; n];
    for i in 0..n {
        s = String::new(); // => s를 한 줄 입력마다 초기화해줘야함!
        io::stdin()
            .read_line(&mut s)
            .unwrap();
        let x = s.trim().split_ascii_whitespace().map(|num| num.parse::<u32>().unwrap()).collect::<Vec<u32>>();
        v[i].height = x[0];
        v[i].weight = x[1];
    }
    //println!("s is {}", s);
    //panic!();
    //assert_ne!(v[0], v[2], "s must be initialized! v[0]=v[2]={:?}", v[0]);
    //assert_eq!(v[0], Dungchi{height: 55 , weight: 185}, "Dungchi vector v[0] = {:?} is not initialized well!", v[0]);
    //assert_eq!(v[2], Dungchi{height: 88 , weight: 186}, "Dungchi vector v[2] = {:?} is not initialized well!", v[2]);
    for i in 0..n {
        let mut rank = 1;
        (0..n).filter(|&num| num!=i).for_each(|j| if v[i]<v[j] {rank+=1;});
        /*for j in (0..n).filter(|&num| num!=i) {
            assert_ne!(i, j, "i and j should not be equal.");
            if v[i]<v[j] {
                assert!(v[i].weight<v[j].weight && v[i].height < v[j].weight, "WTF??");
                rank+=1;
            }
        }*/
        print!("{} ", rank);
    }
}
