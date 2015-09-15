# -*- coding: utf-8 -*-

# SMTP send email

	# SMTP是发送邮件的协议，Python内置对SMTP的支持，可以发送纯文本邮件、HTML邮件以及带附件的邮件
	# Python对SMTP支持有smtplib和email两个模块，email负责构造邮件，smtplib负责发送邮件
	
# 1.构造一个最简单的纯文本邮件：
from email.mime.text import MIMEText
msg = MIMEText('hello, send by Python...', 'plain', 'utf-8');
	# 构造MIMEText对象时
		# 第一个参数就是邮件正文
		# 第二个参数是MIME的subtype，传入'plain'表示纯文本，最终的MIME就是'text/plain'
		# 最后一定要用utf-8编码保证多语言兼容性
# 2.通过SMTP发送出去
# 输入Email地址和口令
from_addr = input('From: ')
password = input('Password: ')
# 输入收件人的地址
to_addr = input('To: ')
# 输入SMTP服务器地址
smtp_server = input('SMTP Server: ')

import smtplib 
server = smtplib.SMTP(smtp_server, 25)	# SMTP协议默认端口号是 25
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()

# set_debuglevel(1)就可以打印出和SMTP服务器交互的所有信息
# SMTP协议就是简单的文本命令和响应
# login()方法用来登录SMTP服务器
# sendmail()方法就是发邮件，由于可以一次发给多个人，所以传入一个list，邮件正文是一个str，as_string()把MIMEText对象变成str

# 完整的邮件：
	# 邮件主题、如何显示发件人、收件人等信息并不是通过SMTP协议发给MTA
	# 而是包含在发给MTA的文本中的，所以，我们必须把From、To和Subject添加到MIMEText中。
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from emial.utils import parseaddr, formataddr

import stmplib

def _format_addr(s):
	name, addr = parseaddr(s)
	return formataddr((Header(name, 'utf-8').encode(), addr))
	
from_addr = input("From: ")
password = input('Password: ')
to_addr = input('To: ')
smtp_server = input('SMTP server: ')

msg = MIMEText('hello, send by Python...', 'plain', 'utf-8')
msg['From'] = _format_addr('Python爱好者 <%s>' % from_addr)
msg['To'] = _format_addr('管理员 <%s>' % to_addr)
msg['Subject'] = Header('来自SMTP的问候...', 'utf-8').encode()

server = smtplib.SMTP(smtp_server, 25)
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()

# _format_addr()来格式化一个邮件地址
# 注意不能简单地传入name <addr@example.com>，因为如果包含中文，需要通过Header对象进行编码
# msg['To']接收的是字符串而不是list，如果有多个邮件地址，用,分隔即可

# 你看到的收件人的名字很可能不是我们传入的管理员，因为很多邮件服务商在显示邮件时，会把收件人名字自动替换为用户注册的名字，但是其他收件人名字的显示不受影响


## 发送HTML邮件