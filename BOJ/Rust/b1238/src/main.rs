use std::{io, io::Write, str, collections::BinaryHeap, cmp};

pub struct UnsafeScanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> UnsafeScanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    pub fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

fn process_dijkstra (
    d : &mut Vec<i32>,
    edges : &Vec<Vec<(i32, usize)>>,
    n : usize,
    from : usize,
) {
    let mut pq = BinaryHeap::new();
    pq.push((-0, from));
    let mut isdefined = vec![false;n+1];
    while let Some((mut cost, to)) = pq.pop() {
        if isdefined[to] == true {
            continue;
        }
        isdefined[to] = true;
        cost=(!cost)+1; // cost*=-1;
        d[to] = cost;
        for j in edges[to].iter() {
            let (nxt_cost, nxt) = (cost+(*j).0, (*j).1);
            if d[nxt] > nxt_cost {
                d[nxt] = nxt_cost;
                pq.push((-nxt_cost, nxt));
            }
        }
    }
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let (n, m, x) = (
        scan.token::<usize>(),
        scan.token::<usize>(),
        scan.token::<usize>(),
    );
    let mut graph = vec![Vec::new();n+1];
    let mut rgraph = vec![Vec::new();n+1];
    for _ in 0..m {
        let (a, b, w) = (scan.token::<usize>(), scan.token::<usize>(), scan.token::<i32>());
        graph[a].push((w, b));
        rgraph[b].push((w, a));
    }
    
    const BIG : i32 = 1000001;
    let mut d1 = vec![BIG;n+1];
    let mut d2 = vec![BIG;n+1];
    
    // home to party
    process_dijkstra(&mut d1, &rgraph, n, x);
    // party to home
    process_dijkstra(&mut d2, &graph, n, x);

    let mut ans = 0;
    for i in 1..=n {
        ans = cmp::max(ans, d1[i] + d2[i]);
    }
    write!(out, "{}", ans).unwrap();
}

/*
fn process_dijkstra(
    vertices: &mut Vec<i32>,
    vertex_info: &Vec<Vec<(usize, i32)>>,
    n: usize,
    from: usize,
    to: usize,
) {
    let mut temp_vertices = vec![i32::MAX; n + 1];
    temp_vertices[from] = 0;

    let mut queue = BinaryHeap::new();
    queue.push((0, from));

    while !queue.is_empty() {
        let (mut cost, vertex) = queue.pop().unwrap();
        cost *= -1;

        for info in vertex_info[vertex].iter() {
            let (next_vertex, mut next_cost) = *info;
            next_cost += cost;

            if temp_vertices[next_vertex] > next_cost {
                temp_vertices[next_vertex] = next_cost;
                queue.push((-next_cost, next_vertex));
            }
        }
    }

    vertices[from] = temp_vertices[to];
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = UnsafeScanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let (n, m, x) = (
        scan.token::<usize>(),
        scan.token::<usize>(),
        scan.token::<usize>(),
    );
    let mut vertices1 = vec![i32::MAX; n + 1];
    let mut vertices2 = vec![i32::MAX; n + 1];
    let mut vertex_info = vec![Vec::new(); n + 1];

    for _ in 0..m {
        let (u, v, w) = (
            scan.token::<usize>(),
            scan.token::<usize>(),
            scan.token::<i32>(),
        );
        vertex_info[u].push((v, w));
    }

    // From home to party
    for i in 1..=n {
        if i == x {
            continue;
        }

        process_dijkstra(&mut vertices1, &vertex_info, n, i, x);
    }

    // From party to home
    vertices2[x] = 0;

    let mut queue = BinaryHeap::new();
    queue.push((0, x));

    while !queue.is_empty() {
        let (mut cost, vertex) = queue.pop().unwrap();
        cost *= -1;

        for info in vertex_info[vertex].iter() {
            let (next_vertex, mut next_cost) = *info;
            next_cost += cost;

            if vertices2[next_vertex] > next_cost {
                vertices2[next_vertex] = next_cost;
                queue.push((-next_cost, next_vertex));
            }
        }
    }

    let mut ans = 0;

    for i in 1..=n {
        if vertices1[i] != i32::MAX && vertices2[i] != i32::MAX {
            ans = cmp::max(ans, vertices1[i] + vertices2[i]);
        }
    }

    writeln!(out, "{}", ans).unwrap();
}
 */