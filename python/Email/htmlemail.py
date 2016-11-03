# -*- coding: utf-8 -*-

# HTML形式 email

from email.mime.text import MIMEText
import smtplib

from_addr = 'ywangsh2011@163.com'
password = 'feixue54321'
to_addr = 'ywangsh2014@sina.com'
subject = 'python email test'
server = smtplib.SMTP('smtp.163.com', 25)

msg = MIMEText('</pre> <h1> hello </h1> <pre>', 'html', 'utf-8')
msg['Subject'] = subject

server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()

