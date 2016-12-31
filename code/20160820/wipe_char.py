#!/usr/bin/env python
# encoding: utf-8

import sys

# 消除字符,消除最多等分最高

# 相邻是否有相同的字符
# 使用列表操作
def has_same_str(strs):
    for i in xrange(len(strs)-1):
        if strs[i] == strs[i+1]:
            return True
    return False

# 消除字符操作
# 使用列表操作
def wipe(strs):
    if len(strs)==0:
        return
    vlist=[]
    tmp=[]
    lens = len(strs)
    for i in strs:
        vlist.append(True)

    for i in xrange(lens-1):
        if strs[i]==strs[i+1]:
            vlist[i]=vlist[i+1]=False
    for i in xrange(lens):
        if vlist[i]:
            tmp.append(strs[i])
    return tmp

# 递归消除字符,返回得分
def wipe_all(strs):
    score=0
    while has_same_str(strs):
        tmp=wipe(strs)
        score+=len(strs)-len(tmp)
        strs=tmp
    return score,strs

# 尝试插入一个字符['A','B','C']
def try_insert(strs):
    cs='ABC'
    max_score = 0
    score = -1
    # 改进方法
    # 先存储到set中,因为有一些是一样的
    tot = set()
    for c in cs:
        for i in xrange(len(strs)+1):
            my_str = list(strs)
            my_str.insert(i,c) # 插入字符
            tot.add(''.join(my_str))

    for s in tot:
        score,t = wipe_all(list(s))
        if max_score<score:
            max_score = score
    return max_score

def handle_input():
    n = int(raw_input())
    ss=[]
    for i in xrange(n):
        # 没有错误处理,非法字符
        ss.append(str.upper(raw_input()))
    for i in xrange(n):
        print try_insert(ss[i])

if __name__ == '__main__':
    #s = sys.argv[1]
    #print try_insert(s)
    handle_input()
