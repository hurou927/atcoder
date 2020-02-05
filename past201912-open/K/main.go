package main

import (
	"fmt"
	"math"
)

const debug bool = true
const Inf int = math.MaxInt32

func dln(v ...interface{}) {
	if debug {
		fmt.Println(v...)
	}
}

func df(s string, v ...interface{}) {
	if debug {
		fmt.Printf(s, v...)
	}
}

func getInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func getInt2() (int, int) {
	var n, m int
	fmt.Scan(&n, &m)
	return n, m
}

// struct table2dInt {
//     X int
//     Y int
//     table []int
// }

// func newTable2dInt(sizeX int, sizeY int) table2dInt {
//     return table2dInt {
//         X: sizeX,
//         Y: sizeY,
//         table: make([]int, sizeX * sizeY)
//     }
// }

// func (t *table2dInt)

// func solution2() {

// }

func solution1() {
	N := getInt()

	W := int(math.Ceil(math.Log2(float64(N)))) + 1
	doublingTable := make([]int, (W+1)*(N+1))
	rank := make([]int, (W+1)*(N+1))

	// for i := 0; i < W; i++ {
	// 	doublingTable[i] = make([]int, N+1)
	// 	rank[i] = make([]int, N+1)
	// }

	for i := 1; i <= N; i++ {
		doublingTable[0*(N+1)+i] = getInt()
		rank[0*(N+1)+i] = 1
	}
	// println(N, W)
	var depth int = 0
	for i := 1; i < W; i++ {
		var updated bool = false
		for j := 1; j <= N; j++ {
			index := doublingTable[(i-1)*(N+1)+j]
			if index != -1 {
				doublingTable[i*(N+1)+j] = doublingTable[(i-1)*(N+1)+index]
				rank[i*(N+1)+j] = rank[(i-1)*(N+1)+j] + rank[(i-1)*(N+1)+index]
				updated = true
			} else {
				doublingTable[i*(N+1)+j] = -1
				rank[i*(N+1)+j] = rank[(i-1)*(N+1)+j]
			}
		}
		if !updated {
			break
		}
		depth = i
	}

	Q := getInt()
	for i := 0; i < Q; i++ {
		a, b := getInt2()
		rankA := rank[depth*(N+1)+a]
		rankB := rank[depth*(N+1)+b]

		if rankB > rankA {
			fmt.Println("No")
			continue
		}

		diff := rankA - rankB

		var jump int = a
		for index := 0; (diff >> uint(index)) != 0; index++ {
			if ((diff >> uint(index)) & 1) == 1 {
				jump = doublingTable[index*(N+1)+jump]
			}
		}
		if jump == b {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}

}

func main() {
	solution1()
}
