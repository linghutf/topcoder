#!/usr/bin/env python
# encoding: utf-8

import math
import copy
#相似度计算
#余弦公式cos(seta) = a*b/|a||b|

def cos_seta(factora,factorb):
    a = copy.copy(factora)
    b = copy.copy(factorb)
    lena = len(a)
    lenb = len(b)
    lens = lena
    #lens = lena if lena>lenb else lenb
    #print lens
    if lena>lenb:
        #lens = lena
        for i in xrange(lena-lenb):
            b.append(0)
    elif lena<lenb:
        lens = lenb
        for i in xrange(lenb-lena):
            a.append(0)
    #print 'a:',a,',b:',b
    actor = 0
    suma,sumb = 0,0
    for i in xrange(lens):
        actor+=a[i]*b[i]
        suma+=a[i]*a[i]
        sumb+=b[i]*b[i]
    return actor/math.sqrt(suma*sumb)

if __name__ == '__main__':
    a = [1,2]
    b = [3,4,5]
    print a,b,' 相似度:',cos_seta(a,b)
    a.append(-1)
    print a,b,' 相似度:',cos_seta(a,b)
