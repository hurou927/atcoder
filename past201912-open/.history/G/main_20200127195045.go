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
func rec(depth int, c int, bits int) int {
	return min(
            rec(depth+1, 0, (0 << depth) | bits),
            rec(depth+1, 1, (1 << depth) | bits),
            rec(depth+1, 2, (0 << depth) | bits)
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
