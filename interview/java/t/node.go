package t

type T struct{
    Id int
}

func(self *T)Add(n int){
    self.Id+=n
}

func Sub(a,b int) int{
    return a-b
}
