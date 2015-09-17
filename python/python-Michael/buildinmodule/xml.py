# -*- coding: utf-8 -*-

# XML
	# XML虽然比JSON复杂，在Web中应用也不如以前多了，不过仍有很多地方在用
	
# DOM vs SAX
	# 操作XML有两种方法：DOM和SAX
	# DOM会把整个XML读入内存，解析为树，因此占用内存大，解析慢，优点是可以任意遍历树的节点
	# SAX是流模式，边读边解析，占用内存小，解析快，缺点是我们需要自己处理事件
	## 正常情况下，优先考虑SAX，因为DOM实在太占内存
	
# 在Python中使用SAX解析XML非常简洁，通常我们关心的事件是start_element，end_element和char_data，准备好这3个函数，然后就可以解析xml了
# 例如：当SAX解析器读到一个节点时：<a href="/">python</a>，会产生3个事件：
	# start_element事件，在读取<a href="/">时；
	# char_data事件，在读取python时；
	# end_element事件，在读取</a>时
	
from xml.parsers.expat import ParserCreate

class DefaultSaxHandler(object):
    def start_element(self, name, attrs):
        print('sax:start_element: %s, attrs: %s' % (name, str(attrs)))

    def end_element(self, name):
        print('sax:end_element: %s' % name)

    def char_data(self, text):
        print('sax:char_data: %s' % text)

xml = r'''<?xml version="1.0"?>
<ol>
    <li><a href="/python">Python</a></li>
    <li><a href="/ruby">Ruby</a></li>
</ol>
'''

handler = DefaultSaxHandler()
parser = ParserCreate()
parser.StartElementHandler = handler.start_element
parser.EndElementHandler = handler.end_element
parser.CharacterDataHandler = handler.char_data
parser.Parse(xml)

# 需要注意的是读取一大段字符串时，CharacterDataHandler可能被多次调用，所以需要自己保存起来，在EndElementHandler里面再合并
# 最简单也是最有效的生成XML的方法是拼接字符串：
L = []
L.append(r'<?xml version="1.0"?>')
L.append(r'<root>')
L.append(encode('some & data'))
L.append(r'</root>')
return ''.join(L)
## 如果要生成复杂的XML呢？建议你不要用XML，改成JSON

## 解析XML时，注意找出自己感兴趣的节点，响应事件时，把节点数据保存起来。解析完毕后，就可以处理数据


## 练习
	# 请利用SAX编写程序解析Yahoo的XML格式的天气预报，获取当天和第二天的天气：
	# http://weather.yahooapis.com/forecastrss?u=c&w=2151330
	# 参数w是城市代码，要查询某个城市代码，可以在weather.yahoo.com搜索城市，浏览器地址栏的URL就包含城市代码
from xml.parsers.expat import ParserCreate
class WeatherSaxHandler(object):
	def __init__(self):
		self._weathers = []
		
	def start_element(self, name, attrs):
		if name == 'yweather: location':
			self._city = attrs['city']
			self._country = attrs['country']
		elif name == 'yweather:condition':
			self._today = attrs['date'].split(',')[0]
			print(self._today)
		elif name == 'yweather:forecast':
			if len(self._weathers) == 0:
				if attrs['day'] == self._today:
					self._weathers = []
			aweather = {}
			aweather['text'] = attrs['text']
			aweather['high'] = attrs['high']
			aweather['low'] = attrs['low']
			self._weathers.append(aweather)
			
	def end_element(self, name):
		pass
		
	def char_data(self, text):
		pass
		
		
def parse_weather(xml):
	handler = WeatherSaxHandler()
	parser = ParserCreate()
	parser.StartElementHandler = handler.start_element
	parser.EndElementHandler = handler.end_element
	parser.CharacterDataHandler = handler.char_data
	parser.Parse(xml)
	
	return{
		'city': hander._city,
		'country': handler._country,
		'today':{
			'text': handler._weather[0]['text'],
			'low': handler._weather[0]['low'],
			'high': handler._weather[0]['high']
		},
		'tomorrow':{
			'text': handler._weather[1]['text'],
			'low': handler._weather[1]['low'],
			'high':handler._weather[1]['high']
		}
	}
	
# test
data = r'''<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
		<rss version="2.0" xmlns:yweather="http://xml.weather.yahoo.com/ns/rss/1.0" xmlns:geo="http://www.w3.org/2003/01/geo/wgs84_pos#">
			<channel>
		
<title>Yahoo! Weather - Beijing, CN</title>
<link>http://us.rd.yahoo.com/dailynews/rss/weather/Beijing__CN/*http://weather.yahoo.com/forecast/CHXX0008_c.html</link>
<description>Yahoo! Weather for Beijing, CN</description>
<language>en-us</language>
<lastBuildDate>Tue, 08 Sep 2015 8:00 pm CST</lastBuildDate>
<ttl>60</ttl>
<yweather:location city="Beijing" region=""   country="China"/>
<yweather:units temperature="C" distance="km" pressure="mb" speed="km/h"/>
<yweather:wind chill="24"   direction="200"   speed="3.22" />
<yweather:atmosphere humidity="56"  visibility="8"  pressure="1015.6"  rising="0" />
<yweather:astronomy sunrise="5:48 am"   sunset="6:36 pm"/>
<image>
<title>Yahoo! Weather</title>
<width>142</width>
<height>18</height>
<link>http://weather.yahoo.com</link>
<url>http://l.yimg.com/a/i/brand/purplelogo//uh/us/news-wea.gif</url>
</image>
<item>
<title>Conditions for Beijing, CN at 8:00 pm CST</title>
<geo:lat>39.91</geo:lat>
<geo:long>116.39</geo:long>
<link>http://us.rd.yahoo.com/dailynews/rss/weather/Beijing__CN/*http://weather.yahoo.com/forecast/CHXX0008_c.html</link>
<pubDate>Tue, 08 Sep 2015 8:00 pm CST</pubDate>
<yweather:condition  text="Mostly Cloudy"  code="27"  temp="24"  date="Tue, 08 Sep 2015 8:00 pm CST" />
<description><![CDATA[
<img src="http://l.yimg.com/a/i/us/we/52/27.gif"/><br />
<b>Current Conditions:</b><br />
Mostly Cloudy, 24 C<BR />
<BR /><b>Forecast:</b><BR />
Tue - Partly Cloudy. High: 28 Low: 17<br />
Wed - Cloudy. High: 24 Low: 17<br />
Thu - Cloudy. High: 21 Low: 14<br />
Fri - Partly Cloudy. High: 23 Low: 14<br />
Sat - Partly Cloudy. High: 24 Low: 11<br />
<br />
<a href="http://us.rd.yahoo.com/dailynews/rss/weather/Beijing__CN/*http://weather.yahoo.com/forecast/CHXX0008_c.html">Full Forecast at Yahoo! Weather</a><BR/><BR/>
(provided by <a href="http://www.weather.com" >The Weather Channel</a>)<br/>
]]></description>
<yweather:forecast day="Tue" date="8 Sep 2015" low="17" high="28" text="Partly Cloudy" code="29" />
<yweather:forecast day="Wed" date="9 Sep 2015" low="17" high="24" text="Cloudy" code="26" />
<yweather:forecast day="Thu" date="10 Sep 2015" low="14" high="21" text="Cloudy" code="26" />
<yweather:forecast day="Fri" date="11 Sep 2015" low="14" high="23" text="Partly Cloudy" code="30" />
<yweather:forecast day="Sat" date="12 Sep 2015" low="11" high="24" text="Partly Cloudy" code="30" />
<guid isPermaLink="false">CHXX0008_2015_09_12_7_00_CST</guid>
</item>
</channel>
</rss>

<!-- fan469.sports.gq1.yahoo.com Tue Sep  8 06:02:18 PDT 2015 -->
'''
weather = parse_weather(data)
assert weather['city'] == 'Beijing', weather['city']
assert weather['country'] == 'China', weather['country']
assert weather['today']['text'] == 'Partly Cloudy', weather['today']['text']
assert weather['today']['low'] == 20, weather['today']['low']
assert weather['today']['high'] == 33, weather['today']['high']
assert weather['tomorrow']['text'] == 'Sunny', weather['tomorrow']['text']
assert weather['tomorrow']['low'] == 21, weather['tomorrow']['low']
assert weather['tomorrow']['high'] == 34, weather['tomorrow']['high']
print('Weather:', str(weather))

