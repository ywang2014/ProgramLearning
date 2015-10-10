# -*- coding: utf-8 -*-

# convert xx.yy to xx dollars and yy cents
def convert_1(val):
	dollars = int(val)
	cents = int(100 * (val - dollars))
	return str(dollars) + " dollars and " + str(cents) + " cents"
	
# Tests
print convert_1(11.20)
print convert_1(11.23)
print convert_1(1.12)
print convert_1(12.01)
print convert_1(1.01)
print convert_1(1.00)
print convert_1(0)
print convert_1(0.00)

# Handle single quantity
def convert_units(val, name):
	if val > 1:
		return str(val) + " " + name + "s"
	return str(val) + " " + name

# convert xx.yy to xx dollars and yy cents
def convert(val):
	# Split into dollars and cents
	dollars = int(val)
	cents = int(round(100 * (val - dollars)))
	# Convert to string
	dollars_string = convert_units(dollars, "dollar")
	cents_string = convert_units(cents, "cent")
	
	#return composite string
	if dollars == 0 and cents == 0:
		return "Broke!"
	elif dollars == 0:
		return cents_string
	elif cents == 0:
		return dollars_string
	else:
		return dollars_string + " and " + cents_string
		

# Tests
print convert(11.20)
print convert(11.23)
print convert(1.12)
print convert(12.01)
print convert(1.01)
print convert(1.00)
print convert(0)
print convert(0.00)

input("pause!")