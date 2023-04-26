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

func eratothenes(n int, p []int) []int {
	var isPrime []bool
	for i := 0; i < n+1; i++ {
		isPrime = append(isPrime, true)
	}
	for _, v := range p {
		for i := 1; i*v < n+1; i++ {
			isPrime[i*v] = false
		}
	}
	var primes []int
	for i := 1; i < n+1; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	return primes
}

func prime_factor(n int) map[int]int {
	prime_counts := make(map[int]int)
	tmp := n
	for i := 2; i*i <= tmp; i++ {
		for n%i == 0 {
			prime_counts[i]++
			n /= i
		}
	}
	if n != 1 {
		prime_counts[n]++
	}
	return prime_counts
}

var (
	arr []int
)

func main() {
	n, m := input(), input()
	for i := 0; i < n; i++ {
		arr = append(arr, input())
	}
	sort.Ints(arr)
	mp := make(map[int]bool)
	for _, v := range arr {
		primes := prime_factor(v)
		for k, _ := range primes {
			mp[k] = true
		}
	}

	var t []int
	for k, _ := range mp {
		t = append(t, k)
	}
	primes := eratothenes(m, t)

	fmt.Println(len(primes))
	for _, v := range primes {
		fmt.Println(v)
	}
	return
}
