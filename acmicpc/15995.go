package main

import "fmt"

func main() {
	var a, m int = 1, 2
	fmt.Scanf("%d %d", &a, &m)

	for i := 1; i <= m; i++ {
		if a*i%m == 1 {
			fmt.Printf("%d\n", i)
			break
		}
	}
}
