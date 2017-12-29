#!/usr/bin/python
# -*- coding: UTF-8 -*- 

l = []
for i in range(101,200):
	for j in range(2,i-1):
		if i % j == 0:
			break
	else:
		l.append(i)


print l 

print '总数为：%d' %len(l)