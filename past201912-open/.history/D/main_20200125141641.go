package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n) //default zero
	for i := 0; i < n; i = i + 1 {
		fmt.Scan(&v)
		t[v] = t[v] + 1
	}

}
