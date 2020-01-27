package main

import (
	"fmt"
	"sort"
)

func main() {

	var n, q int
	fmt.Scan(&n, &q)

	t := make([]int, n*n)

	for i := 0; i < q; i = i + 1 {
		var command int
		fmt.Scan(&command)
		var p, q int = -1, -1
		fmt.Scan(&p)
		if command == 1
	}

	sort.Ints(t)
	fmt.Println(t[3])

}
