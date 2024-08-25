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
func maxint(nums ...int) int {
	if len(nums) == 0 {
		panic("max: no values provided")
	}
	maxValue := nums[0]
	for _, num := range nums[1:] {
		if num > maxValue {
			maxValue = num
		}
	}
	return maxValue
}

var (
	n, k int
	p, c []int
)

func solve() int {
	ans := int(math.Inf(-1))
	for i := 0; i < n; i++ {
		cycleScore := 0
		cycleCnt := 0
		current := i
		for true {
			cycleCnt++
			cycleScore += c[current]
			current = p[current]
			if current == i {
				break
			}
		}

		pathScore := 0
		current = i
		num := 0
		for true {
			num++
			pathScore += c[current]
			cycl := (k - num) / cycleCnt
			scoreSum := pathScore + maxint(0, cycleScore)*cycl
			ans = maxint(ans, scoreSum)
			current = p[current]
			if current == i {
				break
			}
		}
	}
	return ans
}

func main() {
	initialBufSize := 10000
	maxBufSize := 1_000_000_000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)

	n, k = input(), input()
	p = input_arr()
	c = input_arr()

	for i := 0; i < n; i++ {
		p[i]--
	}

	fmt.Println(solve())
}
