use std::io::Read;
// use std::collections::BinaryHeap;

// const INF_L: i64 = std::i32::MAX as i64;
// const INF_L: i64 = std::i64::MAX;

fn maxf64(a: f64, b: f64) -> f64 {
    if a > b {
        a
    } else {
        b
    }
}

fn find_chimera(monsters: &Vec<(i64, i64)>, _helpers: &Vec<(i64, i64)>) -> f64 {
    let n = monsters.len();

    let mut ok: f64 = 0.0;
    let mut ng: f64 = 100000.0;
    // println!("{} {}",1e7, 1e-7);
    while (ok - ng).abs() > 1e-8 {
        let mid: f64 = (ok + ng) / 2.0;
        // println!("ng:{}, mid:{}, ok:{}", ng, mid, ok);
        let mut scores = monsters
            .iter()
            .map(|v| (v.1 as f64) - mid * (v.0 as f64))
            .collect::<Vec<f64>>();
        scores.sort_by(|a, b| b.partial_cmp(a).unwrap());

        let sum = scores.iter().take(5).fold(0.0, |sum, item| sum + item);
        if sum >= 0.0 {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}

fn find_chimera_with_helper(monsters: &Vec<(i64, i64)>, helpers: &Vec<(i64, i64)>) -> f64 {
    let n = monsters.len();
    let m = helpers.len();

    let mut ok: f64 = 0.0;
    let mut ng: f64 = 100000.0;
    // println!("{} {}",1e7, 1e-7);
    while (ok - ng).abs() > 1e-8 {
        let mid: f64 = (ok + ng) / 2.0;
        // println!("ng:{}, mid:{}, ok:{}", ng, mid, ok);
        let mut scores = monsters
            .iter()
            .map(|v| (v.1 as f64) - mid * (v.0 as f64))
            .collect::<Vec<f64>>();
        scores.sort_by(|a, b| b.partial_cmp(a).unwrap());

        
        let sum = scores.iter().take(4).fold(0.0, |sum, item| sum + item);
        
        let is_ok = (0..m)
            .map(|v| sum + (helpers[v].1 as f64) - mid * (helpers[v].0 as f64))
            .fold(false, |acc, item| { acc | (item >= 0.0) });
        if is_ok {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let m: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let monsters: Vec<(i64, i64)> = (0..n)
        .map(|_| {
            (
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect();

    let helpers: Vec<(i64, i64)> = (0..m)
        .map(|_| {
            (
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect();

    let max_5 = find_chimera(&monsters, &helpers);
    let max_4 = find_chimera_with_helper(&monsters, &helpers);

    println!("{:.10}", maxf64(max_5, max_4));
}
