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
func min[T int | int64](nums ...T) T {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	minValue := nums[0]
	for _, num := range nums[1:] {
		if num < minValue {
			minValue = num
		}
	}
	return minValue
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

func lowerBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool {
		return arr[i] >= x
	})
}

func upperBound(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool {
		return arr[i] > x
	})
}

type Item struct {
	priority int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
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

// 累積和データ構造 (int64型)
type CumulativeSum struct {
	data   []int64
	prefix []int64
}

// 累積和の初期化（引数なし）
func NewCumulativeSum() *CumulativeSum {
	// 初期化時は空のスライスを設定
	return &CumulativeSum{
		data:   []int64{},
		prefix: []int64{0}, // 最初の prefix[0] は 0 から始める
	}
}

// データを追加し、累積和を効率よく更新
func (cs *CumulativeSum) Add(values ...int64) {
	for _, value := range values {
		cs.data = append(cs.data, value)
		// 直前の累積和に新しい値を足すことで効率よく更新
		lastPrefix := cs.prefix[len(cs.prefix)-1]
		val := (lastPrefix + value + mod) % mod
		cs.prefix = append(cs.prefix, val)
	}
}

// 範囲 [i, j) の累積和を取得
func (cs *CumulativeSum) Query(i, j int) int64 {
	return (cs.prefix[j] - cs.prefix[i] + mod) % mod
}

var (
	n   int
	arr []int64
	mod = int64(998244353)
)

func digitCount[T int | int64](n T) T {
	var count T
	count = 0
	for n > 0 {
		n /= 10
		count++
	}
	return count
}

func modPow(base, exponent, modulus int64) int64 {
	result := int64(1)
	base = base % modulus
	for exponent > 0 {
		if exponent%2 == 1 {
			result = (result * base) % modulus
		}
		exponent = exponent >> 1
		base = (base * base) % modulus
	}
	return result
}
func solve() int64 {
	csraw := NewCumulativeSum()
	for i := 0; i < n; i++ {
		csraw.Add(arr[i])
	}

	csbit := NewCumulativeSum()
	for i := 0; i < n; i++ {
		val := modPow(10, digitCount(arr[i]), mod)
		csbit.Add(val)
	}

	ans := int64(0)
	for i := 0; i < n-1; i++ {
		ans += arr[i]*csbit.Query(i+1, n)%mod + csraw.Query(i+1, n)%mod
		ans %= mod
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
	arr = make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64()
	}

	fmt.Println(solve())
}
