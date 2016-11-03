# -*- coding: utf-8 -*-

# 文本形式 email

from email import encoders
from email.utils import parseaddr, formataddr
from email.mime.text import MIMEText
from email.header import Header
import smtplib

def _format_addr(s):
    name, addr = parseaddr(s)
    return formataddr((Header(name, 'utf-8').encode(), addr))

from_addr = 'ywangsh2011@163.com'
password = 'feixue54321'
to_addr = 'ywangsh2014@sina.com'
subject = 'python email test'
server = smtplib.SMTP('smtp.163.com', 25)

msg = MIMEText('hello, python...', 'plain', 'utf-8')
msg['From'] = _format_addr('Python lover <%s>' % from_addr)
msg['To'] = _format_addr('Admin <%s>' % to_addr)
msg['Subject'] = Header(subject, 'utf-8').encode()

server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()







