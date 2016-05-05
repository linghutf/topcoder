/*
测试map
*/
package main

import(
    "fmt"
)

type Encode interface{
    encode(*int) *int
}

func main(){
    m:=make(map[int]*string) //initial
    //m[1]="1234"
    if m[1]==nil{
        fmt.Println("1 not in.")
    }
    s:="hello"
    m[1]=&s
    Print(m)
}

func Print(m map[int]*string){
    var size int = len(m)
    if size==0{
        fmt.Println("assert failed.")
        return
    }
    fmt.Println(*m[1])

    v:=make(map[string]int,4)
    in,ok:=v["data-0.txt"]
    fmt.Printf("%d,%t\n",in,ok)
}
