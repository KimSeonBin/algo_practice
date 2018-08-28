package main

import (
	"fmt"
	"sort"
)

type student struct {
	nation, num, score int
}

type students []student

func (s students) Len() int {
	return len(s)
}

func (s students) Less(i, j int) bool {
	return s[i].score < s[j].score
}

func (s students) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func main() {
	var n, doublemodel int
	var doublemodelnation [200]int
	fmt.Scanf("%d\n", &n)

	var stu students
	for i := 0; i < n; i++ {
		var temp student
		fmt.Scanf("%d %d %d\n", &temp.nation, &temp.num, &temp.score)
		stu = append(stu, temp)
	}
	sort.Sort(stu)

	for i := n - 1; i >= 0; i-- {
		var check bool = false
		for j := 0; j < 3; j++ {
			if doublemodelnation[stu[i].nation] > 1 {
				check = true
				break
			}
		}

		if check == false {
			fmt.Printf("%d %d\n", stu[i].nation, stu[i].num)
			doublemodelnation[stu[i].nation]++
			doublemodel++
			if doublemodel == 3 {
				break
			}
		}
	}
}
