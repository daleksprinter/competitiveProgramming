package main

import (
	"fmt"
	"sort"
)

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

type Coordinate struct {
	x int
	y int
}

var (
	n   int
	arr []Coordinate
	mp  map[Coordinate]bool
)

func main() {
	n = input()
	mp = make(map[Coordinate]bool)
	for i := 0; i < n; i++ {
		x := input()
		y := input()
		arr = append(arr, Coordinate{x, y})
		mp[Coordinate{x, y}] = true
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i].x < arr[j].x && arr[i].y < arr[j].y
	})

	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if arr[i].x < arr[j].x && arr[i].y < arr[j].y {
				a := Coordinate{arr[i].x, arr[j].y}
				b := Coordinate{arr[j].x, arr[i].y}
				if mp[a] && mp[b] {
					ans++
				}
			}

		}
	}
	fmt.Println(ans)
	return
}
