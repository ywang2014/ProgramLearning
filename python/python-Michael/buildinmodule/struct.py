# -*- coding: utf-8 -*-

# struct: 
	# struct模块: 解决bytes和其他二进制数据类型的转换
	
# 在Python中，比方说要把一个32位无符号整数变成字节，也就是4个长度的bytes，你得配合位运算符这么写：
n = 10240099
b1 = (n & 0xff000000) >> 24
b2 = (n & 0xff0000) >> 16
b3 = (n & 0xff00) >> 8
b4 = n & 0xff
bs = bytes([b1, b2, b3, b4])
print(bs)	# b'\x00\x9c@c'

# struct的pack函数把任意数据类型变成bytes：
import struct 
struct.pack('>I', 10240099)
# 输出 b'\x00\x9c@c'
# pack的第一个参数是处理指令，'>I'的意思是：
	# >表示字节顺序是big-endian，也就是网络序（网络传输通常使用Big-endian：高地址存高位(左低右高)），I表示4字节无符号整数
	# 后面的参数个数要和处理指令一致

# unpack把bytes变成相应的数据类型：
struct.unpack('>IH', b'\xf0\xf0\xf0\xf0\x80\x80')	# (4042322160, 32896)
# 根据>IH的说明，后面的bytes依次变为I：4字节无符号整数和H：2字节无符号整数
# 官方文档：https://docs.python.org/3/library/struct.html#format-characters

# Windows的位图文件（.bmp）是一种非常简单的文件格式，我们来用struct分析一下
# 读入前30个字节来分析：
 s = b'\x42\x4d\x38\x8c\x0a\x00\x00\x00\x00\x00\x36\x00\x00\x00\x28\x00\x00\x00\x80\x02\x00\x00\x68\x01\x00\x00\x01\x00\x18\x00'
 # BMP格式采用小端方式存储数据，文件头的结构按顺序如下：
	# 两个字节：'BM'表示Windows位图，'BA'表示OS/2位图；
	# 一个4字节整数：表示位图大小；
	# 一个4字节整数：保留位，始终为0；
	# 一个4字节整数：实际图像的偏移量；
	# 一个4字节整数：Header的字节数；
	# 一个4字节整数：图像宽度；
	# 一个4字节整数：图像高度；
	# 一个2字节整数：始终为1；
	# 一个2字节整数：颜色数
struct.unpack('<ccIIIIIIHH', s)
# (b'B', b'M', 691256, 0, 54, 40, 640, 360, 1, 24)
# 结果显示，b'B'、b'M'说明是Windows位图，位图大小为640x360，颜色数为24


## 练习
	# 请编写一个bmpinfo.py，可以检查任意文件是否是位图文件，如果是，打印出图片大小和颜色数
import struct
def bmpinfo(filename):	# 使用re对文件名进行解析
	with open(filename, 'rb') as fp:
		header = fp.read(30)
		info = struct.unpack('<ccIIIIIIHH', head)
		if info[0] == b'B' and info[1] == b'M':
			print('Windows BMP! Size: %s * %s. Color: %s' % (info[6], info[7], info[9]))
		elif info[0] == b'B' and info[1] == b'A':
			print('OS/2 BMP! Size: %s * %s. Color: %s' % (info[6], info[7], info[9]))
		else:
			print("It is not BMP!")
			
if (__name__ == '__main__'):
	bmpinfo('test.bmp')
	