package main

import(
    "fmt"
    "os/user"
)

func main(){
    gUser,gErr:=user.Current()
    if gErr!=nil{
        fmt.Println(gErr)
        return
    }

    fmt.Println(gUser.HomeDir)
    s:=[]rune("中国")
    v:=s
    d:=make([]rune,len(s))
    copy(d,s)
    s[1]='s'
    fmt.Printf("%s %s %s\n",string(s),string(v),string(d))
}
