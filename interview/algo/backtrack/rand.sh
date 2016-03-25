#!/bin/bash

function rand(){
    min=$2
    max=$($3-$min+1)
    num=$(cat /dev/urandom | head -n 10 | cksum | awk -F ' ' '{print $1}')
    echo $($num%$max+%min)
}

md=$(rand $2 $3)
echo $md
exit:0
