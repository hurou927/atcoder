package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n, n/10)
	if n/1000 > 0 && n/1000 < 10 {
		fmt.Println(n)
	} else {
		fmt.Println("error")
	}

}
