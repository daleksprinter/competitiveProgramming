package main

import "fmt"

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

var (
	n, m int
	arr  [][]int
)

func main() {
	n = input()
	m = input()
	for i := 0; i < m; i++ {
		k := input()
		var tmp []int
		for j := 0; j < k; j++ {
			a := input()
			tmp = append(tmp, a)
		}
		arr = append(arr, tmp)
	}
	i := 0 //pointer of tube
	mp := make(map[int]bool)
	finish := 0
	for len(mp) < m && finish < m+1 {
		if len(mp) == 0 {
			finish++
		}
		if len(arr[i]) != 0 {
			p := arr[i][0]
			if mp[p] {
				delete(mp, p)
			} else {
				mp[p] = true
			}
			arr[i] = arr[i][1:]
		}
		i = (i + 1) % m
	}
	if len(mp) == m {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
	return
}
