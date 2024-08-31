package main

import (
	"bufio"
	"fmt"
	"math"
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

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func nextInt64() int64 {
	sc.Scan()
	i, e := strconv.ParseInt(sc.Text(), 10, 64)
	if e != nil {
		panic(e)
	}
	return i
}

var (
	n int
	t int
	s string
	x []int
)

func nextLine() string {
	sc.Scan()
	return sc.Text()
}

// lower_bound関数の実装
func upperBound(v []int, tgt int) (idx, val int) {
	if tgt >= v[len(v)-1] {
		return len(v), 1 << 60
	} else if tgt < v[0] {
		return 0, v[0]
	} else {
		bottom, top := 0, len(v)
		for {
			if top-bottom == 1 {
				break
			}
			middle := (bottom + top) / 2
			if v[middle] > tgt {
				top = middle
			} else {
				bottom = middle
			}
		}
		return top, v[top]
	}
}

func lowerBound(v []int, tgt int) (idx, val int) {
	if tgt > v[len(v)-1] {
		return len(v), 1 << 60
	} else if tgt <= v[0] {
		return 0, v[0]
	} else {
		bottom, top := 0, len(v)
		for {
			if top-bottom == 1 {
				break
			}
			middle := (bottom + top) / 2
			if v[middle] >= tgt {
				top = middle
			} else {
				bottom = middle
			}
		}
		return top, v[top]
	}
}

func solve() int {
	var plus []int
	var minus []int

	for i := 0; i < n; i++ {
		if s[i] == '1' {
			plus = append(plus, (x[i]))
		} else {
			minus = append(minus, (x[i]))
		}
	}

	sort.Slice(plus, func(i, j int) bool {
		return plus[i] < plus[j]
	})
	sort.Slice(minus, func(i, j int) bool {
		return minus[i] < minus[j]
	})
	ans := 0
	for i := 0; i < len(plus); i++ {
		pos := plus[i]
		left, _ := lowerBound(minus, pos)
		right, _ := upperBound(minus, pos+2*t)
		ans += right - left
	}
	return ans
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	n = nextInt()
	t = nextInt()
	s = nextLine()
	for i := 0; i < n; i++ {
		x = append(x, nextInt())
	}
	fmt.Println(solve())
}
