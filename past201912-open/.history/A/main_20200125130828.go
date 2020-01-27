package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(n, n/100)
	if n/100 > 0 && n/100 < 10 {
		fmt.Println(n * 2)
	} else {
		fmt.Println("error")
	}

}
