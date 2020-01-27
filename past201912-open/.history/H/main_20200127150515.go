package main

import (
	"fmt"
)

type MinC struct {
	evenMinIndex int
	oddMinIndex  int
	values       []int
}

func newMinC(size int) *MinC {
	m := new(MinC)
	m.evenMinIndex = 0
	m.oddMinIndex = 1
	m.values = make([]int, size)
	return m
}

func (m *MinC) init() {
	for i, v := range m.values {
		if i&1 == 0 {
			if v < m.values[m.evenMinIndex] {
				m.evenMinIndex = i
			}
		} else {
			if v < m.values[m.oddMinIndex] {
				m.oddMinIndex = i
			}
		}
	}
}

func (m *MinC) update(index int, v int) {
	m.values[index] = v
	if index&1 == 0 {
		if v < m.values[m.evenMinIndex] {
			m.evenMinIndex = index
		}
	} else {
		if v < m.values[m.oddMinIndex] {
			m.oddMinIndex = index
		}
	}
}

func main() {

	var N int
	fmt.Scan(&N)
	C := make([]int, N)

	for i, _ := range C {
		fmt.Scan(&C[i])
	}

	var oddMinIndex, evenMinIndex int = 0, 0
	for i, v := range C {
		if i&1 == 0 {
			if v < C[evenMinIndex] {
				evenMinIndex = i
			}
		} else {
			if v < C[oddMinIndex] {
				oddMinIndex = i
			}
		}
	}

	var Q int
	fmt.Scan(&Q)

	for i := 0; i < Q; i++ {
		var com int
		fmt.Scan(&com)
		var x, a int = -1, -1
		if com == 1 {
			fmt.Scan(&x)
		}
		fmt.Scan(&a)
		fmt.Println(com, x, a)

		x = x - 1
		a = a - 1
		switch com {
		case 1:

		case 2:

		case 3:

		}
	}
}
