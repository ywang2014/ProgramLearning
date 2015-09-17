# -*- coding: utf-8 -*-

# StringIO 内存中读写str

# 写
	# 要把str写入StringIO，我们需要先创建一个StringIO，然后，像文件一样写入即可：
from io import StringIO 
f = StringIO()
f.write('hello')	# 返回读入字符数，5
f.write(' ')
f.write('world!')
print(f.getvalue())	# hello world
# getvalue()方法用于获得写入后的str

# 读
	# 读取StringIO，可以用一个str初始化StringIO，然后，像读文件一样读取：
from io import StringIO
f = StringIO('Hello!\nHi!\nGoodbye!')
while True:
	s = f.readline()
	if s == '':
		break
	print(s.strip())
	

# BytesIO 操作二进制数据
	# BytesIO实现了在内存中读写bytes，我们创建一个BytesIO，然后写入一些bytes：

# 写
from io import BytesIO
f = BytesIO()
f.write('中文'.encode('utf-8'))	# 返回值 6
# 请注意，写入的不是str，而是经过UTF-8编码的bytes
print(f.getvalue())

# 读 
from io import StringIO
f = BytesIO(b'\xe4\xb8\xad\xe6\x96\x87')
f.read()

## StringIO和BytesIO是在内存中操作str和bytes的方法，使得和读写文件具有一致的接口

