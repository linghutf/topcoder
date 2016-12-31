#!/usr/bin/env python
# encoding: utf-8

from decimal import *
import math

if __name__ == '__main__':
    d = Decimal(2+math.sqrt(3))
    r = d**80
    s = str(r)
    pos = s.rfind('.')
    print "str:",s,"number:",s[pos-1:pos]
