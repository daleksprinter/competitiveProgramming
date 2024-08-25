package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

var (
	n, q int
	a    []int
)

// lower_bound関数の実装
func lowerBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool {
		return arr[i] >= x
	})
}

// upper_bound関数の実装
func upperBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool {
		return arr[i] > x
	})
}

func isbig(mid, b, k int) bool {
	l := lowerBound(a, b-mid)
	r := upperBound(a, b+mid)
	return r-l >= k
}

func solve(b, k int) int {
	l, r := -1, 10000000000
	var mid int
	for r-l > 1 {
		mid = (l + r) / 2
		if isbig(mid, b, k) {
			r = mid
		} else {
			l = mid
		}
	}
	return l
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	n, q = nextInt(), nextInt()
	for i := 0; i < n; i++ {
		a = append(a, nextInt())
	}
	sort.Ints(a)
	for i := 0; i < q; i++ {
		b, k := nextInt(), nextInt()
		fmt.Println(solve(b, k) + 1)
	}
}
