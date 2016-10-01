#!/usr/bin/env python
# encoding: utf-8

import sys

# 阶乘末尾的0的个数
# 寻找5的个数

def num_of_five(n):
    cnt = 0
    while n%5==0:
        cnt+=1
        n/=5
    return cnt

def tail_zero_num(bound):
    cnt = 0
    for i in xrange(2,bound+1):
        cnt += num_of_five(i)
    return cnt


if __name__ == '__main__':
    n = int(sys.argv[1])
    print tail_zero_num(n)
