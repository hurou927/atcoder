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
	m.evenMinIndex = 1
	m.oddMinIndex = 1
	m.values = make([]int, size+1)
	return m
}

func (m *MinC) init() {
	for i := 1; i < len(m.values); i = i + 1 {
		v := m.values[i]
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

func (m *MinC) print() {
	fmt.Printf("%v, %v $ ", m.evenMinIndex, m.oddMinIndex)
	for _, v := range m.values {
		fmt.Printf("%v, ", v)
	}
	fmt.Println()
}

func main() {

	var N int
	fmt.Scan(&N)

	m := newMinC(N)

	for i, _ := range m.values {
		fmt.Scan(&m.values[i])
	}
	m.init()
	m.print()

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
			if m.values[x] >= a {
				m.update(x, m.values[x]-a)
			}
		case 2:
			if m.values[m.oddMinIndex] >= a {
				for j := 1; j < N; j = j + 2 {
					m.values[j] -= a
				}
			}
		case 3:
			if m.values[m.oddMinIndex] >= a && m.values[m.evenMinIndex] >= a {
				for j := 0; j < N; j = j + 1 {
					m.values[j] -= a
				}
			}
		}
		m.print()
	}

	var sum int = 0
	for _, v := range m.values {
		sum += v
	}

	fmt.Println(sum)
}
