package main

import (
	"fmt"
)

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

var (
	n    int
	arr  []int
	memo [100000][10][10]int
)

func dp(i int, m int, k int) int {
	if i == n-1 {
		if k == m {
			return 1
		} else {
			return 0
		}
	}

	if memo[i][m][k] > -1 {
		return memo[i][m][k]
	}

	plus := (m + arr[i+1]) % 10
	multi := (m * arr[i+1]) % 10
	ans := (dp(i+1, plus, k) + dp(i+1, multi, k)) % 998244353
	memo[i][m][k] = ans
	return ans
}

func main() {
	n = input()
	for i := 0; i < n; i++ {
		arr = append(arr, input())
	}

	for i := 0; i < 100000; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				memo[i][j][k] = -1
			}
		}
	}
	for i := 0; i < 10; i++ {
		fmt.Println(dp(0, arr[0], i))
	}
}
