﻿# -*- coding: utf-8 -*-

# urllib
	# urllib提供了一系列用于操作URL的功能

# Get 
	# urllib的request模块可以非常方便地抓取URL内容，也就是发送一个GET请求到指定的页面，然后返回HTTP的响应
	# 例如，对豆瓣的一个URLhttps://api.douban.com/v2/book/2129650进行抓取，并返回响应：
from urllib import request

with request.urlopen('https://api.douban.com/v2/book/2129650') as f:
	data = f.read()
	print('Status: ', f.status, f.reason)
	for k, v in f.getheaders():
		print('%s: %s' % (k ,v))
	print('Data:', data.decode('utf-8'))
	
	
# 如果我们要想模拟浏览器发送GET请求，就需要使用Request对象，通过往Request对象添加HTTP头，我们就可以把请求伪装成浏览器
# 模拟iPhone 6去请求豆瓣首页：
from urllib import request
req = request.Request('http://www.douban.com/')
req.add_header('User-Agent', 'Mozilla/6.0 (iPhone: CPU iPhone OS 8_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/8.0 Mobile/10A5376e Safari/8536.25')
with request.urlopen(req) as f:
	print('Status: ', f.status, f.reason)
	for k, v in f.getheaders():
		print('%s: %s' % (k, v))
	print('Data:', f.read().decode('utf-8'))
	
# post 
	# 如果要以POST发送一个请求，只需要把参数data以bytes形式传入
# 我们模拟一个微博登录，先读取登录的邮箱和口令，然后按照weibo.cn的登录页的格式以username=xxx&password=xxx的编码传入
from urllib import request, parse

print('Login to weibo.cn...')
email = input('Email: ')
passwd = input('Password: ')
login_data = parse.urlencode([
    ('username', email),
    ('password', passwd),
    ('entry', 'mweibo'),
    ('client_id', ''),
    ('savestate', '1'),
    ('ec', ''),
    ('pagerefer', 'https://passport.weibo.cn/signin/welcome?entry=mweibo&r=http%3A%2F%2Fm.weibo.cn%2F')
])

req = request.Request('https://passport.weibo.cn/sso/login')
req.add_header('Origin', 'https://passport.weibo.cn')
req.add_header('User-Agent', 'Mozilla/6.0 (iPhone; CPU iPhone OS 8_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/8.0 Mobile/10A5376e Safari/8536.25')
req.add_header('Referer', 'https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=http%3A%2F%2Fm.weibo.cn%2F')

with request.urlopen(req, data=login_data.encode('utf-8')) as f:
    print('Status:', f.status, f.reason)
    for k, v in f.getheaders():
        print('%s: %s' % (k, v))
    print('Data:', f.read().decode('utf-8'))
	

# Handler 
	# 如果还需要更复杂的控制，比如通过一个Proxy去访问网站，我们需要利用ProxyHandler来处理
# 示例代码如下
proxy_handler = urllib.request.ProxyHandler({'http': 'http://www.example.com:3128/'})
proxy_auth_handler = urllib.request.ProxyBasicAuthHandler()
proxy_auth_handler.add_password('realm', 'host', 'username', 'password')
opener = urllib.request.build_opener(proxy_handler, proxy_auth_handler)
with opener.open('http://www.example.com/login.html') as f:
    pass


## urllib提供的功能就是利用程序去执行各种HTTP请求
	# 如果要模拟浏览器完成特定功能，需要把请求伪装成浏览器。伪装的方法是先监控浏览器发出的请求，再根据浏览器的请求头来伪装，User-Agent头就是用来标识浏览器的
	
## 练习
	# 利用urllib读取XML，将XML一节的数据由硬编码改为由urllib获取：
from urllib import request

def fetch_xml(url):
	with request.urlopen(url) as f:
		data = f.read()
		d = {}
		for k, v in f.getheaders():
			d[k] = v
		d['Data'] = data.decode('utf-8')
		return d

# 测试
print(fetch_xml('http://weather.yahooapis.com/forecastrss?u=c&w=2151330'))

## with-as表达式极大的简化了每次写finally的工作，这对保持代码的优雅性是有极大帮助的。
	# try excep finally
	# __enter__()   __exit__()