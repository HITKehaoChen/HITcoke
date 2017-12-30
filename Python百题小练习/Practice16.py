#!/usr/bin/python
# -*- coding: UTF-8 -*-

import datetime

if __name__ == '__main__':
	print(datetime.date.today().strftime('%d/%m/%Y'))
	mybirthdate = datetime.date(1997,9,20)
	print(mybirthdate.strftime('%d/%m/%Y'))

