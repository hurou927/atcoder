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

	var oddMinIndex, evenMinIndex int = 0, 0

	var Q int
	fmt.Scan(&Q)

	for i := 0; i < Q; i++ {
		var com int
		fmt.Scan(&com)
		var x, a int = -1, -1
		if com == 1 {
			fmt.Scan(&x)
		}
		fmt.Scan(&a)
		fmt.Println(com, x, a)

		x = x - 1
		a = a - 1
		switch com {
		case 1:

		case 2:

		case 3:

		}
	}
}
