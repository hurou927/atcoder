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

	var Q int
	fmt.Scan(&Q)

	for i := 0; i < Q; i++ {
		var com int
		fmt.Scan(&com)
		var x, a int = -1, -1
		switch com {
		case 1:

		case 2:

		case 3:

		}
	}
}
