package main

import(
    "fmt"
)

func main(){
    src:=[]byte("asd")
    dst :=make([]byte,14)
    var n int
    times:=3
    for i:=0;i<times;i++{
        n+=copy(dst[n:],src)
    }
    fmt.Printf("len:%d,dst:%s\n",n,string(dst))
}
