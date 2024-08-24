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

type permuteTable struct {
	table [][]int
}

func newPermuteTable(n int) *permuteTable {
	p := make([][]int, 60)
	for lv := 0; lv < 60; lv++ {
		p[lv] = make([]int, n+1)
	}
	return &permuteTable{table: p}
}

func (p *permuteTable) build(n int, x []int) {
	for i := 1; i <= n; i++ {
		p.table[0][i] = x[i-1]
	}
	for lv := 1; lv < 60; lv++ {
		for j := 1; j <= n; j++ {
			p.table[lv][j] = p.table[lv-1][p.table[lv-1][j]]
		}
	}
}

func (p *permuteTable) get(lv int) []int {
	return p.table[lv]
}

func solve(n int, k int, x []int, a []int) (ans []int) {
	pt := newPermuteTable(n)
	pt.build(n, x)

	arr := make([]int, n+1)
	for i := 1; i <= n; i++ {
		arr[i] = i
	}
	for lv := 0; lv < 60; lv++ {
		tbl := pt.get(lv)
		if k%2 == 1 {
			for i := 1; i <= n; i++ {
				arr[i] = tbl[arr[i]]
			}
		}
		k /= 2
	}

	ans = make([]int, n+1)
	for i := 1; i <= n; i++ {
		ans[i] = a[arr[i]-1]
	}
	return ans[1 : n+1]

}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)

	n, k := input(), input()
	x := input_arr()
	a := input_arr()

	output_arr(solve(n, k, x, a))
}
