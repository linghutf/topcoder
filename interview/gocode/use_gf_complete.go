package main

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
/*
char* c_strcpy(char *dst,char* src)
{
    return strcpy(dst,src);
}

void c_print(char *s)
{
    printf("%s\n",s);
}
*/
import "C"
import "unsafe"

func main(){
    var cmsg *C.char = C.CString("123")
    //bs:=make([]byte,5)
    lens:=unsafe.Sizeof(cmsg)
    println(lens)
    var bs = C.malloc(10)//(C.malloc((*C.size_t)(unsafe.Pointer(&lens))))
    //var bs  *C.char = *C.char(C.malloc(5))//C.CString("xxdv")//(C.malloc(6))
    C.strcpy((*C.char)(unsafe.Pointer(bs)),cmsg)
    C.c_print((*C.char)(unsafe.Pointer(bs)))

    defer C.free(unsafe.Pointer(cmsg))
    defer C.free(unsafe.Pointer(bs))
}
