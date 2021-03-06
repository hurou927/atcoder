package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	if len(s) != 3 {
		fmt.Println("error")
	}

	for _, v := range s {
		if v < '0' || v > '9' {
			fmt.Println("error")
			return
		}
	}

	i, _ := strconv.Atoi(s)
	fmt.Println(i * 2)
}
