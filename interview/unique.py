#!/usr/bin/env python
# encoding: utf-8

# 容器内开始有两个不相同的正数
# 每次插入容器内两两元素的差值的一个与容器元素均不相同的值
# 要求容器保持元素惟一
#初始元素:m,n(n>m)
# 最多有n/min(n-m,m)个元素
def adunique(lst):
    d = set()
    num = 0
    tmp = set()
    lastsz = len(lst)
    while True:
        for i in lst:
            for j in lst:
                num = i-j
                if num>0:
                    d.add(num)
        tmp = d-lst
        print '差值:',tmp
        if len(tmp)==0:
            break
        lst.add(max(tmp))
        if len(lst)==lastsz:
            break
        lastsz = len(lst)
        d.clear()
        tmp.clear()

if __name__ == '__main__':
    lst = set()
    from sys import argv
    from sys import exit
    if len(argv)<3:
        print 'usgae: python ',argv[0],' num1 num2.'
        exit(1)
    a = int(argv[1])
    b = int(argv[2])
    lst.add(a)
    lst.add(b)
    adunique(lst)
    print lst
    print 'nums:',len(lst)
