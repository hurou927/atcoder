package main

import (
	"fmt"
	"sort"
)

func main() {

	var s string
	fmt.Scan(&s)
	fmt.Println(s)

	var words []string
	var f, e int = -1, -1
	for i, c := range s {
		// fmt.Println(i, c)
		if c >= 'A' && c <= 'Z' {
			if f <= e {
				f = i
			} else {
				e = i
				// fmt.Println(f, e, s[f:e+1])
				words = append(words, s[f:e+1])
			}
		}
	}
	// for i, w := range words {
	// 	fmt.Println(i, w)
	// }

	sort.Strings(words)

	var output string = ""
	for i, w := range words {
		fmt.Println(i, w)
		// var word string = w
		output = output + w
	}
	fmt.Println(output)
}
