package main

import (
	"fmt"
)

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func getIntSlice(size int) int* {
    t := make([]int, size)
    return t
}

func main() {
	var N int
	fmt.Scan(N)
}
