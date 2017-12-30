#!/usr/bin/python
# -*- coding: utf-8 -*-
num = int(input('input the number:'))
def fenjie(num):
    strf = '{}='.format(num)
    flag = True
    while flag:
        for i in range(2,num+1):
            if not num%i:
                if i==num:
                    flag = False
                    strf = strf + str(i)
                else:
                    strf = strf + str(i) + '*'
                    num = num//i
                break
    return strf
print(fenjie(num))