#!/usr/bin/env python
# encoding: utf-8

# 根据字典序还是长度排序

def is_less_len(a,b):
    return len(a)<len(b)

def is_less_chr(a,b):
    pass

if __name__ == '__main__':
    a=["a",'aaab','bbb']
    sorted(a)
    print a
    sorted(a,cmp=is_less_len)
    print a
