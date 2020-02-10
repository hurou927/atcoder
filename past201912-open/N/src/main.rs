use std::i64::MAX as INF_I64;
use std::io::Read;

//       b_s_min  left      right   b_s_max
//     ------->   <-------------->  <-------
//

fn b_search_right(stones: &Vec<(usize, usize, i64)>, right: usize) -> Option<usize> {
    let n = stones.len();
    let mut ok = 0;
    let mut ng = n;

    let is_ok = |index: usize| {stones[index].0 <= right};

    if !is_ok(ok) {
        return None;
    }

    while ng - ok > 1 {
        let mid = (ng + ok) / 2;
        if is_ok(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    Some(ok)
}

fn b_search_left(stones: &Vec<(usize, usize, i64)>, left: usize) -> Option<usize> {
    let n = stones.len();
    let mut ok: isize = (n - 1) as isize;
    let mut ng: isize = -1;

    let is_ok = |index: usize| {stones[index].0 >= left};
    if !is_ok(ok as usize) {
        return None;
    }

    while ok - ng > 1 {
        let mid = (ng + ok) / 2;
        if is_ok(mid as usize) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    Some(ok as usize)
}


fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let w: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let c: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let mut stones: Vec<(usize, usize, i64)> = (0..n)
        .map(|_| {
            (
                iter.next().unwrap().parse::<usize>().unwrap(),
                iter.next().unwrap().parse::<usize>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect();

    stones.sort();
    let psum_stones: Vec<i64> = stones.iter().scan(0, |state, &x| {
        *state = *state + x.2;
        Some(*state)
    }).collect();

    let mut stones_by_end: Vec<(usize, usize, i64)> =
        stones.iter().map(|v| (v.1, v.0, v.2)).collect();
    stones_by_end.sort();

    let psum_stones_by_end: Vec<i64> = stones_by_end.iter().scan(0, |state, &x| {
        *state = *state + x.2;
        Some(*state)
    }).collect();
    
    // println!("{} {} {}", n, w, c);
    // println!("{:?}", stones);
    // println!("{:?}", psum_stones);
    // println!("{:?}", stones_by_end);
    // println!("{:?}", psum_stones_by_end);

    // b_search_min(&stones_by_end, 23);

    let mut min = INF_I64;
    for i in 0..n {
        if stones[i].0 >= c {
            let left = stones[i].0 - c;
            let right = stones[i].0;
            
            let left_boader = b_search_right(&stones_by_end, left);
            let right_boader = b_search_left(&stones, right);
            // println!("i:{} {:?} {:?} {:?}",i,(left, right), left_boader, right_boader);


            let mut weight = 0;
            weight = match left_boader {
                None => weight,
                Some(v) => weight + psum_stones_by_end[v]
            };
            weight = match right_boader {
                None => weight,
                Some(v) if v == 0 => weight + psum_stones[n-1],
                Some(v) => weight + psum_stones[n-1] - psum_stones[v-1]
            };
            weight = psum_stones[n-1] - weight;
            // println!("w: {}", weight);
            min = if min > weight { weight } else { min };
        }
    }

    for i in 0..n {
        if w - stones_by_end[i].0 >= c {
            let left = stones_by_end[i].0;
            let right = stones_by_end[i].0 + c;

            
            let left_boader = b_search_right(&stones_by_end, left);
            let right_boader = b_search_left(&stones, right);

            let mut weight = 0;
            weight = match left_boader {
                None => weight,
                Some(v) => weight + psum_stones_by_end[v]
            };
            weight = match right_boader {
                None => weight,
                Some(v) if v == 0 => weight + psum_stones[n-1],
                Some(v) => weight + psum_stones[n-1] - psum_stones[v-1]
            };
            weight = psum_stones[n-1] - weight;
            // println!("w: {}", weight,);
            min = if min > weight { weight } else { min };
        }
    }
    println!("{}", min);
}
