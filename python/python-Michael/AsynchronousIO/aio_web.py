# -*- coding: utf-8 -*-

# aiohttp
	# HTTP连接就是IO操作，因此可以用单线程+coroutine实现多用户的高并发支持
	# asyncio实现了TCP、UDP、SSL等协议，aiohttp则是基于asyncio实现的HTTP框架
	# 先安装aiohttp：	pip install aiohttp
	# 然后编写一个HTTP服务器，分别处理以下URL：
		# / - 首页返回b'<h1>Index</h1>'；
		# /hello/{name} - 根据URL参数返回文本hello, %s!。
import asyncio
from aiohttp import web

def index(request):
	return web.Response(body = b'<h1>Index</h1>')
	
def hello(request):
	yield from asyncio.sleep(0.5)
	text = '<h1> hello, %s! </h1>' % request.match_info['name']
	return web.Response(body = text.encode('utf-8'))
	
@asyncio.coroutine 
def init(loop):
	app = web.Application(loop = loop)
	app.router.add_route('GET', '/', index)
	app.router.add_route('GET', '/hello/{name}', hello)
	arv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 8000)
	print('Server started at http://127.0.0.1:8000...')
	return arv
	
loop = asyncio.get_event_loop()
loop.run_until_complete(init(loop))
loop.run_forever()

# 注意aiohttp的初始化函数init()也是一个coroutine，loop.create_server()则利用asyncio创建TCP服务


#test
def test():
	import asyncio
	from aiohttp import web

	def index(request):
		return web.Response(body = b'<h1>Index</h1>')
	
	def hello(request):
		yield from asyncio.sleep(0.5)
		text = '<h1> hello, %s! </h1>' % request.match_info['name']
		return web.Response(body = text.encode('utf-8'))
	
	@asyncio.coroutine 
	def init(loop):
		app = web.Application(loop = loop)
		app.router.add_route('GET', '/', index)
		app.router.add_route('GET', '/hello/{name}', hello)
		arv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 8000)
		print('Server started at http://127.0.0.1:8000...')
		return arv
	
	loop = asyncio.get_event_loop()
	loop.run_until_complete(init(loop))
	loop.run_forever()
