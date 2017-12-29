#!/usr/bin/python
# -*- coding: UTF-8 -*-
def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
print fib(36)

f1 = 1
f2 = 1
for i in range(1,36):
    print '%12ld %12ld' % (f1,f2),
    if (i % 3) == 0:
        print ''
    f1 = f1 + f2
    f2 = f1 + f2



