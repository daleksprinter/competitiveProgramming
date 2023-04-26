package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Range struct {
	from int
	to   int
}

const (
	initialBufSize = 1e4
	maxBufSize     = 1e6 + 7
)

func init() {
	sc.Split(bufio.ScanWords)
	sc.Buffer(buf, maxBufSize)
}

var buf []byte = make([]byte, initialBufSize)
var sc = bufio.NewScanner(os.Stdin)
var (
	n   int
	arr []Range
)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	n = nextInt()
	mp := map[int]bool{}
	for i := 0; i < n; i++ {
		a, b := nextInt(), nextInt()
		b = a + b
		arr = append(arr, Range{a, b})
		mp[a] = true
		mp[b] = true
	}
	var tmp []int
	for k, _ := range mp {
		tmp = append(tmp, k)
	}
	sort.Ints(tmp)
	coordmap := make(map[int]int)
	revmap := make(map[int]int)
	l := len(tmp)
	for i := 0; i < l; i++ {
		coordmap[tmp[i]] = i
		revmap[i] = tmp[i]
	}
	for i := 0; i < n; i++ {
		arr[i].from = coordmap[arr[i].from]
		arr[i].to = coordmap[arr[i].to]
	}
	var imos []int
	var ans []int
	for i := 0; i < n*2; i++ {
		imos = append(imos, 0)
		ans = append(ans, 0)
	}
	for i := 0; i < n; i++ {
		frm := arr[i].from
		to := arr[i].to
		imos[frm]++
		imos[to]--
	}

	l = len(imos)
	for i := 1; i < l; i++ {
		imos[i] = imos[i-1] + imos[i]
	}
	for i, v := range imos {
		ans[v] += revmap[i+1] - revmap[i]
	}
	for i := 1; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
	fmt.Println(ans[n])
	return
}
