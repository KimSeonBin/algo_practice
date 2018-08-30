package main

import (
	"fmt"
)

func howdiv(x int) int {
	var divv int = 1
	for i := 0; true; i++ {
		if x/divv == 0 {
			break
		}
		divv *= 10
	}
	return divv
}

func main() {
	var t, n, npow, div int
	fmt.Scanf("%d\n", &t)
	for i := 0; i < t; i++ {
		fmt.Scanf("%d\n", &n)
		npow = n * n
		div = howdiv(n)
		if n == (npow % div) {
			fmt.Printf("YES\n")
		} else {
			fmt.Printf("NO\n")
		}
	}
}
