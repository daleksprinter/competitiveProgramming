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

func input_int_arr() []int {
	sc.Scan()
	strs := strings.Split(sc.Text(), " ")
	nums := make([]int, len(strs))
	for i, s := range strs {
		nums[i], _ = strconv.Atoi(s)
	}
	return nums
}

func input_str() string {
	sc.Scan()
	return sc.Text()
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
	n   int
	a   string
	arr [200001][3]int
)

func dp(i int, last string) int {
	if i == n {
		return 0
	}
	if arr[i][hand_to_int(last)] > -1 {
		return arr[i][hand_to_int(last)]
	}
	hand := string(a[i])
	ans := 0
	if last == "R" {
		ans = maxint(ans, dp(i+1, "S")+is_win("S", hand), dp(i+1, "P")+is_win("P", hand))
	} else if last == "S" {
		ans = maxint(ans, dp(i+1, "R")+is_win("R", hand), dp(i+1, "P")+is_win("P", hand))
	} else {
		ans = maxint(ans, dp(i+1, "R")+is_win("R", hand), dp(i+1, "S")+is_win("S", hand))
	}
	arr[i][hand_to_int(last)] = ans
	return ans
}

func hand_to_int(hand string) int {
	if hand == "R" {
		return 0
	}
	if hand == "S" {
		return 1
	}
	return 2
}

func is_win(hand1, hand2 string) int {
	if hand1 == "R" && hand2 == "S" {
		return 1
	}
	if hand1 == "S" && hand2 == "P" {
		return 1
	}
	if hand1 == "P" && hand2 == "R" {
		return 1
	}
	if hand1 == hand2 {
		return 0
	}
	return -999999999
}

func solve() int {
	return dp(0, "")
}

func main() {

	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)

	n = input()
	a = input_str()
	for i := 0; i < 200001; i++ {
		for j := 0; j < 3; j++ {
			arr[i][j] = -1
		}
	}

	fmt.Println(maxint(0, solve()))
}
