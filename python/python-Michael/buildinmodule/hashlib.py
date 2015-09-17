# -*- coding: utf-8 -*-

# hashlib: 摘要算法简介
	# Python的hashlib提供了常见的摘要算法，如MD5，SHA1等等
	# 摘要算法又称哈希算法、散列算法。它通过一个函数，把任意长度的数据转换为一个长度固定的数据串（通常用16进制的字符串表示）
	# 摘要算法就是通过摘要函数f()对任意长度的数据data计算出固定长度的摘要digest，目的是为了发现原始数据是否被人篡改过
	# 摘要算法之所以能指出数据是否被篡改过，就是因为摘要函数是一个单向函数，计算f(data)很容易
	# 但通过digest反推data却非常困难。而且，对原始数据做一个bit的修改，都会导致计算出的摘要完全不同

# 以常见的摘要算法MD5为例，计算出一个字符串的MD5值：
import hashlib
md5 = hashlib.md5()
md5.update('how to use md5 in python hashlib?'.encode('utf-8'))
print(md5.hexdigest())

# 如果数据量很大，可以分块多次调用update()，最后计算的结果是一样的：
md5 = hashlib.md5()
md5.update('how to use md5 in '.encode('utf-8'))
md5.update('python hashlib?'.encode('utf-8'))
print(md5.hexdigest())
# MD5是最常见的摘要算法，速度很快，生成结果是固定的128 bit字节，通常用一个32位的16进制字符串表示

import hashlib
sha1 = hashlib.sha1()
sha1.update('how to use sha1 in '.encode('utf-8'))
sha1.update('python hashlib?'.encode('utf-8'))
print(sha1.hexdigest())
# SHA1的结果是160 bit字节，通常用一个40位的16进制字符串表示
# 比SHA1更安全的算法是SHA256和SHA512，不过越安全的算法不仅越慢，而且摘要长度更长

# 有没有可能两个不同的数据通过某个摘要算法得到了相同的摘要？完全有可能
# 任何摘要算法都是把无限多的数据集合映射到一个有限的集合中。这种情况称为碰撞

## 摘要算法应用
	# 任何允许用户登录的网站都会存储用户登录的用户名和口令。如何存储用户名和口令呢？方法是存到数据库表中：
	# 如果以明文保存用户口令，如果数据库泄露，所有用户的口令就落入黑客的手里。此外，网站运维人员是可以访问数据库的，也就是能获取到所有用户的口令
	# 正确的保存口令的方式是不存储用户的明文口令，而是存储用户口令的摘要，比如MD5：
	# 当用户登录时，首先计算用户输入的明文口令的MD5，然后和数据库存储的MD5对比，如果一致，说明口令输入正确，如果不一致，口令肯定错误
	
## 练习
	# 根据用户输入的口令，计算出存储在数据库中的MD5口令：
	# 存储MD5的好处是即使运维人员能访问数据库，也无法获知用户的明文口令

import hashlib
def calc_md5(password):
	md5 = hashlib.md5()
	md5.update(password.encode('utf-8'))
	return md5.hexdigest()

db = {'Alice':'99b1c2188db85afee403b1536010c2c9',
		'Bob':'4aca5a6dad62f1d63f0f96c3ac3d812b',
		'Tom':'c12b0299106d15771f1afc17e5ca14da'}

def login(user, password):
	if cmp(user, 'Alice') == 0:
		if cmp(calc_md5(password), db['Alice']) == 0:
			print('Yes!')
			return True
		else:
			print('Error!')
			return False
	elif cmp(user, 'Bob') == 0:
		if cmp(calc_md5(password), db['Bob']) == 0:
			print('Yes!')
			return True
		else:
			print('Error!')
			return False
	elif cmp(user, 'Tom') == 0:
		if cmp(calc_md5(password), db['Tom']) == 0:
			print('Yes!')
			return True
		else:
			print('Error!')
			return False
	else:
		print('The user does exist!')
		return False
		
# 采用MD5存储口令是否就一定安全呢？也不一定。假设你是一个黑客，已经拿到了存储MD5口令的数据库，如何通过MD5反推用户的明文口令呢？暴力破解费事费力，真正的黑客不会这么干
# 很多用户喜欢用123456，888888，password这些简单的口令，于是，黑客可以事先计算出这些常用口令的MD5值，得到一个反推表
# 黑客根据反推表，查找出用户的密码明文：无需破解，只需要对比数据库的MD5，黑客就获得了使用常用口令的用户账号

## 加盐
# 对于用户来讲，当然不要使用过于简单的口令。但是，我们能否在程序设计上对简单口令加强保护呢？
# 由于常用口令的MD5值很容易被计算出来，所以，要确保存储的用户口令不是那些已经被计算出来的常用口令的MD5
# 这一方法通过对原始口令加一个复杂字符串来实现，俗称“加盐”：
def calc2_md5(password):
    return calc_md5(password + 'the-Salt')
# 经过Salt处理的MD5口令，只要Salt不被黑客知道，即使用户输入简单口令，也很难通过MD5反推明文口令

# 如果有两个用户都使用了相同的简单口令比如123456，在数据库中，将存储两条相同的MD5值，这说明这两个用户的口令是一样的。有没有办法让使用相同口令的用户存储不同的MD5呢？
# 如果假定用户无法修改登录名，就可以通过把登录名作为Salt的一部分来计算MD5，从而实现相同口令的用户也存储不同的MD5

## 练习2
	# 根据用户输入的登录名和口令模拟用户注册，计算更安全的MD5：
db = {}
def register(username, password):
    db[username] = calc_md5(password + username + 'the-Salt')

# 根据修改后的MD5算法实现用户登录的验证：
def login(username, password):
	if cmp(calc_md5(password + username + 'the-Salt'), db[username]) == 0:
		return True
	else:
		return False

## 要注意摘要算法不是加密算法，不能用于加密（因为无法通过摘要反推明文），只能用于防篡改，但是它的单向计算特性决定了可以在不存储明文口令的情况下验证用户口令

# cmp在python3中，被移除了！