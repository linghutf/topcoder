#!/usr/bin/env python
# encoding: utf-8

def calc_year(base,mons):
    return base * mons

if __name__ == '__main__':
    b = 15879.5
    a = 15327.67
    t = 14962.88
    lst = [b,a,t]
    src = [17000,16000,15500]
    print '百度:',calc_year(b,12)+calc_year(src[0],2.6)
    print '阿里:',calc_year(a,13)+calc_year(src[1],3)
    print '腾讯:',calc_year(t,13)+calc_year(src[2],3)

