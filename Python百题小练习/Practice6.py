#!/usr/bin/python
# -*- coding: UTF-8 -*-

#递归方法
def fib(n):
	if n ==1 or n == 2:
		return 1
	return fib(n-1)+fib(n-2)
#普通解法
def fib2(n):
	a,b = 1,1
	for i in range(n-1):
		a,b = b,a+b
	return a

print fib(10)

print fib2(10)