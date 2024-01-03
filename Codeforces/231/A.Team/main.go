package main
import (
	"fmt"
)
func main() {
	var n int
	fmt.Scanln(&n)
	var cn int = 0
	var a,b,c int
	for (n>0){
		fmt.Scan(&a)
		fmt.Scan(&b)
		fmt.Scan(&c)
		if a+b+c > 1 {
			cn++
		}
		n--
	}
	fmt.Println(cn)
}