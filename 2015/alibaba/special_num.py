#!/usr/bin/env python
# encoding: utf-8

if __name__ =='__main__':
    cnt=0
    for i in xrange(1000,2000):
        s=str(i)
        li=list(s)
        a=dict()
        for j in li:
            a[j]=1
        if len(a)==3:
            print s
            cnt+=1
    print cnt
