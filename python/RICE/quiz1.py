# -*- coding: utf-8 -*-

# Quiz 1

import random
n = 20
while n > 0:
	print "randint:", random.randint(0, 10)
	print "randrange:", random.randrange(0, 10)
	n = n - 1
	
#  f(x) = -5 x5 + 69 x2 - 47
def fn(x):
	result = -47
	a = x
	for i in range(1, 5):
		a = a * x
		if i == 1:
			result = result + 69 * a
		if i == 4:
			result = result - 5 * a
	return result
	
	
# compound interest:  FV = PV (1+rate)^periods
def future_value(present_value, annual_rate, periods_per_year, years):
	rate_per_period = annual_rate / periods_per_year
	periods = periods_per_year * years
	# put your code here
	rate = 1
	for i in range(0, periods):
		rate = rate * (1 + rate_per_period) 
	return present_value * rate

print "$1000 at 2% compounded daily for 3 years yields $", future_value(1000, .02, 365, 3)

# calculate the area of a regular polygon: 1/4*n*s*s/tan(pie/n)
import math

def areaofregularpolygon(numofsides, length):
	area = 1.0 / 4 * numofsides * length * length / math.tan(math.pi / numofsides)
	return area
	
	
def max_of_2(a, b):
    if a > b:
        return a
    else:
        return b
		
def max_of_3(a, b, c):
	return max_of_2(a, max_of_2(b, c))
	
def project_to_distance(point_x, point_y, distance):
	dist_to_origin = math.sqrt(point_x ** 2 + point_y ** 2)    
	scale = distance / dist_to_origin
	print point_x * scale, point_y * scale
    
project_to_distance(2, 7, 4)

input('pause!')
