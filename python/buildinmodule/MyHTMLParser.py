# -*- coding: utf-8 -*-

from html.parser import HTMLParser
from html.entities import name2codepoint 

class MyHTMLParser(HTMLParser):
	in_title = False
	in_location = False
	in_time = False
	
	def handle_starttag(self, tag, attrs):
		if ('class', 'event-title') in attrs:
			self.in_title = True
			# 在此处直接输出Title 应该也可以。
		elif ('class', 'event-location') in attrs:
			self.in_location = True
		elif tag == 'time':
			self.in_time = True
			self.times = []
			
	def handle_data(self, data):
		if self.in_title:
			print('-' * 50)
			print('Title: ' + data.strip())
		if self.in_location:
			print('Location: ' + data.strip())
		if self.in_time:
			self.times.append(data)
			
	def handle_endtag(self, tag):
		if tag == 'h3':
			self.in_title = False
		if tag == 'span':
			self.in_location = False
		if tag == 'time':
			self.in_time = False
			print('Time: ' + '-'.join(self.times))
			
parser = MyHTMLParser()
with open('python-events.htm') as html:
	parser.feed(html.read())
	
input('pause!')