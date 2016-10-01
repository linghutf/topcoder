#!/usr/bin/env python
# encoding: utf-8

# 从100-999的等腰三角形个数

import math

def is_ok(a,b):
    v = b/2.0/a
    if (v-1.00)>1e-5:
        return False

    seta = math.asin(v)*2
    return seta>1e-5 and math.pi-seta>1e-5

def is_sanjiao(a,b):
    cnt = 0
    for i in xrange(a,b):
        for j in xrange(a,b):
            if is_ok(i,j):
                cnt+=1
    return cnt

if __name__ == '__main__':
    print is_sanjiao(100,1000)
