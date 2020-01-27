package main

import "fmt"
import "strconv"

func main() {
	var s string
	fmt.Scan(&s)

	if len(s) != 3 {
		fmt.Println("error")
	}

	for i, v := range s {
		if v < '0' || v > '9'
			return
	}

	fmt.Println()
}
