package main

import "fmt"

func input() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}

func main() {
	i := input()
	fmt.Println(i)
	return
}
