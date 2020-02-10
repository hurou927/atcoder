use std::io::Read;


fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let w: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let c: usize = iter.next().unwrap().parse::<usize>().unwrap();
    let stones: Vec<(usize, usize, i64)> = (0..n)
        .map(|_| {
            (
                iter.next().unwrap().parse::<usize>().unwrap(),
                iter.next().unwrap().parse::<usize>().unwrap(),
                iter.next().unwrap().parse::<i64>().unwrap(),
            )
        })
        .collect();

}
