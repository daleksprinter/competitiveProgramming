package main

import (
	"bufio"
	"fmt"
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

type Bridge struct {
	From int
	To   int
}

var (
	n, k    int
	bridges map[int][]int

	v       map[int]bool
	visited map[int]bool
)

func dfs(current int) int {
	if visited[current] {
		return 0
	}
	visited[current] = true

	child_cost := 0
	for _, next := range bridges[current] {
		child_cost += dfs(next)
	}

	current_node_cost := 0
	if _, ok := v[current]; ok || child_cost > 0 {
		current_node_cost = 1
	}

	overall_cost := current_node_cost + child_cost
	return overall_cost
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	n = nextInt()
	k = nextInt()
	bridges = make(map[int][]int)
	for i := 0; i < n-1; i++ {
		f, t := nextInt()-1, nextInt()-1
		if _, ok := bridges[f]; !ok {
			bridges[f] = []int{}
		}
		bridges[f] = append(bridges[f], t)
		if _, ok := bridges[t]; !ok {
			bridges[t] = []int{}
		}
		bridges[t] = append(bridges[t], f)
	}
	v = make(map[int]bool)
	start := 0
	for i := 0; i < k; i++ {
		val := nextInt() - 1
		v[val] = true
		start = val
	}
	visited = make(map[int]bool)
	fmt.Println(dfs(start))
}
