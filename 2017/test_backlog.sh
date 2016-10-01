#!/bin/bash
HOST='localhost'
PORT=8090
for i in {0..5};do
    telnet $HOST $PORT &
    echo "$i done."
done
