# -*- coding: utf-8 -*-

# text content
from email.mime.text import MIMEText
message = MIMEText('Hello boy, send by Python...', 'plain', 'utf-8')
# args[0]邮件正文内容，args[1]邮件类型：plain代表纯文本，args[2]编码方式：utf-8保证语言兼容性

# send by SMTP
from_addr = input('Your Email: ')	
# qq/sina邮箱可以成功发送，163/126邮箱不能发送：smtplib.SMTPHeloError: (500, b'Error: bad syntax')
password = input('Your password: ')
to_addr = input('To: ')
smtp_server = input('SMTP server: ') 
# smtp.xxx.com qq/sina/163/...

import smtplib
server = smtplib.SMTP(smtp_server, 25)
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], message.as_string())
server.quit()

# test
def test():
	from email.mime.text import MIMEText
	message = MIMEText('Hello boy, send by Python...', 'plain', 'utf-8')
	# args[0]邮件正文内容，args[1]邮件类型：plain代表纯文本，args[2]编码方式：utf-8保证语言兼容性

	# send by SMTP
	from_addr = input('Your Email: ')
	password = input('Your password: ')
	to_addr = input('To: ')
	smtp_server = input('SMTP server: ')

	import smtplib
	server = smtplib.SMTP(smtp_server, 25)
	server.set_debuglevel(1)
	server.login(from_addr, password)
	server.sendmail(from_addr, [to_addr], message.as_string())
	server.quit()

# test2
def test2():
	from email import encoders
	from email.header import Header
	from email.mime.text import MIMEText
	from email.utils import parseaddr, formataddr
	import getpass

	import smtplib

	def _format_addr(s):
		name, addr = parseaddr(s)
		return formataddr((Header(name, 'utf-8').encode(), addr))

	from_addr = input('From: ')
	password = getpass.getpass('Password: ')
	to_addr = input('To: ')
	smtp_server = input('SMTP server: ')

	msg = MIMEText('hello, send by Python...', 'plain', 'utf-8')
	msg['From'] = _format_addr('Python爱好者 <%s>' % from_addr)
	msg['To'] = _format_addr('管理员 <%s>' % to_addr)
	msg['Subject'] = Header('来自SMTP的问候……', 'utf-8').encode()

	server = smtplib.SMTP(smtp_server, 25)
	server.set_debuglevel(1)
	server.login(from_addr, password)
	server.sendmail(from_addr, [to_addr], msg.as_string())
	server.quit()

# test3
def test3():
	import smtplib
	from_mail='ywangsh2011@126.com'
	to_mail='ywangsh2011@163.com'
	server=smtplib.SMTP('smtp.126.com')
	server.docmd('ehlo','ywangsh2011@126.com')
	server.login('ywangsh2011@126.com','************')
	msg='''from:xxx@126.com
	to:yyy@qq.com
	subject:I am guol
	I'm come 126
	.
	'''
	server.sendmail(from_mail,to_mail,msg)
	server.quit()

def test4():
	import smtplib
	from email.mime.text import MIMEText
	from email.header import Header

	sender = "发件人邮箱"
	receiver = "收件人邮箱"
	subject = "测试邮件"
	smtpserver = "smtp.exmail.qq.com"
	username = '1071512072@qq.com'
	password = '*****************'

	msg = MIMEText('你好','text','utf-8')
	msg['Subject'] = Header(subject,'utf-8')

	smtp = smtplib.SMTP()
	smtp.connect('smtp.qq.com')
	smtp.login(username,password)
	smtp.sendmail(sender,receiver,msg.as_string())
	smtp.quit()
	
	// 编码格式不对？？？
	
# test5
def test5():
	from email.header import Header
	from email.mime.text import MIMEText
	from email.mime.multipart import MIMEMultipart
	import smtplib, datetime
	msg =  MIMEText('你好','text','utf-8')
	msg['to'] = '844398850@qq.com'
	msg['from'] = '348632061@qq.com'
	msg['subject'] = Header('testABC (' + str(datetime.date.today()) + ')','gb2312')
	server = smtplib.SMTP('smtp.qq.com')
	server.starttls()
	server.login('1071512072@qq.com','**************')
	error=server.sendmail(msg['from'], msg['to'], msg.as_string())
	server.close()
	print(error)