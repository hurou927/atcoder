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

func addEdges(g *Graph, t [][]int) {
	H := len(t)
	W := len(t[0])
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			from := i*W + j
			if i != 0 {
				g.addEdge(from, (i-1)*W+j, t[i-1][j])
			}
			if j != 0 {
				g.addEdge(from, (i)*W+(j-1), t[i][j-1])
			}
			if i != H-1 {
				g.addEdge(from, (i+1)*W+j, t[i+1][j])
			}
			if j != W-1 {
				g.addEdge(from, i*W+j+1, t[i][j+1])
			}
		}
	}
}

func main() {

	H, W := getInt2()

	g := newGraph(H*W, 4)

	t := make([][]int, H, H)
	for i := 0; i < H; i++ {
		t[i] = make([]int, W, W)
		for j := 0; j < W; j++ {
			t[i][j] = getInt()
		}
	}

	addEdges(&g, t)

	var start, mid, end int = H*W - W, H*W - 1, W - 1
	start2all := g.dijkstra_bf(start, -1)
	mid2all := g.dijkstra_bf(mid, -1)
	end2all := g.dijkstra_bf(end, -1)

	var minDist int = Inf
	for i := 0; i < H*W; i++ {
		h := i / W
		w := i % W
		d := start2all[i].v + mid2all[i].v + end2all[i].v - 2*t[h][w]
		if minDist > d {
			minDist = d
		}
	}

	fmt.Println(minDist)
}
