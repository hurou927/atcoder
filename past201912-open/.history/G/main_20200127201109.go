package main

import (
	"fmt"
)

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func maxInt(a int, b int, c int) int {
	if a > b {
		if c > a {
			return c
		} else {
			return a
		}
	} else {
		if c > b {
			return c
		} else {
			return b
		}
	}
}
func rec(adj [][]int, depth int, w int, bits uint, max int) int {
	if depth > max {
		return w
	}
	sums := [3]int{0, 0, 0}
	for i := u0; i < depth; i++ {
		g := (bits >> (2 * i)) & 3
		sums[g] += adj[depth][i]
	}
	return maxInt(
		rec(adj, depth+1, w+sums[0], (0<<(depth*2))|bits, max),
		rec(adj, depth+1, w+sums[1], (1<<(depth*2))|bits, max),
		rec(adj, depth+1, w+sums[2], (2<<(depth*2))|bits, max),
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
			// fmt.Printf("%v ", n)
		}
		// fmt.Println()
	}
	fmt.Println(rec(adj, 1, 0, 0, N))
}
