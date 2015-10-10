### String Processing

# String literals
str1 = "Rixner's funny"
str2 = 'Warren wears nice ties!'
str3 = " t-shirts!"

print str1, str2
print str3

# Combining strings
str4 = ' and '
str5 = "Warren" + str4 + "Rixner" + ' are nuts!'
print str4

# Characters and slices
print str1[0], str1[3], str1[6]
print len(str1)
print str1[0:6] + str2[6:]
print str2[:13] + str1[9:] + str3

#Converting strings
str6 = str(375)
print str6
il = int(str6[1:])
print il + 1

input("pause!")
