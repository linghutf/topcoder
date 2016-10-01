#!/usr/bin/env python
# encoding: utf-8

import sys

# 最长公共序列

# 打印函数
def print_mat(a):
    rows = len(a)
    cols = len(a[0])
    for i in a:
        for j in i:
            print "%2d" % (j,),
        print


def LCS(s,t):
    len_s = len(s)
    len_t = len(t)

    a=[]
    # 初始化
    for i in xrange(len_s+1):
        a.append([0 for j in xrange(len_t+1)])
    # 计算LCS
    for i in xrange(1,len_s+1):
        for j in xrange(1,len_t+1):
            if s[i-1] == t[j-1]:
                a[i][j] = a[i-1][j-1]+1
            else:
                a[i][j] = max(a[i-1][j],a[i][j-1])
    # 寻找斜向上的符合点
    result = []
    for i in xrange(len_s,0,-1):
        for j in xrange(len_t,0,-1):
            if a[i][j] == a[i-1][j-1]+1 and a[i-1][j]==a[i][j-1]:
                result.append(s[i-1])
                break
    result.reverse()
    return result


if __name__ == '__main__':
    s='abcdaf'
    t='acbcf'
    print LCS(s,t)
