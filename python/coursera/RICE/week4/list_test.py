# Fun with lists

# Create
mt_list = []
print mt_list

l = [1, 3, 5, -7, -9]
print l

l2 = ['milk', 'eggs', 'bread', 'butter']
print l2

l3 = [[3, 4], ['a', 'b', 'c'], []]
print l3

# Access
print len(mt_list), len(l), len(l2), len(l3)

print "First element: ", l[0]
print "Last element: ", l[-1]
print l3[1]

l4 = l2[1:3]
print l4

# Update
l2[0] = 'cheese'
print l2

input("pause!")