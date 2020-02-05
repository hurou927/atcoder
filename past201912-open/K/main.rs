use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_whitespace();

    let n: usize = iter.next().unwrap().parse::<usize>().unwrap();
    // let bosses: Vec<i64> = (0..m)
    //     .map(|_| iter.next().unwrap().parse::<i64>().unwrap() )})
    //     .collect();

    let w: usize =  (n as f64).log2().ceil() as usize + 1;

    // println!("{} {}", n, w);

    let mut doubling: Vec<Vec<usize>> = (0..w)
        .map(|_| {
            vec![0; n+1]
        }).collect();
    let mut rank:  Vec<Vec<i64>> = (0..w)
        .map(|_| {
            vec![0; n+1]
        }).collect();


    for i in 1..n+1 {
        let input = iter.next().unwrap().parse::<i64>().unwrap();
        doubling[0][i] = match input {
            -1 => 0,
            _  => input as usize
        };
        rank[0][i] = match input {
            -1 => 0,
            _  => 1
        }
    };
    doubling[0][0] = 0;
    rank[0][0] = 0;

    for i in 1..w {
        for j in 1..n+1 {
            let next = doubling[i-1][j];
            doubling[i][j] =  doubling[i-1][next];
            rank[i][j] = rank[i-1][j] + rank[i-1][next];
        }
    }

    // (1..n+1).for_each(|j| {
    // 	println!("{} {} {}",j,doubling[w-1][j], rank[w-1][j]);
    // });

    let q = iter.next().unwrap().parse::<usize>().unwrap();
    for _i in 0..q {
        let a =iter.next().unwrap().parse::<usize>().unwrap();
        let b =iter.next().unwrap().parse::<usize>().unwrap();
        let rank_a = rank[w-1][a];
        let rank_b = rank[w-1][b];
        if rank_a <= rank_b {
            println!("No");
        } else {

            let diff = rank_a - rank_b;
            let mut jump = a;
            let mut shifts = 0;
            while (diff >> shifts) != 0 {
                if (diff>>shifts) & 1 == 1 {
                    jump = doubling[shifts][jump];
                }
                shifts = shifts + 1;
            }
            if jump == b {
                println!("Yes");
            } else {
                println!("No");
            }
        }
    
    };


}
