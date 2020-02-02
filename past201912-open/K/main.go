package main

import (
	"errors"
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

type SQVec struct {
	maxSize int
	t       []interface{}

	frontIndex int
	backIndex  int
	itemCount  int
}

func newSQVecWithMaxSize(size int) SQVec {
	return SQVec{maxSize: size, t: make([]interface{}, size), frontIndex: -1, backIndex: 0, itemCount: 0}
}

func (sqv *SQVec) pushFront(a interface{}) error {
	if sqv.itemCount >= sqv.maxSize {
		return errors.New("exceed maxsize")
	}
	sqv.frontIndex = sqv.frontIndex + 1
	if sqv.frontIndex == sqv.maxSize {
		sqv.frontIndex = 0
	}
	sqv.t[sqv.frontIndex] = a

	sqv.itemCount++
	return nil
}

func (sqv *SQVec) pushBack(a interface{}) error {
	if sqv.itemCount >= sqv.maxSize {
		return errors.New("exceed maxsize")
	}
	sqv.backIndex = sqv.backIndex - 1
	if sqv.backIndex < 0 {
		sqv.backIndex = sqv.maxSize - 1
	}
	sqv.t[sqv.backIndex] = a

	sqv.itemCount++
	return nil
}

func (sqv *SQVec) popFront() (interface{}, error) {
	if sqv.itemCount == 0 {
		return nil, errors.New("item does not exist")
	}
	v := sqv.t[sqv.frontIndex]

	sqv.frontIndex = sqv.frontIndex - 1
	if sqv.frontIndex < 0 {
		sqv.frontIndex = sqv.maxSize - 1
	}

	sqv.itemCount--
	return v, nil
}

func (sqv *SQVec) popBack() (interface{}, error) {
	if sqv.itemCount == 0 {
		return nil, errors.New("item does not exist")
	}
	v := sqv.t[sqv.backIndex]

	sqv.backIndex = sqv.backIndex + 1
	if sqv.backIndex == sqv.maxSize {
		sqv.backIndex = 0
	}

	sqv.itemCount--
	return v, nil
}

func (sqv *SQVec) sPush(item interface{}) error { return sqv.pushFront(item) }
func (sqv *SQVec) sPop() (interface{}, error)   { return sqv.popFront() }
func (sqv *SQVec) qPush(item interface{}) error { return sqv.pushFront(item) }
func (sqv *SQVec) qPop() (interface{}, error)   { return sqv.popBack() }

type Edge struct {
	from   int
	to     int
	weight int
}

func newEdge(f, t, w int) Edge {
	return Edge{f, t, w}
}

type Graph struct {
	edges [][]Edge
}

func newGraph(size int, cap int) Graph {
	edges := make([][]Edge, size)
	for i := 0; i < size; i++ {
		edges[i] = make([]Edge, 0, cap)
	}
	return Graph{edges}
}
func (g *Graph) addEdge(f, t, w int) {
	g.edges[f] = append(g.edges[f], Edge{f, t, w})
}
func (g *Graph) print() {
	for i, edges := range g.edges {
		fmt.Printf("%3d :", i)
		for _, e := range edges {
			fmt.Printf("%3d(%4d) ", e.to, e.weight)
		}
		fmt.Println()
	}
}

type Node struct {
	n int
	v int
}

// not use priority queuej
func (g *Graph) dijkstra_bf(start int, end int) []Node {
	n := len(g.edges)
	dist := make([]Node, n, n)
	visited := make([]bool, n, n)
	for i := 0; i < n; i++ {
		visited[i] = false
		dist[i] = Node{n: -1, v: Inf}
	}
	dist[start] = Node{start, 0}

	for {
		var selectedNode int = -1
		var costS2F int = Inf
		for i, v := range dist {
			if !visited[i] && v.v < costS2F {
				selectedNode = i
				costS2F = v.v
			}
		}

		if selectedNode == -1 {
			break
		}
		visited[selectedNode] = true

		if selectedNode == end {
			break
		}
		for _, next := range g.edges[selectedNode] {
			// s ---- f ------ n
			//  \-------------/
			costF2N := next.weight     //
			costS2N := dist[next.to].v // current least distance
			if costS2N > costS2F+costF2N {
				dist[next.to] = Node{
					n: selectedNode,
					v: costS2F + costF2N,
				}
			}
		}

	}
	// can be excluded
	for i := 0; i < n; i++ {
		if !visited[i] {
			dist[i].n = -1
			dist[i].v = Inf
		}
	}
	return dist
}

func (g *Graph) bfs(start int) []Node {
	n := len(g.edges)
	visited := make([]bool, n)
	nodes := make([]Node, n)
	queue := newSQVecWithMaxSize(n * 2)

	queue.qPush(start)
	visited[start] = true
	nodes[start] = Node{n: -1, v: 0}

	for queue.itemCount > 0 {
		nextIf, _ := queue.qPop()
		next := nextIf.(int)
		reloadV := nodes[next].v

		for _, e := range g.edges[next] {
			if !visited[e.to] {
				queue.qPush(e.to)
				nodes[e.to] = Node{n: next, v: reloadV + 1}
			}
		}

	}
	return nodes
}

func main() {
	N := getInt()
	p := make([]int, N+1)

	g := newGraph(N+1, int(math.Sqrt(float64(N))))

	var ceo = 0
	for i := 1; i <= N; i++ {
		p[i] = getInt()
		if p[i] == -1 {
			ceo = i
		} else {
			g.addEdge(p[i], i, 1)
		}
	}

	// g.print()

	// dist := g.dijkstra_bf(ceo, -1)
	dist := g.bfs(ceo)
	// for i, d := range dist {
	// fmt.Println(i, d)
	// }

	Q := getInt()
	// a, b := make([]int, Q), make([]int, Q)
	for i := 0; i < Q; i++ {
		// a[i], b[i] = getInt2()
		a, b := getInt2()

		var isBuka bool = true
		if dist[a].v <= dist[b].v {
			isBuka = false
		} else {
			var index int = dist[a].n
			for {
				if dist[index].v <= dist[b].v {
					if index != b {
						isBuka = false
					}
					break
				}
				index = dist[index].n
			}
		}

		if isBuka {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}

	}

}
