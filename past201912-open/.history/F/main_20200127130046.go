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
	fmt.Scan(s)
	fmt.Println(s)

}
