package main

import (
	"bufio"
	"errors"
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

var (
	n int64
	m int64
)

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

func digitCountByString(n int64) int {
	return len(strconv.FormatInt(n, 10))
}

// modInverse calculates the modular inverse of a under modulo m
// using the extended Euclidean algorithm.
func modInverse(a, m int64) (int64, error) {
	g, x, _ := extendedGCD(a, m)
	if g != 1 {
		return 0, errors.New("modular inverse does not exist")
	}
	// Ensure x is positive
	return (x%m + m) % m, nil
}

// extendedGCD calculates the greatest common divisor of a and b
// as well as the coefficients x and y for which a*x + b*y = gcd(a, b)
func extendedGCD(a, b int64) (int64, int64, int64) {
	if a == 0 {
		return b, 0, 1
	}
	gcd, x1, y1 := extendedGCD(b%a, a)
	x := y1 - (b/a)*x1
	y := x1
	return gcd, x, y
}

func mod(n, m int64) int64 {
	return (n%m + m) % m
}

func PowerOfTenInt(k int) int64 {
	return mod(int64(math.Pow10(k)), m)
}

func modDiff(a, b, m int64) int64 {
	diff := (a - b) % m
	if diff < 0 {
		diff += m
	}
	return diff
}

func modMulti(modulus int64, numbers ...int64) int64 {
	result := int64(1)
	for _, number := range numbers {
		result = (result * number) % modulus
	}
	return result
}

func main() {
	initialBufSize := 10000
	maxBufSize := 100000000
	buf := make([]byte, initialBufSize)
	sc.Buffer(buf, maxBufSize)
	sc.Split(bufio.ScanWords)

	m = int64(998244353)
	n = nextInt64()

	k := digitCountByString(n) // k = digit count of n

	modinv, _ := modInverse(modDiff(PowerOfTenInt(k), 1, m), m)            // mod inverse of 10^k-1
	_10pown := modPow(int64(10), n, m)                                     // 10^n
	_10pownk := modPow(_10pown, int64(k), m)                               // 10^(n*k)
	sum := modMulti(m, mod(n, m), modinv, mod(modDiff(_10pownk, 1, m), m)) // n * modinv(10^k-1) * 10^n^k - 1
	fmt.Println(mod(sum, m))
}
