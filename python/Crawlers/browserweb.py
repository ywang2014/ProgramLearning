# -*- coding: utf-8 -*-

# 爬虫入门

# 第一步导入第三方库
import urllib
import webbrowser as web	# 取别名

ur1 = 'http://www.163.com'
content = urllib.urlopen(ur1).read()
open("163.com.html", "w").write(content)
web.open_new_tab('163.com.html')
web.open_new_tab('http://www.github.com')	# webbrowser.open...一样
