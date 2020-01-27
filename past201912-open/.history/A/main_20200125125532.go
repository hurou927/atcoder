package main

import "fmt"

func main() {
	var n int
	fmtScan(&n)

	if n < 20 {
		fmt.Println("Child")
		return
	}

	fmt.Println("Adult")
}