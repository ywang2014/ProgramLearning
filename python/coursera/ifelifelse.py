# -*- coding: utf-8 -*-

# if elif else

def greet(friend, money):
	if friend and (money > 2500):
		print('Hi!')
		money = money - 1000
	elif friend
		print('Hello')
	else :
		print('Ha, ha')
		money = money + 1000
	return money

money = 2000
money = greet(True, money)
print("Money: ", money)
print("")

money = greet(False, money)
print("Money: ", money)
print("")

money = greet(True, money)
print("Money: ", money)
print("")


def is_leep_year(year):
	if (year % 400) == 0:
		return True
	elif (year % 100) == 0:
		return True
	elif (year % 4) == 0:
		return True
	else :
		return False
		
year = 2015
leapYear = is_leap_year(year)

if leapYear:
	print('Yes, it is leap year!')
else :
	print('No, it is not leap year!')

	
	