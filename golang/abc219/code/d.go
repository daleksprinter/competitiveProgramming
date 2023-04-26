package main

import (
	"fmt"
	"math"
)

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
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

var (
	n    int
	x, y int
	arra []int
	arrb []int
	memo [300][310][310]int
)

func dp(i int, sumx int, sumy int) int {
	if sumx >= x && sumy >= y {
		return 0
	}

	if i == n {
		return 100000
	}

	if memo[i][sumx][sumy] > -1 {
		return memo[i][sumx][sumy]
	}
	ans := 10000
	ans = min(ans, dp(i+1, sumx, sumy))
	ans = min(ans, 1+dp(i+1, min(x, sumx+arra[i]), min(y, sumy+arrb[i])))
	memo[i][sumx][sumy] = ans
	return ans
}

func main() {
	n = input()
	x = input()
	y = input()
	for i := 0; i < n; i++ {
		a := input()
		b := input()
		arra = append(arra, a)
		arrb = append(arrb, b)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < 310; j++ {
			for k := 0; k < 310; k++ {
				memo[i][j][k] = -1
			}
		}
	}

	ans := dp(0, 0, 0)
	if ans > n {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
	return
}
