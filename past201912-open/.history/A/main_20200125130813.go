package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n, n/1000)
	if n/1000 > 0 && n/1000 < 10 {
		fmt.Println(n * 2)
	} else {
		fmt.Println("error")
	}

}
