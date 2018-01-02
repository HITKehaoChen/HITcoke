#!/usr/bin/python
# -*- coding: UTF-8 -*-

for a in ['x','y','z']:
    for b in ['x','y','z']:
        for c in ['x','y','z']:
            if (a!=b)and(b!=c)and(c!=a)and (a!='x')and(c!='x')and(c!='z'):
                print 'a和%s比赛，b和%s比赛，c和%s比赛' %(a,b,c)