#!/bin/bash

# 测试epoll连接

host=127.0.0.1
port=9527

for i in {1..10};do
    telnet $host $port
    echo "$i"
    sleep 0.01
done
