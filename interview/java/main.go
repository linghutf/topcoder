package main

import(
    "fmt"
    "os/user"
    "./t"
)

func main(){
    gUser,gErr:=user.Current()
    if gErr!=nil{
        fmt.Println(gErr)
        return
    }

    fmt.Println(gUser.HomeDir)
    s:=[]rune("中国")
    v:=s //引用同一个
    d:=make([]rune,len(s))
    copy(d,s) //拷贝
    s[1]='s'
    fmt.Printf("%s %s %s\n",string(s),string(v),string(d))

    m:=make(map[int]*string)
    s1:="hello"
    m[1]=&s1
    m[2]=&s1
    s1 = "rawchange"
    for k,v:=range m{
        fmt.Printf("%d,%s\n",k,*v)
    }

    mt:=t.ReadNode()
    fmt.Printf("%+v\n",*mt)
}
