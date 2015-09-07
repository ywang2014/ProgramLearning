# -*- coding: utf-8 -*-
import hashlib

db = {}

# calculate the MD5 value
def calc_md5(password):
	md5 = hashlib.md5()
	if not isinstance(password, str):
		raise ValueError
	md5.update(password.encode('utf-8'))
	return md5.hexdigest()
	
# register interface
def register():
	global db
	name = input('Please input the username:')
	password = input('Please input your password:')
	if not isinstance(name, str) or not isinstance(password, str):
		raise ValueError
	password = name + password + 'the-Salt'
	db[name] = calc_md5(password)
	
# login interface
def login():
	global db
	name = input('Please input your username:')
	password = input('Please input your password:')
	if not isinstance(name, str) or not isinstance(password, str):
		raise ValueError
	if calc_md5(name+password+'the-Salt') == db[name]:
		print('Succeed!')
		return True
	else:
		print('Failed!')
		return False
		
# manager function
def manage():
	while True:
		flag = input('Do you want to sign up now? y/n:')
		if flag == 'y' or flag == 'Y':
			register()
		elif flag == 'n' or flag == 'N':
			break
		else:
			print('Your inputs have some wrong!')
			raise ValueError
			
	while True:
		flag = input('Do you want to log in now? y/n:')
		if flag == 'y' or flag == 'Y':
			login()
		elif flag == 'n' or flag == 'N':
			break
		else:
			print('Your inputs have some wrong!')
			raise ValueError
			
# 在python3中，cmp()函数被移除了！
# str1 is str2
# str1 == str2
# cmp(str1, str2)