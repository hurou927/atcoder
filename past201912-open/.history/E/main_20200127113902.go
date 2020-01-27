package main

import (
	"fmt"
	"sort"
)

func main() {

	var n int
 	fmt.Scan(&n

	n := 6
	t := make([]int, n)

	for i := 0; i < n; i = i + 1 {
		fmt.Scan(&t[i])
	}

	sort.Ints(t)
	fmt.Println(t[3])

}
