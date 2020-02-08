use std::io::Read;
use std::cmp::Ordering;
use std::collections::BinaryHeap;

// const INF_L: i64 = std::i32::MAX as i64;
const INF_L: i64 = std::i64::MAX;

#[derive(Copy, Clone, Eq, PartialEq)]
struct Edge{
    from: usize,
    to: usize,
    weight: i64,
}
impl Ord for Edge {
    fn cmp(&self, other: &Edge) -> Ordering {
        other.weight.cmp(&self.weight)
    }
}
impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Edge) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}



fn prim_for_adjmatrix(graph: &Vec<Vec<i64>>, start: usize) -> Vec<(usize, i64)> {
    let n = graph.len();
    let mut heap = BinaryHeap::new();
    let mut dist : Vec<(usize, i64)> = vec![(std::usize::MAX, INF_L); n];
    let mut visited = vec![false; n];

    heap.push((0, 0, start));
    dist[start] = (start, 0);
    while let Some((_priority, _cost, position)) = heap.pop(){
        if visited[position] {
            continue;
        }
        visited[position] = true;
        for i in 0..n {
            let weight = graph[position][i];
            if !visited[i] && weight >= 0 && dist[i].1 > weight {
                dist[i] = (position, weight);
                heap.push((-weight, weight, i))
            }
        }
    }
    dist
}

fn squared_euclid_distance(a:i64, b:i64) -> i64 {
    a*a + b*b
}


fn node_distance(nodes: &Vec<(i64, i64, i64)>, index1: usize, index2:usize) -> i64 {
    if index1 == index2 {
        -1
    } else {
        let n = nodes[index1];
        let m = nodes[index2];
        if n.2 == m.2{
            squared_euclid_distance(n.0-m.0, n.1-m.1)
        } else {
            100 * squared_euclid_distance(n.0-m.0, n.1-m.1)
        }
    }
}

fn calc_distance(dist: &Vec<(usize, i64)>) -> f64 {
   dist.iter().fold(0.0, |sum, a| {
        if a.1 == INF_L { 
            sum
        } else { 
            sum + (a.1 as f64).sqrt()
        }
    })
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let m: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let all_nodes = n + m;
    
    let nodes: Vec<(i64, i64, i64)> = (0..all_nodes)
        .map(|_| {
            (
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect();

    // construct graph
    let mut graph: Vec<Vec<i64>> = (0..all_nodes)
        .map(|_| {
            vec![-1;all_nodes]
        }).collect();


    for i in 0..n {
        for j in 0..n {
            graph[i][j] = node_distance(&nodes, i, j);
        }
    }

    let dist = prim_for_adjmatrix(&graph, 0);
    // for i in 0..(all_nodes) {
    //     println!("node {}: {} {}", i, dist[i].0, dist[i].1);
    // }
    // println!("{}", calc_distance(&dist));
    let mut smallest = calc_distance(&dist);
    let mut pre:u64 = 0;
    for i in 1..((1<<m)) {
        let code: u64 = i ^ (i >> 1);
        let lsb = (pre^code).trailing_zeros();
        let is_zero = (code>>lsb)&1 == 0;
        let node_num = n + lsb as usize;
        // println!("i:{} node_num:{} zero?:{}", i, node_num, is_zero);

        if is_zero {
            for i in 0..n+m {
                graph[node_num][i] = -1;
                graph[i][node_num] = -1;
            }
        } else {
            for i in 0..n+m {
                let dis = if i == node_num {
                    -1
                } else if i < n {
                    node_distance(&nodes, i, node_num)
                } else if (code >> (i-n) ) & 1 == 0 {
                    -1
                } else {
                    node_distance(&nodes, i, node_num)
                };
                graph[node_num][i] = dis;
                graph[i][node_num] = dis;
            }
        }
        
        let dist = prim_for_adjmatrix(&graph, 0);
        // for j in 0..(all_nodes) {
        //     println!("node {}: {} {}", j, dist[j].0, dist[j].1);
        // }
        let sum = calc_distance(&dist);
        // println!("{}", sum);
        smallest = if smallest > sum {
            sum
        } else {
            smallest
        };
        // println!("smallest {} {}", smallest, sum);
        pre = code;
    }
 



    println!("{:.12}", smallest);
}
