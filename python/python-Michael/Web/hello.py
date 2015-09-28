# -*- coding: utf-8 -*-

def application(environ, start_response):
	start_response('200 ok', [('Content-Type', 'text/html')])
	body = '<h1> Hello, %s!</h1>' % (environ['PATH_INFO'][1:] or 'web') 
	return [body.encode('utf-8')]
	