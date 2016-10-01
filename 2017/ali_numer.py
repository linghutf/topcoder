#!/usr/bin/env python
# encoding: utf-8

# 阿里数字
# 首位为1
# 只有一个数字出现一次
# 四位数


def is_ok(n):
    s = str(n)
    m = set()
    for c in s:
        m.add(c)
    return len(m)==3

def alinum():
    cnt = 0
    for i in xrange(1000,2000):
        if is_ok(i):
            cnt+=1
    return cnt


if __name__=='__main__':
    print alinum()
