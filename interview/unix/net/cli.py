#!/usr/bin/env python3
# encoding: utf-8

import socket

def connect(host,port):
    fd = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    fd.connect((host,port))
    while True:
        msg = input()
        if msg.strip() == 'bye':
            break
        fd.sendall(msg)
        data = fd.recv(1024)
        print(data)
    fd.close()

if __name__ == '__main__':
    connect("0.0.0.0",8001)
