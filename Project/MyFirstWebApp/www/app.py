# -*- coding: utf-8 -*-

# Web App Construction
	# program a based app.py by aiohttp frame!

import logging; logging.basicConfig(level = logging.INFO)
import asyncio, os, json, time
from datetime import datetime
from aiohttp import web

def index(request):
	return web.Response(body = b'<center> <h1> Hello boys and girls! </h1>')
	
@asyncio.coroutine
def init(loop): 
	app = web.Application(loop = loop)
	app.router.add_route('GET', '/', index)
	srv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 8888)
	logging.info('Server started at http://127.0.0.1:8888...')
	return srv
	
loop = asyncio.get_event_loop()
loop.run_until_complete(init(loop))
loop.run_forever()

'''
# test
def test():
	import logging; logging.basicConfig(level = logging.INFO)
	import asyncio, os, json, time
	from datetime import datetime
	from aiohttp import web
	
	def index(request):
		return web.Response(body = b'<center> <h1> Hello boys and girls! </h1>')
	
	@asyncio.coroutine
	def init(loop): 
		app = web.Application(loop = loop)
		app.router.add_route('GET', '/', index)
		srv = yield from loop.create_server(app.make_handler(), '127.0.0.1', 8888)
		logging.info('Server started at http://127.0.0.1:8888...')
		return srv
	
	loop = asyncio.get_event_loop()
	loop.run_until_complete(init(loop))
	loop.run_forever()
	
# 直接运行不成功
python app.py 	18行编译错误
shell 命令行下面，可以正确运行！
'''
