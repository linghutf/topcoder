package t

import(
    "testing"
)

func Test_Sub(t *testing.T){
    a,b:=10,15
    c:=Sub(a,b)
    if c!=-5{
        t.Error("sub error")
    }
}
