#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 linghutf <linghutf@pc>
#
# Distributed under terms of the MIT license.

if __name__=='__main__':
    s=0
    for i in xrange(1,10000):
        for j in xrange(1,i+1):
            if i%j==0:
                s+=i
    print s
