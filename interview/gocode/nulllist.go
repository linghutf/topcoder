package main

import(
    "container/list"
    "fmt"
)

func main(){
    bs:=[]byte{1,2,3,4}
    n:=2
    per:=2
    lst:=list.New()
    for i:=0;i<n;i++{
        lst.PushBack(bs[i*per:(i+1)*per])
    }
    //可以添加空slice
    lst.PushBack(bs[n*per:])
    bs=nil
    for e:=lst.Front();e!=nil;e=e.Next(){
        p:=e.Value.([]byte)
        fmt.Printf("[%d]%v\n",len(p),p)
    }
}
