# -*- coding: utf-8 -*-

# 实现发送电子邮件
from email.mime.text import MIMEText
from email.header import Header
from email import encoders
from email.utils import parseaddr, formataddr
import smtplib

def _format_addr(s):
	name, addr = parseaddr(s)
	return formataddr((Header(name, 'utf-8').encode(), addr))
	
username = input('Your Email: ')
password = input('Password: ')

# 输入收件人，循环实现输入多个收件人！
to_addr = []
while True:
	print('Plese input the To_email address: q: Exit')
	addr = input()
	if addr == 'q':
		break
	to_addr.append(addr)
	
if not to_addr:
	# 没有收件人，则发送给自己
	to_addr.append(username)

# 简单的自识别服务器，复杂的不能识别
s = username.split('@')
# smtp_server = 'smtp.'.join(s[1])  join()是把'smtp.'拼接到s[1]中！！！！
smtp_server = 'smtp.' + s[1]
# print(smtp_server)

content = input('Content: ')
message = MIMEText(content, 'plain', 'utf-8')

message['From'] = _format_addr('Dear friend <%s>' % username)
message['To'] = _format_addr('Old friend <%s>' % to_addr[0])
message['Subject'] = Header('Greet: 来自好朋友的诚挚问候...', 'utf-8').encode()

server = smtplib.SMTP(smtp_server, 25)
server.set_debuglevel(1)
server.login(username, password)
server.sendmail(username, to_addr, message.as_string())
server.quit()


# 文本邮件
def text_email():
	from email.mime.text import MIMEText
	from email.header import Header
	from email import encoders
	from email.utils import parseaddr, formataddr
	import smtplib

	def _format_addr(s):
		name, addr = parseaddr(s)
		return formataddr((Header(name, 'utf-8').encode(), addr))
	
	username = input('Your Email: ')
	password = input('Password: ')

	# 输入收件人，循环实现输入多个收件人！
	to_addr = []
	while True:
		print('Plese input the To_email address: q: Exit')
		addr = input()
		if addr == 'q':
			break
		to_addr.append(addr)
	
	if not to_addr:
		# 没有收件人，则发送给自己
		to_addr.append(username)

	# 简单的自识别服务器，复杂的不能识别
	s = username.split('@')
	# smtp_server = 'smtp.'.join(s[1])  join()是把'smtp.'拼接到s[1]中！！！！
	smtp_server = 'smtp.' + s[1]
	# print(smtp_server)

	content = input('Content: ')
	message = MIMEText(content, 'plain', 'utf-8')

	message['From'] = _format_addr('Dear friend <%s>' % username)
	message['To'] = _format_addr('Old friend <%s>' % to_addr[0])
	message['Subject'] = Header('Greet: 来自好朋友的诚挚问候...', 'utf-8').encode()

	server = smtplib.SMTP(smtp_server, 25)
	server.set_debuglevel(1)
	server.login(username, password)
	server.sendmail(username, to_addr, message.as_string())
	server.quit()
	
	
# HTML 邮件
def html_email():
	from email.mime.text import MIMEText
	from email.header import Header
	from email import encoders
	from email.utils import parseaddr, formataddr
	import smtplib

	def _format_addr(s):
		name, addr = parseaddr(s)
		return formataddr((Header(name, 'utf-8').encode(), addr))
	
	username = input('Your Email: ')
	password = input('Password: ')

	# 输入收件人，循环实现输入多个收件人！
	to_addr = []
	while True:
		print('Plese input the To_email address: q: Exit')
		addr = input()
		if addr == 'q':
			break
		to_addr.append(addr)
	
	if not to_addr:
		# 没有收件人，则发送给自己
		to_addr.append(username)

	# 简单的自识别服务器，复杂的不能识别
	s = username.split('@')
	# smtp_server = 'smtp.'.join(s[1])  join()是把'smtp.'拼接到s[1]中！！！！
	smtp_server = 'smtp.' + s[1]
	# print(smtp_server)

	################################# 修改的地方 ########################################
	#content = input('Content: ')
	message = MIMEText('<html> <body> <h1> Hello Boys and girls </h1>' +
						'<p> Send by <a href = "http://www.python.org"> Python </a> ... </p>' + 
						'<p color = "blue"> Long time no see, I miss you! </p>' +
						'</body> </html>', 'html', 'utf-8')
	################################# END ########################################

	message['From'] = _format_addr('Dear friend <%s>' % username)
	message['To'] = _format_addr('Old friend <%s>' % to_addr[0])
	message['Subject'] = Header('Greet: 来自好朋友的诚挚问候...', 'utf-8').encode()

	server = smtplib.SMTP(smtp_server, 25)
	server.set_debuglevel(1)
	server.login(username, password)
	server.sendmail(username, to_addr, message.as_string())
	server.quit()
	

# 有附加文件的邮件
def annex_email():
	from email.mime.text import MIMEText
	from email.header import Header
	from email import encoders
	from email.utils import parseaddr, formataddr
	import smtplib

	def _format_addr(s):
		name, addr = parseaddr(s)
		return formataddr((Header(name, 'utf-8').encode(), addr))
	
	username = input('Your Email: ')
	password = input('Password: ')

	# 输入收件人，循环实现输入多个收件人！
	to_addr = []
	while True:
		print('Plese input the To_email address: q: Exit')
		addr = input()
		if addr == 'q':
			break
		to_addr.append(addr)
	
	if not to_addr:
		# 没有收件人，则发送给自己
		to_addr.append(username)

	# 简单的自识别服务器，复杂的不能识别
	s = username.split('@')
	# smtp_server = 'smtp.'.join(s[1])  join()是把'smtp.'拼接到s[1]中！！！！
	smtp_server = 'smtp.' + s[1]
	# print(smtp_server)

	################################# 修改的地方 ########################################
	# 带附件的邮件可以看做包含若干部分的邮件：文本和各个附件本身
	# 可以构造一个MIMEMultipart对象代表邮件本身
	# 然后往里面加上一个MIMEText作为邮件正文，再继续往里面加上表示附件的MIMEBase对象即可：
	# 邮件对象:
	message = MIMEMultipart()
	message['From'] = _format_addr('Dear friend <%s>' % username)
	message['To'] = _format_addr('Old friend <%s>' % to_addr[0])
	message['Subject'] = Header('Greet: 来自好朋友的诚挚问候...', 'utf-8').encode()

	# 邮件正文是MIMEText:
	message.attach(MIMEText('send with file...', 'plain', 'utf-8'))

	# 添加附件就是加上一个MIMEBase，从本地读取一个图片:
	with open('/Users/michael/Downloads/test.png', 'rb') as f:
		# 设置附件的MIME和文件名，这里是png类型:
		mime = MIMEBase('image', 'png', filename='test.png')
		# 加上必要的头信息:
		mime.add_header('Content-Disposition', 'attachment', filename='test.png')
		mime.add_header('Content-ID', '<0>')
		mime.add_header('X-Attachment-Id', '0')
		# 把附件的内容读进来:
		mime.set_payload(f.read())
		# 用Base64编码:
		encoders.encode_base64(mime)
		# 添加到MIMEMultipart:
		message.attach(mime)
	################################# END ########################################

	server = smtplib.SMTP(smtp_server, 25)
	server.set_debuglevel(1)
	server.login(username, password)
	server.sendmail(username, to_addr, message.as_string())
	server.quit()