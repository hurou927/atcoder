package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n)
	for i := 0; i < n; i = i + 1 {
		fmt.Scan(&t[i])
	}

}
