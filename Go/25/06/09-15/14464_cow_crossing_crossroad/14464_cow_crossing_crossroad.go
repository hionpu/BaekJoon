package main

import (
	"fmt"
)

type Pii struct {
	s int
	e int
}

func main() {
	var C, N int
	fmt.Scan(&C, &N)

	ch := make([]int, C)

	for i := 0; i < C; {
		fmt.Scan(ch[i])
	}

	cow := make([]Pii, N)

	for i:=0;i<N; {
		fmt.Scan(cow[i].s)
		fmt.Scan(cow[i].e)
	}

	



}
