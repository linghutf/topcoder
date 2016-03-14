
def FirstAppearByNTimes(lst,times):
    d=dict()
    for i in lst:
        if d.has_key(i):
            d[i]+=1
        else:
            d[i]=1
        for k in d.keys():
            if d[k]==times:
                return k
            return None

if __name__ == '__main__':
    #print 'hello'
    times = int(raw_input())
    nums = int(raw_input())
    a=raw_input()
    lst=[int(i) for i in a.split()]
    print(FirstAppearByNTimes(lst,times))
