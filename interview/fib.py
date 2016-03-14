#!/usr/bin/env python
# encoding: utf-8

#x=[1,1,0]
def fib(n):
    if n<=2:
        return 1
    a=b=1
    c=0
    for i in xrange(2,n):
        c=a+b
        a,b=b,c
    return c

print fib(int(raw_input()))
