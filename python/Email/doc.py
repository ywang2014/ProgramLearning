# -*- coding: utf-8 -*-

# 电子邮件

	# MUA：Mail User Agent——邮件用户代理：写邮件的一些软件
	# MTA：Mail Transfer Agent——邮件传输代理：网易、新浪etc
	# MDA：Mail Delivery Agent——邮件投递代理
	
	# 发件人 -> MUA -> MTA -> MTA -> 若干个MTA -> MDA <- MUA <- 收件人
	
# 编写程序来发送和接收邮件
	
	# 1.编写MUA把邮件发到MTA
	# 2.编写MUA从MDA上收邮件
	
	# 发邮件时，MUA和MTA使用的协议就是SMTP：Simple Mail Transfer Protocol，后面的MTA到另一个MTA也是用SMTP协议
	# 收邮件时，MUA和MDA使用的协议有两种：POP：Post Office Protocol，目前版本是3，俗称POP3；
	# IMAP：Internet Message Access Protocol，目前版本是4，优点是不但能取邮件，还可以直接操作MDA上存储的邮件，比如从收件箱移到垃圾箱，等等
	
	# send
	# 先配置SMTP服务器: 163提供的SMTP服务器地址：smtp.163.com
	# SMTP服务器还要求你填写邮箱地址和邮箱口令
	# receive
	# 邮件客户端会要求你填写POP3或IMAP服务器地址、邮箱地址和口令
	
## 在使用Python收发邮件前，请先准备好至少两个电子邮件, 注意两个邮箱不要用同一家邮件服务商