package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n)
	for i, v := range t {
		fmt.Scan(&t[i])
		fmt.Println(i, v)
	}

	for i, v := range t {
		fmt.Scan(&t[i])
		fmt.Println(i, v)
	}

}
