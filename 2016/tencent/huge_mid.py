import random

def rand():
    lst=[]
    up = 2<<32-1
    down = 0
    for i in xrange(1000):
        lst.append(random.randint(down,up))
    return lst


