use std::io::Read;

// 3.64925355954377
// 3.42188884244970

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let mut dices: Vec<Vec<i64>> = (0..n)
        .map(|_| {
            vec![
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            ]
        })
        .collect();
    let mut p = 0.0;

    let pre_index = 0;
    let mut pre_distribution = (
        1.0 / 6.0,
        1.0 / 6.0,
        1.0 / 6.0,
        1.0 / 6.0,
        1.0 / 6.0,
        1.0 / 6.0,
    );
    for i in 0..10 {}

    println!("{}", n);
}
