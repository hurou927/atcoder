package main

import (
	"fmt"
)

func pt(t [][]bool, n int) {
	for i := 0; i < n; i = i + 1 {
		for j := 0; j < n; j = j + 1 {
			if t[i][j] && i != j {
				fmt.Printf("Y")
			} else {
				fmt.Printf("N")
			}
		}
		fmt.Printf("\n")
	}
}

func main() {

	var s string
	fmt.Scan(&s)
	fmt.Println(s)

	// var ss []string
	var f, e int = -1, -1
	for i, c := range s {
		fmt.Println(i, c)
		if c >= 'A' && c <= 'Z' {
			if e >= f {
				e = i
			} else {
				f = i
			}
		}
	}

}
