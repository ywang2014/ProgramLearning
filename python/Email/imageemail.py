# -*- coding: utf-8 -*-

# 带图片的邮件

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

msgText = MIMEText('<b> Image <i> HTML </i> text </b> and image. <img alt = "" src = "cid:image1"/> good!', 'html', 'utf-8')

msgRoot.attach(msgText)

fp = open('test.jpg', 'rb')
msgImage = MIMEImage(fp.read())
fp.close()

msgImage.add_header('Meinv', ' ')
msgRoot.attach(msgImage)

server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msgRoot.as_string())
server.quit()


