## Day2

#### [编写Web App骨架](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143217133614028a244ea855b40a586b551c616d3b2c9000)
Web App建立在asyncio的基础上，因此需要一个用aiohttp写的基本框架----app.py
#### 源代码
	import logging; logging.basicConfig(level=logging.INFO)

	import asyncio, os, json, time
	from datetime import datetime

	from aiohttp import web

	def index(request):
		return web.Response(body=b'<h1>Awesome</h1>')

	@asyncio.coroutine
	def init(loop):
		app = web.Application(loop=loop)
		app.router.add_route('GET', '/', index)
		srv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 9000)
		logging.info('server started at http://127.0.0.1:9000...')
		return srv

	loop = asyncio.get_event_loop()
	loop.run_until_complete(init(loop))
	loop.run_forever()
	
运行 python app.py，Web App将在8888端口监听HTTP请求，并且对首页/进行响应

	app.py	// 双击即可运行
	
	查看效果，在浏览器中输入URL：localhost:9000