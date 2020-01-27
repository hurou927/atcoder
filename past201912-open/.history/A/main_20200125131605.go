package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	if len(s) != 3 {
		fmt.Println("error")
	}

	for i, v := range len(s) {
		fmt.Println(i, v)
	}
}
