package main

import(
    "fmt"
)

func main(){
    s:="123"
    bs:=make([]byte,3)
    copy(bs,s)
    fmt.Printf("%s\n",bs)
}
