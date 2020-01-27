package main

import "fmt"

func main() {
	var s string
	fmt.Scan(s)

	if n/100 > 0 && n/100 < 10 {
		fmt.Println(n * 2)
	} else {
		fmt.Println("error")
	}

}
