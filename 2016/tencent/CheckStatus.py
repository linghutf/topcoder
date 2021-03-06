#!/usr/bin/env python
# encoding: utf-8

# 面试状态查询
# person-file:
# 姓名 身份证后4位   手机号
# 张三 1234          13112345678
# usage: python file.py person-file

import requests
import threading
import signal
import sys
from functools import partial
import time
from bs4 import BeautifulSoup as bs


class Person(object):
    def __init__(self,name,idcard,phone):
        self.idcard = idcard
        self.phone = phone
        self.name = name
        self.status = ''

    def setStatus(self,result):
        self.status = result

    def getStatus(self):
        return self.status

    def __str__(self):
        return "%s %s %s\n%s" %(self.name,self.idcard,self.phone,self.getStatus())

    def __repr__(self):
        return "%s %s %s\n%s" %(self.name,self.idcard,self.phone,self.getStatus())

    def query(self,url='http://m.join.qq.com/query/result'):
        post_data = {'type':'query_result','idcard':'','phone':''}
        post_data['idcard'] = self.idcard
        post_data['phone'] = self.phone
        user_agent = {"User-Agent":"Mozilla/5.0 (iPhone; CPU iPhone OS 5_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Mobile/9B176 MicroMessenger/4.3.2"}

        r = requests.request('POST',url=url,headers=user_agent,data=post_data)

        #r.encoding = 'gb2313' #微信已经改为utf-8编码
        soup = bs(r.text,'lxml')
        print soup.get_text()
        node = soup.select('.school')[0]# .query-result')
        self.setStatus(node.get_text())


def parse(linestr):
    li=linestr.split()
    return Person(li[0],li[1],li[2])

# 读取配置文件
def read_config(filename):
    fp = open(filename,'r')
    persons = []
    try:
        line = fp.readline()
        while line:
            persons.append(parse(line))
            line = fp.readline()
    finally:
        fp.close()
    return persons

def map_task(person,timespan):
    cnt = 0
    while True:
        cnt+=1
        person.query()
        print('*'*16,cnt,'*'*16)
        s = time.strftime("%F %T",time.localtime())
        print("%s\n%s" %(s,person))
        time.sleep(timespan)

# listen Quit signal
def signal_handler(threads,signal,frame):
    print("本次查询退出...")
    for t in threads:
        t.alive = False
    sys.exit(0)

class thread(threading.Thread):
    def __init__(self,target,args):
        threading.Thread.__init__(self)
        self.alive = True
        self.target = target
        self.args = args
        #self.stop = args[-1] # stop event

    def run(self):
        while self.alive:
            self.target(*self.args)


if __name__ == '__main__':
    t = 60 # 60s

    if len(sys.argv)<2:
        print('usage:%s persons-file.' %(sys.argv[0]))
        sys.exit(1)
    filename = sys.argv[1]
    #读取用户列表
    persons = read_config(filename)
    # 多线程运行
    ths = []
    for i in persons:
        ths.append(thread(target=map_task,args=(i,t,)))
        #ths.append(threading.Thread(target=map_task,args=(i,t,)))

    for t in ths:
        t.start()

    signal.signal(signal.SIGINT,partial(signal_handler,ths))
    '''
    for i in ths:
        i.join()
    '''
    while True:
        pass
