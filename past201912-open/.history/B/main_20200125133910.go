package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n)
	for i, _ := range t {
		fmt.Scan(v)
	}

	for i, v := range t {
		fmt.Println(i, v)
	}

}
