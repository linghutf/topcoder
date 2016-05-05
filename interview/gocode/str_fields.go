package main

import(
    "strings"
    "fmt"
)

func main(){
    str :="1\n2\n 3\n4";
    ss:=strings.Fields(str)
    fmt.Printf("%+v\n",ss)
}
