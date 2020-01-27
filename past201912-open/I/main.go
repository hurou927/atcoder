package main

import (
	"fmt"
	"math"
)

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func getString() string {
	var s string
	fmt.Scan(&s)
	return s
}

func minInt(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func main() {
	N := getInt()
	M := getInt()
	s := make([]string, M+1)
	c := make([]int, M+1)
	bits := make([]uint, M+1)

	for i := 1; i <= M; i++ {
		s[i] = getString()
		c[i] = getInt()
		for _, w := range s[i] {
			var b uint = 0
			if w == 'Y' {
				b = 1
			}
			bits[i] = (bits[i] << 1) | b
		}
		// fmt.Println(N, i, s[i], c[i], bits[i])
	}

	width := 1 << uint(N)
	t := make([]int, width)
	for i := 0; i < width; i = i + 1 {
		t[i] = math.MaxInt32
	}
	t[0] = 0

	for i := 1; i <= M; i++ {
		n := bits[i]
		for j := uint(0); j < uint(width); j++ {
			if t[j] >= 0 {
				index := j | n
				t[index] = minInt(t[j]+c[i], t[index])
				// fmt.Println(index, j, n, t[index])
			}
		}
	}
	if t[width-1] == math.MaxInt32 {
		fmt.Println(-1)
	} else {
		fmt.Println(t[width-1])
	}

}
