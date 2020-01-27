package main

import (
	"fmt"
)

func main() {

	var N int
	fmt.Scan(&N)
	C := make([]int, N)

	for i, _ := range C {
		fmt.Scan(&C[i])
	}
}
