package main

import (
	"fmt"
)

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func min(a int, b int, c int) int {
	return a
}
func rec(adj [][]int, depth int, w int, bits int) int {
	var sum1, sum2, sum3 int = 0, 0, 0
	for i := 0; i < depth; i++ {
        g := bits >> (2 * i)
        switch g {
        case 0:
            sum1 +=  
        case 1:
            sum2 +=
        case 2:
            sum3 +=
        }
	}
	return min(
		rec(adj, depth+1, w+0, (0<<(depth*2))|bits),
		rec(adj, depth+1, w+1, (1<<(depth*2))|bits),
		rec(adj, depth+1, w+2, (2<<(depth*2))|bits),
	)
}

func main() {
	N := getInt()

	adj := make([][]int, N+1)
	for i := 1; i <= N; i = i + 1 {
		adj[i] = make([]int, N+1)
	}
	for i := 1; i <= N; i++ {
		for j := i + 1; j <= N; j++ {
			n := getInt()
			adj[i][j] = n
			adj[j][i] = n
			fmt.Printf("%v ", n)
		}
		fmt.Println()
	}

}
