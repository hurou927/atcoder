package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {

	var s string
	fmt.Scan(&s)
	// fmt.Println(s)

	// var words []string
	words := make([]string, 0, len(s)/2)
	var f, e int = -1, -1
	for i, c := range s {
		// fmt.Println(i, c)
		if c >= 'A' && c <= 'Z' {
			if f <= e {
				f = i
			} else {
				e = i
				// fmt.Println(f, e, s[f:e+1])
				words = append(words, strings.ToLower(s[f:e+1]))
			}
		}
	}
	// for i, w := range words {
	// 	fmt.Println(i, w)
	// }

	sort.Strings(words)

	var output string = ""
	for _, w := range words {
		// fmt.Println(i, w)
		b := []byte(w)
		b[0] = b[0] - 'a' + 'A'
		b[len(b)-1] = b[len(b)-1] - 'a' + 'A'
		// output = output + string(b)
		fmt.Printf("%s", b)
	}
	// fmt.Println(output)
}
