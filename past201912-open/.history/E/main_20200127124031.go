package main

import (
	"fmt"
)

func pt(t []int, n int) {
	for i := 0; i < n; i = i + 1 {
		for j := 0; j < n; j = j + 1 {
			if t[i*n+j] == 0 || i == j {
				fmt.Printf("N")
			} else {
				fmt.Printf("Y")
			}
		}
		fmt.Printf("\n")
	}
}

func main() {

	var n, q int
	fmt.Scan(&n, &q)

	t := make([]int, n*n)

	b := make([]int, n)

	for i := 0; i < q; i = i + 1 {
		var command int
		fmt.Scan(&command)
		var p, q int = -1, -1
		fmt.Scan(&p)
		if command == 1 {
			fmt.Scan(&q)
		}
		fmt.Println(command, p, q)

		p = p - 1
		q = q - 1
		if command == 1 {
			t[p*n+q] = 1
		} else if command == 2 {
			for j := 0; j < n; j = j + 1 {
				t[p*n+j] += t[j*n+p]
			}
		} else {
			for j := 0; j < n; j = j + 1 {
				b[j] = 0
			}
			for j := 0; j < n; j = j + 1 {
				if t[p*n+j] == 1 {
					for k := 0; k < n; k = k + 1 {
						b[k] += t[j*n+k]
					}
				}
			}
			for j := 0; j < n; j = j + 1 {
				t[p*n+j] += b[j]
			}

		}
		pt(t, n)
	}

	pt(t, n)

}
