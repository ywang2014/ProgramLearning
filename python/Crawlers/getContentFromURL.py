# -*- coding: utf-8 -*-

'''
	网络爬虫0.1
	抓取网页中的特定内容
	python 3.4 没有urllib2 有urllib，但是内容奇怪！
'''
#################### import #########################################
import urllib
import re

#--------------------------------------------------------------------
def getContentFromURL(url):
	#req = urllib2.Request(url)
	resphtml = urllib.urlopen(url).read()
	#print("html = ", resphtml)
	
	#<h1 class = "username"> user </h1>  使用正则表达式
	content = re.search('<h1\s+?class="username">(?P<username>.+?)</h1>', resphtml)
	print('content = ', content)
	if any(content):
		username = content.group("username")
		print("username = ", username)
	
#------------------------------------------------------------------------------------------
def test():
	url = "http://www.baidu.com"
	req = urllib2.Request(url)
	fd = urllib2.urlopen(req)
	print "Retrieved", fd.geturl()	# Retrieved http://www.baidu.com
	info = fd.info()
	
	for key, v in info.items():
		print "%s = %s" % (key, v)
		
#------------------------------------------------------------------------------------------
def test2():
	import urllib
	print urllib.urlopen("http://www.baidu.com").readline()
	
#------------------------------------------------------------------------------------------
def test3():
	import urllib
	baidu = urllib.urlopen("http://www.baidu.com")	# 返回一个url的类文件对象，可以操作文件一样，使用该对象
	print "header = ", baidu.info()
	print "status = ", baidu.getcode()
	print "url = ", baidu.geturl()
	
	for line in baidu:
		print line
	
	baidu.close()
############################################################################################
if __name__ == "__main__":
	getContentFromURL("http://www.baidu.com")
	
'''
urlopen返回 一个类文件对象，他提供了如下方法：
    read() , readline() , readlines() , fileno() , close() ：这些方法的使用方式与文件对象完全一样;
    info()：返回一个httplib.HTTPMessage 对象，表示远程服务器返回的头信息；
    getcode()：返回Http状态码。如果是http请求，200表示请求成功完成;404表示网址未找到；
    geturl()：返回请求的url；

	
urllib.urlretrieve(url[, filename[, reporthook[, data]]])：#[]表明参数可选
	urlretrieve方法直接将远程数据下载到本地。
	参数filename指定了保存到本地的路径（如果未指定该参数，urllib会生成一个临时文件来保存数据）；
	参数reporthook是一个回调函数，当连接上服务器、以及相应的数据块传输完毕的时候会触发该回调。
	可以利用这个回调函 数来显示当前的下载进度，下面的例子会展示。
	参数data指post到服务器的数据。该方法返回一个包含两个元素的元组(filename, headers)，
		filename表示保存到本地的路径，header表示服务器的响应头。
		
	下面通过例子来演示一下这个方法的使用，这个例子将新浪首页的html抓取到本地，保存在D:/sina.html文件中，同时显示下载的进度。

def cbk(a, b, c):
    &#039;&#039;&#039;回调函数
    @a: 已经下载的数据块
    @b: 数据块的大小
    @c: 远程文件的大小
    &#039;&#039;&#039;
    per = 100.0 * a * b / c
    if per &gt; 100:
        per = 100
    print &#039;%.2f%%&#039; % per

url = &#039;http://www.sina.com.cn&#039;
local = &#039;d://sina.html&#039;
urllib.urlretrieve(url, local, cbk)


辅助方法：
    urllib.quote(string[, safe])：对字符串进行编码。参数safe指定了不需要编码的字符;
    urllib.unquote(string) ：对字符串进行解码；
    urllib.quote_plus(string [ , safe ] ) ：与urllib.quote类似，但这个方法用’+'来替换’ ‘，而quote用’%20′来代替’ ‘
    urllib.unquote_plus(string ) ：对字符串进行解码；
    urllib.urlencode(query[, doseq])：将dict或者包含两个元素的元组列表转换成url参数。例如 字典{‘name’: ‘dark-bull’, ‘age’: 200}将被转换为”name=dark-bull&age=200″
    urllib.pathname2url(path)：将本地路径转换成url路径；
    urllib.url2pathname(path)：将url路径转换成本地路径；

'''

#--------------------------------------------------------------------------
'''
有几种方法可以实现提取所需的信息：

1. 对于HTML源码：

（1）如果是Python中的话，可以通过调用第三方的Beautifulsoup库然后再调用find等函数，来提取对应的信息。

	这部分内容，相对很复杂，需要详细了解的，可以参考一下：http://www.crifan.com/crifan_released_all/website/python/blogstowordpress/ 中的源码。

（2）直接使用正则表达式自己去提取相关内容

	对于内容的分析和提取，很多时候，都是通过正则表达式来实现的。

		关于正则表达式的相关知识和总结，http://www.crifan.com/summary_regular_expression_csharp_python/
		详解python正则表达式：http://www.crifan.com/detailed_explanation_about_python_regular_express/

	正则表达式是一种规范/规则，具体用何种语言实现，取决于你自己。
	
	Python：使用re模块，常用的函数是find，，findall，search等
	
2. 如何处理Json
	
	（1）使用库（函数）来处理

		Python中，有对应的json库，常用的是json.load，即可将json格式的字符串，转换为对应的字典Dictionary类型变量，很是好用。

	（2）还是使用正则表达式来处理