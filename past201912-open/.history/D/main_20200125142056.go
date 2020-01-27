package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n+1) //default zero
	for i := 0; i < n; i = i + 1 {
		var v int
		fmt.Scan(&v)
		t[v] = t[v] + 1
	}

	var non, dup int = -1, -1

	for i := 1; i <= n; i = i + 1 {
		if t[i] == 0 {
			non = i
		}
		if t[i] == 2 {
			dup = i
		}
	}

}
