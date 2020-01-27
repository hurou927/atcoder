package main

import (
	"fmt"
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
		if command == 1 {
			fmt.Scan(&q)
		}
		fmt.Println(command, p, q)

		if command == 1 {
			t[p*n+q] = 1
		} else if command == 2 {
			for j := 0; j < n; j = j + 1 {
				if t[j*n+p] == 1 {
					t[p*n+j] = t[j*n+p]
				}
			}
		} else {
			for j := 0; j < n; j = j + 1 {
				if t[p*n+j] == 1 {
					for k := 0; k < n; k = k + 1 {

					}
				}
			}
		}
	}

}
