package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scan(&s)

	if len(s) != 3 {
		fmt.Println("error")
	}

	for i, v := range s {
		if v < '0' || v > '9' {
			fmt.Println("error")
		}
	}

	fmt.Println(strconv.Atoi(s) * 2)
}
