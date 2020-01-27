package main

import (
	"fmt"
)

func main() {

	n := 6
	t := make([]int, n)

	var p int
	for i := 0; i < n; i = i + 1 {
		fmt.Scan(&t[i])
	}

	// for i, v := range t {
	// 	fmt.Println(i, v)
	// }

}
