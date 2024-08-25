package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

var (
	sc = bufio.NewScanner(os.Stdin)
)

func input_arr() []int {
	sc.Scan()
	strs := strings.Split(sc.Text(), " ")
	nums := make([]int, len(strs))
	for i, s := range strs {
		nums[i], _ = strconv.Atoi(s)
	}
	return nums
}

func print_arr(arr []int) {
	for _, v := range arr {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func print_arr2(arr [][]int) {
	for _, v := range arr {
		for _, vv := range v {
			fmt.Print(vv, " ")
		}
		fmt.Println()
	}
}

func output_arr(arr []int) {
	for i, v := range arr {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

var (
	n, m int
	a    []int
	b    map[int]map[int]int
)

type Item struct {
	cost int
	node int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].cost < pq[j].cost
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func solve() {
	minCosts := make([]int, n)
	for i := 0; i < n; i++ {
		minCosts[i] = int(math.Inf(1))
	}

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	item1 := Item{
		cost: a[0],
		node: 0,
	}
	heap.Push(&pq, &item1)
	for true {
		if pq.Len() == 0 {
			break
		}

		item := heap.Pop(&pq).(*Item)
		node := item.node
		cost := item.cost

		if minCosts[node] < cost {
			continue
		}

		minCosts[node] = cost

		for nextNode, nextCost := range b[node] {
			nextItem := Item{
				cost: cost + nextCost + a[nextNode],
				node: nextNode,
			}
			heap.Push(&pq, &nextItem)
		}
	}
	output_arr(minCosts[1:])
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	b = make(map[int]map[int]int)

	sc.Split(bufio.ScanWords)
	n, m = nextInt(), nextInt()
	for i := 0; i < n; i++ {
		a = append(a, nextInt())
	}
	for i := 0; i < m; i++ {
		f, t, c := nextInt()-1, nextInt()-1, nextInt()
		if _, ok := b[f]; !ok {
			b[f] = make(map[int]int)
		}
		b[f][t] = c
	}
	solve()
}
