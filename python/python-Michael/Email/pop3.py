# coding: utf-8

# POP3 收取邮件
	# SMTP用于发送邮件
	# 收取邮件最常用的协议是POP协议，目前版本号是3，俗称POP3
	
	# Python内置一个poplib模块，实现了POP3协议，可以直接用来收邮件
	
	## 注意到POP3协议收取的不是一个已经可以阅读的邮件本身，而是邮件的原始文本，这和SMTP协议很像，SMTP发送的也是经过编码后的一大段文本
	
	# 要把POP3收取的文本变成可以阅读的邮件，还需要用email模块提供的各种类来解析原始文本，变成可阅读的邮件对象。
		# 收取邮件分两步：
			# 1.用poplib把邮件的原始文本下载到本地
			# 2.用email解析原始文本，还原为邮件对象
			
# 通过POP3下载邮件
import poplib
from email.parser import Parser

# 输入邮件地址，口令，pop3服务器地址
email = input('Email: ')
password = input('Password: ')
pop3_server = input('POP3 server: ')

# 连接到POP3服务器
server = poplib.POP3(pop3_server)
# 可以打开或关闭调试信息
server.set_debuglevel(1)
# 可选 打印POP3服务器的欢迎文字
print(server.getwelcome().decode('utf-8'))

# 身份认证
server.user(email)
server.pass_(password)

# stat()返回邮件数量和占用空间
print('Message: $s. Size: %s' % server.stat())
# list()返回所有邮件编号
resp, mails, octets = server.list()
# 可以查看返回的列表类似[b'1 82923', b'', ...]
print(mails);

# 获取最新一封邮件，注意索引从1开始
index = len(mails)
resp, lines, octets = server.retr(index)

# lines存储邮件的原始文本的每一行
# 可以获得整个邮件的原始文本
msg_content = b'\r\n'.join(lines).decode('utf-8')
# 稍后解析出邮件
msg = Parser().parsestr(msg_content)	# 使用了Parser

# 可以根据邮件索引直接从服务器删除邮件
# server.dele(index)
# 关闭连接
server.quit()

# 用POP3获取邮件其实很简单，要获取所有邮件，只需要循环使用retr()把每一封邮件内容拿到即可
# 真正麻烦的是把邮件的原始内容解析为可以阅读的邮件对象

### 解析邮件
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr
import poplib

# 只需要一行代码就可以把邮件内容解析为Message对象：
msg = Parser().parsestr(mag_content)

# 但是这个Message对象本身可能是一个MIMEMultipart对象，即包含嵌套的其他MIMEBase对象，嵌套可能还不止一层
# 递归地打印出Message对象的层次结构：

# indent 用于缩进显示
def print_info(msg, indent = 0):
	if indent = 0:
		for header in ['From', 'To', 'Subject']:
			value = msg.get(header, '')
			if value:
				if header == 'Subject':
					value = decode_str(value)
				else :
					hdr, addr = parseaddr(value)
					name = decode_str(hdr)
					value = u'%s <%s>' % (name, addr)
			print('%s%s: %s' % (' ' * index, header, value))
		
	if (msg.is_multipart()):
		parts = msg.get_payload()
		for n, part in enumerate(parts):
			print('%spart %s' % ('  ' * indent, n))
			print('%s--------------------' % ('  ' * indent))
			print_info(part, indent + 1)
			
	else:
		content_type = msg.get_content_type()
		if content_type == 'text/plain' or content_type == 'text/html':
			content = msg.get_payload(decode = True)
			charset = guess_charset(msg)
			if charset:
				content = content.decode(charset)
			print('%sText: %s' % (' ' * indent, content + '...'))
		else :
			print('%sAttachment: %s' % (' ' * indent, content_type))
			

# 邮件的Subject或者Email中包含的名字都是经过编码后的str，要正常显示，就必须decode：
def decode_strt(s):
	value, charset = decode_header(s)[0]
	if charset:
		value = value.decode(charset)
	return value
	
# decode_header()返回一个list，因为像Cc、Bcc这样的字段可能包含多个邮件地址，所以解析出来的会有多个元素
# 上面的代码，只取了第一个元素

# 文本邮件的内容也是str，还需要检测编码，否则，非UTF-8编码的邮件都无法正常显示：
def guess_charset(msg):
	charset = msg.get_charset()
	if charset in None；
		content_type = msg.get('Content-Type', '').lower()
		pos = content_type.find('charset=')
		if pos >= 0:
			charset = content_type[pos + 8:].strip()
	return charset
	
	
	
################## Michael
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr

import poplib

# 输入邮件地址, 口令和POP3服务器地址:
email = input('Email: ')
password = input('Password: ')
pop3_server = input('POP3 server: ')

def guess_charset(msg):
    charset = msg.get_charset()
    if charset is None:
        content_type = msg.get('Content-Type', '').lower()
        pos = content_type.find('charset=')
        if pos >= 0:
            charset = content_type[pos + 8:].strip()
    return charset

def decode_str(s):
    value, charset = decode_header(s)[0]
    if charset:
        value = value.decode(charset)
    return value

def print_info(msg, indent=0):
    if indent == 0:
        for header in ['From', 'To', 'Subject']:
            value = msg.get(header, '')
            if value:
                if header=='Subject':
                    value = decode_str(value)
                else:
                    hdr, addr = parseaddr(value)
                    name = decode_str(hdr)
                    value = u'%s <%s>' % (name, addr)
            print('%s%s: %s' % ('  ' * indent, header, value))
    if (msg.is_multipart()):
        parts = msg.get_payload()
        for n, part in enumerate(parts):
            print('%spart %s' % ('  ' * indent, n))
            print('%s--------------------' % ('  ' * indent))
            print_info(part, indent + 1)
    else:
        content_type = msg.get_content_type()
        if content_type=='text/plain' or content_type=='text/html':
            content = msg.get_payload(decode=True)
            charset = guess_charset(msg)
            if charset:
                content = content.decode(charset)
            print('%sText: %s' % ('  ' * indent, content + '...'))
        else:
            print('%sAttachment: %s' % ('  ' * indent, content_type))

# 连接到POP3服务器:
server = poplib.POP3(pop3_server)
# 可以打开或关闭调试信息:
server.set_debuglevel(1)
# 可选:打印POP3服务器的欢迎文字:
print(server.getwelcome().decode('utf-8'))
# 身份认证:
server.user(email)
server.pass_(password)
# stat()返回邮件数量和占用空间:
print('Messages: %s. Size: %s' % server.stat())
# list()返回所有邮件的编号:
resp, mails, octets = server.list()
# 可以查看返回的列表类似[b'1 82923', b'2 2184', ...]
print(mails)
# 获取最新一封邮件, 注意索引号从1开始:
index = len(mails)
resp, lines, octets = server.retr(index)
# lines存储了邮件的原始文本的每一行,
# 可以获得整个邮件的原始文本:
msg_content = b'\r\n'.join(lines).decode('utf-8')
# 稍后解析出邮件:
msg = Parser().parsestr(msg_content)
print_info(msg)
# 可以根据邮件索引号直接从服务器删除邮件:
# server.dele(index)
# 关闭连接:
server.quit()

			
			
			
			
			
			
			
			
			
			
			
			
	
