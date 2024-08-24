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

	sc.Scan()                             // １行分の入力を取得する
	strs := strings.Split(sc.Text(), " ") // 半角スペース区切りでstring型として配列inputsに格納
	nums := make([]int, len(strs))
	for i, s := range strs {
		nums[i], _ = strconv.Atoi(s) // エラーハンドリング省略
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

func main() {

	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	n, k := input(), input()
	x := input_arr()

	p := make([][]int, 60)
	for i := 0; i < 60; i++ {
		p[i] = make([]int, n+1)
	}
	for i := 1; i <= n; i++ {
		p[0][i] = x[i-1]
	}
	for lv := 1; lv < 60; lv++ {
		for j := 1; j <= n; j++ {
			p[lv][j] = p[lv-1][p[lv-1][j]]
		}
	}
	arr := make([]int, n+1)
	for i := 1; i <= n; i++ {
		arr[i] = i
	}
	for lv := 0; lv < 60; lv++ {
		if k%2 == 1 {
			for i := 1; i <= n; i++ {
				arr[i] = p[lv][arr[i]]
			}
		}
		k /= 2
	}

	ans := make([]int, n+1)

	a := input_arr()
	for i := 1; i <= n; i++ {
		ans[i] = a[arr[i]-1]
	}
	output_arr(ans[1 : n+1])

}
