package main

import (
	"fmt"
)

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func getIntSlice(size int, isStartWithZero bool) []int {
	t := make([]int, size+1)
	var offset int = 0
	if !isStartWithZero {
		offset = 1
	}
	for i := 0; i < size; i++ {
		fmt.Scan(&t[i+offset])
	}
	return t
}

func main() {
	N := getInt()

	adj := make([][]int, N+1)
	for i := 1; i < N; i = i + 1 {
		adj[i] = make([]int, N+1)
	}
	for i := 1; i <= N; i++ {
		for j := i + 1; j <= N; j++ {
			fmt.Printf("%v ", getInt())
		}
		fmt.Println()
	}
}
