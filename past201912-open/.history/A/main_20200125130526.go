package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n)
	if n/10 == 3 {
		fmt.Println(n)
	} else {
		fmt.Println("error")
	}

}
