package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	//	t := make([]int, n)
	var p int
	for i >= 0; i < n; i = i + 1 {
		//fmt.Scan(&t[i])
		var t int
		fmt.Scan(&t)

		if i > 0 {

			if t == p {
				fmt.Printf("stay\n")
			} else if t > p {
				fmt.Printf("up %v\n", t-p)
			} else {
				fmt.Printf("down %v\n", p-t)
			}
		}

		p = t

	}

	// for i, v := range t {
	// 	fmt.Println(i, v)
	// }

}
