#!/usr/bin/env python
# encoding: utf-8

import sys

# 最长回文子串

def longest_polindrome(s):
    len_s = len(s)
    if len_s==0:
        return ''
    new_s = pre_process(s)
    len_n,idx,mx=len(new_s),0,0
    p = [0 for i in xrange(len_n)]

    for i in xrange(1,len_n-1):
        p[i] = min(p[2*idx-i],mx-i) if mx > i else 1

        while new_s[i+p[i]] == new_s[i-p[i]]:
            p[i]+=1
        if i+p[i]>mx:
            mx = i+p[i]
            idx = i

    max_len,index=0,0
    for i in xrange(1,len_n-1):
        if p[i]>max_len:
            max_len = p[i]
            index = i
    start = (index-max_len)/2
    end = start+max_len
    return s[start:end]


# 预处理字符串
def pre_process(s):
    ns = '^'+s
    for i in s:
        ns+=i+'#'
    ns+='$'
    return ns


if __name__ == '__main__':
    print longest_polindrome(sys.argv[1])
