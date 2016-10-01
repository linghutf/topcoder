#!/usr/bin/env python
# encoding: utf-8

# 测试socket backlog参数作用

import socket

def server(host,port):
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((host,port))
    #backlog
    s.listen(3)
    while True:
        ss,addr = s.accept()
        print 'get from',addr

if __name__ == '__main__':
    server('127.0.0.1',8090)
