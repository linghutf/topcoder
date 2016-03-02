#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 linghutf <linghutf@pc>
#
# Distributed under terms of the MIT license.
import copy

#
#简单方法:A拿走2瓶葡萄酒，还剩2瓶葡萄酒和1瓶啤酒，
#B拿走的葡萄酒是A的两倍，则可以确定4瓶葡萄酒总共是3x，是3的倍数
#
def three(a):
    for i in xrange(0,len(a)):
        b=copy.copy(a)
        del b[i]
        if sum(b)%3==0:
            print a[i]

def func():
    a=[30,32,36,36,40,62]
    lens=6
    for i in xrange(0,lens):
        for j in xrange(i+1,lens):
            if j==lens:
                continue
        #print "[%d,%d]" %(i,j),
        s1 = a[i]+a[j]
        b = copy.copy(a)
        del b[i],b[j-1]#删除i位置后,j位置前移1位
        s2=sum(b)
        d=s2-s1*2
        #剩下的是啤酒
        if d in a:
            print "%d+%d=%d ," %(a[i],a[j],s1),b,s2,d

if __name__ == '__main__':
    a=[30,32,36,36,40,62]
    three(a)
