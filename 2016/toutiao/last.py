#!/usr/bin/env python
# encoding: utf-8

def cond(x,k):
    if k<=0:
        return -1
    s = set()
    for y in range(1,3*x):
        if (x+y)==(x|y):
            s.add(y)
    n = k if k<len(s) else len(s)
    lst = list(s)
    lst = sorted(lst)
    print(lst)
    return lst[n-1]

if __name__ == '__main__':
    x = int(input('x='))
    k = int(input('k='))

    y = cond(x,k)

    print("%d %d %s %s\n" %(~x,y,bin(~x),bin(y)))
