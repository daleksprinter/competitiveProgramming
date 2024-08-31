package main

import (
	"bufio"
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

func nextLine() string {
	sc.Scan()
	return sc.Text()
}

var (
	n       int
	s       string
	t       string
	visited map[string]bool
)

func min(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

func getNextState(state string, i int) string {
	tmp := state[i : i+2]
	ret := state
	ret = strings.Replace(ret, "..", tmp, 1)
	ret = ret[0:i] + ".." + ret[i+2:]
	return ret
}

type Node struct {
	state string
	cost  int
}

var (
	queue []Node
)

func solve() int {
	queue = append(queue, Node{s, 0})
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		if visited[node.state] {
			continue
		}
		visited[node.state] = true

		if node.state[:n] == t {
			return node.cost
		}

		for i := 0; i < n+1; i++ {
			if node.state[i] == '.' || node.state[i+1] == '.' {
				continue
			}
			nextState := getNextState(node.state, i)
			queue = append(queue, Node{nextState, node.cost + 1})
		}
	}
	return -1
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	n = nextInt()
	s = nextLine() + ".."
	t = nextLine()
	visited = make(map[string]bool)
	fmt.Println(solve())
}
