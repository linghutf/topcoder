#!/usr/bin/env python
# encoding: utf-8

def _permutate(prefix,lst):
    print ''.join(prefix)+''.join(lst)
    lens = len(lst)
    if lens<=1:
        return
    lst[0],lst[-1] = lst[-1],lst[0]
    print ''.join(prefix)+''.join(lst)
    lst[-1],lst[0] = lst[0],lst[-1]
    prefix.append(lst[0])
    lst=lst[1:]
    _permutate(prefix,lst)

def permutation(s):
    pre = list('')
    lst = list(s)
    _permutate(pre,lst)

if __name__=='__main__':
    s='ABC'
    permutation(s)
