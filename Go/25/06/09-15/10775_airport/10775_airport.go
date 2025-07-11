package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type DS struct {
	parent []int
	rank   []int
}

func NewDS(n int) *DS {
	parent := make([]int, n+1)
	rank := make([]int, n+1)
	
	for i := 0; i <= n; i++ {
		parent[i] = i
		rank[i] = 0
	}
	
	return &DS{
		parent: parent,
		rank:   rank,
	}
}

func (ds *DS) getParent(n int) int {
	if ds.parent[n] == n {
		return n
	}
	ds.parent[n] = ds.getParent(ds.parent[n])
	return ds.parent[n]
}

func (ds *DS) join(a, b int) {
	ds.parent[ds.getParent(a)] = ds.getParent(b)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read G
	scanner.Scan()
	G, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))
	
	// Read P
	scanner.Scan()
	P, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))
	
	ds := NewDS(G)
	ans := P
	
	for i := 1; i <= P; i++ {
		scanner.Scan()
		p, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))
		
		available := ds.getParent(p)
		
		if available == 0 {
			ans = i - 1
			break
		}
		
		ds.join(available, available-1)
	}
	
	fmt.Println(ans)
}