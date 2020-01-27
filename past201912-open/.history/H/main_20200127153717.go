package main

import (
	"fmt"
)

type MinC struct {
	evenMinIndex int
	oddMinIndex  int
	evenMinValue int
	oddMinValue  int
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
		m.evenMinValue = m.values[m.evenMinIndex]
		m.oddMinValue = m.values[m.oddMinIndex]
	}
}

func (m *MinC) update(index int, v int) {
	m.values[index] = v
	if index&1 == 0 {
		if v < m.values[m.evenMinIndex] {
			m.evenMinIndex = index
			m.evenMinValue = v
		}
	} else {
		if v < m.values[m.oddMinIndex] {
			m.oddMinIndex = index
			m.oddMinValue = v
		}
	}
}

func (m *MinC) print() {
	fmt.Printf("%v, %v $ ", m.evenMinIndex, m.oddMinIndex)
	for i := 1; i < len(m.values); i = i + 1 {
		v := m.values[i]
		fmt.Printf("%v, ", v)
	}
	fmt.Println()
}

func main() {

	var N int
	fmt.Scan(&N)

	m := newMinC(N)

	var inputSum int = 0
	for i := 1; i <= N; i = i + 1 {
		fmt.Scan(&m.values[i])
		inputSum += m.values[i]
	}

	m.init()
	// m.print()

	var Q int
	fmt.Scan(&Q)

	var oddMinusValue int = 0
	var evenMinusValue int = 0
	for i := 0; i < Q; i++ {
		var com int
		fmt.Scan(&com)
		var x, a int = -1, -1
		if com == 1 {
			fmt.Scan(&x)
		}
		fmt.Scan(&a)

		switch com {
		case 1:
			for i := 1; i <= N; i += 2 {
				m.values[i] -= a
			}

			for i := 1; i <= N; i += 2 {
				m.values[i] -= a
			}

			if m.values[x] >= a {
				m.update(x, m.values[x]-a)
			}
		case 2:
			if m.values[m.oddMinIndex]-oddMinusValue >= a {
				oddMinusValue = oddMinusValue + a
			}
		case 3:
			if m.values[m.oddMinIndex]-oddMinusValue >= a && m.values[m.evenMinIndex]-evenMinusValue >= a {
				oddMinusValue += a
				evenMinusValue += a
			}
		}
		// m.print()
	}

	var sum int = 0
	for _, v := range m.values {
		sum += v
	}

	fmt.Println(inputSum - sum)
}
