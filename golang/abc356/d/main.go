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
func min(nums ...int64) int64 {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int64(math.Min(float64(res), float64(nums[i])))
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

func max[T int | int64](nums ...T) T {
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

func nextInt64() int64 {
	sc.Scan()
	i, e := strconv.ParseInt(sc.Text(), 10, 64)
	if e != nil {
		panic(e)
	}
	return i
}

var (
	n, m int64

	mod = int64(998244353)
)

func cntpops(index int, last int64) int64 {
	cnt := last + 1
	cycle := int64(1) << (index)
	cyclecnt := cnt / cycle
	remain := cnt % cycle
	a := (cycle / 2) * cyclecnt
	b := max(0, remain-(cycle/2))
	return a + b
}

func solve() int64 {
	popcounts := make([]int64, 70)
	for i := 1; i < 62; i++ {
		popcounts[i] = cntpops(i, n)
	}
	ans := int64(0)
	for i := 1; i < 62; i++ {
		if m&(1<<(i-1)) != 0 {
			ans += popcounts[i] % mod
		}
	}
	return ans % mod
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	n = nextInt64()
	m = nextInt64()
	fmt.Println(solve())

}
