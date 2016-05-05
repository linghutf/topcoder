//亿int为主键时的value的顺序
package main

import(
    "fmt"
)

func CopySlicePoint(){
    src:=new([]int)
    *src = make([]int,4)
    (*src)[0]=1
    (*src)[1]=2
    (*src)[2]=3
    (*src)[3]=4

    //复制可行
    dst:=new([]int)
    *dst = make([]int,4)
    //复制前三个
    copy((*dst)[:3],*src)

    for _,v:=range *dst{
        fmt.Println(v)
    }
}

func main(){
    m:=make(map[int]string)
    m[1]="D"
    m[2]="C"
    m[10]="B"
    m[100]="A"

    for _,v:=range m{//顺序不确定
        fmt.Println(v)
    }

    CopySlicePoint()
}
