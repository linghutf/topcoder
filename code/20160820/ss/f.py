#!/usr/bin/env python
# encoding: utf-8

rs = 1
for i in xrange(1,1025):
    rs *= i

s=str(rs)
print s
t=s.strip('0')
print t
print len(s)-len(t)
