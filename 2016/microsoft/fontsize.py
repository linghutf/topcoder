
import math
import random

def isGreater(w,h,s,p,_sum):
    return w/s*h/s*p>=_sum

def solve(w,h,p,_sum):
    s=int(math.ceil(math.sqrt(w*h*p*1.0/_sum)))
    for i in xrange(s+10,1,-1):
        if isGreater(w,h,i,p,_sum):
            return i
    return 1

def rand(down,up):
    n = random.randint(down,up)
    if n<0:
        n=-n
    return n

def check(w,h,s,p,_sum):
    m = w/s*h/s
    print "w(%4d),h(%4d),s(%4d),p(%4d),sum(%4d),%4d * %4d -> %4d>%4d" %(w,h,s,p,_sum,w/s,h/s,m,_sum/p)

def test():
    n = rand(1,100)
    lst = []
    for i in xrange(n):
        lst.append(rand(1,100))
    _sum=sum(lst)
    h = rand(1,100)
    w = rand(1,100)
    p = rand(1,20)

    s = solve(w,h,p,_sum)
    check(w,h,s,p,_sum)

def input():
    n = int(raw_input())
    p = int(raw_input())
    w = int(raw_input())
    h = int(raw_input())
    lst=[]
    for i in xrange(n):
        lst.append(int(raw_input()))

    s = solve(w,h,p,sum(lst))

    print 'result:%4d' %(s)

if __name__ == '__main__':
    times = 100
    for i in xrange(times):
        test()

    #input()
