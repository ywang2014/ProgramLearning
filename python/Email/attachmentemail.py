# -*- coding: utf-8 -*-

# 带附件形式的email

from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage
import smtplib

from_addr = 'ywangsh2011@163.com'
password = 'feixue54321'
to_addr = 'ywangsh2014@sina.com'
subject = 'python email test'
server = smtplib.SMTP('smtp.163.com', 25)

msgRoot = MIMEMultipart('related')
msgRoot['Subject'] = 'hello'

attachment = MIMEText(open('test.jpg', 'rb').read(), 'base64', 'utf-8')
attachment["Content-Type"] = 'application/octet-stream'
attachment["Content-Disposition"] = 'attachment; filename = "test.jpg"'
msgRoot.attach(attachment)

msgImage.add_header('Meinv', ' ')
msgRoot.attach(msgImage)

server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msgRoot.as_string())
server.quit()

# 群邮件：[to_addr]这是一个list，可以放很多的收件人

# SSL 邮件
server = smtplib.SMTP('smtp.163.com', 25)
server.ehlo()   # 链接服务器，立即调用这三句
server.starttls()
server.ehlo()
stmp.set_debuglevel(1)
server.login(from_addr, password)
# 一样。。。
