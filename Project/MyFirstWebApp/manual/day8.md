## Day8
#### [构建前端](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001432339124159f00f6ab876c44349a3fd8eb26d0c291e000)
对于复杂的HTML前端页面来说，我们需要一套基础的CSS框架来完成页面布局和基本样式

jQuery作为操作DOM的JavaScript库也必不可少

从零开始写CSS不如直接从一个已有的功能完善的CSS框架开始

有很多CSS框架可供选择。我们这次选择uikit这个强大的CSS框架。
	有很多CSS框架可供选择。我们这次选择uikit这个强大的CSS框架。
	
可以从uikit首页下载打包的资源文件。

所有的静态资源文件我们统一放到www/static目录下，并按照类别归类：

static/
+- css/
|  +- addons/
|  |  +- uikit.addons.min.css
|  |  +- uikit.almost-flat.addons.min.css
|  |  +- uikit.gradient.addons.min.css
|  +- awesome.css
|  +- uikit.almost-flat.addons.min.css
|  +- uikit.gradient.addons.min.css
|  +- uikit.min.css
+- fonts/
|  +- fontawesome-webfont.eot
|  +- fontawesome-webfont.ttf
|  +- fontawesome-webfont.woff
|  +- FontAwesome.otf
+- js/
   +- awesome.js
   +- html5.js
   +- jquery.min.js
   +- uikit.min.js
   
由于前端页面肯定不止首页一个页面，每个页面都有相同的页眉和页脚
 
如果每个页面都是独立的HTML模板，那么我们在修改页眉和页脚的时候，就需要把每个模板都改一遍，这显然是没有效率的。
 
常见的模板引擎已经考虑到了页面上重复的HTML部分的复用问题。有的模板通过include把页面拆成三部分：
	<html>
		<% include file="inc_header.html" %>
		<% include file="index_body.html" %>
		<% include file="inc_footer.html" %>
	</html>
这样，相同的部分inc_header.html和inc_footer.html就可以共享

这样，相同的部分inc_header.html和inc_footer.html就可以共享
	这样，相同的部分inc_header.html和inc_footer.html就可以共享
	然后，编写多个“子模板”，每个子模板都可以只替换父模板定义的block。
	
	比如，定义一个最简单的父模板：
	<!-- base.html -->
	<html>
		<head>
			<title>{% block title%} 这里定义了一个名为title的block {% endblock %}</title>
		</head>
		<body>
			{% block content %} 这里定义了一个名为content的block {% endblock %}
		</body>
	</html>
	
	对于子模板a.html，只需要把父模板的title和content替换掉：

		{% extends 'base.html' %}

		{% block title %} A {% endblock %}

		{% block content %}
			<h1>Chapter A</h1>
			<p>blablabla...</p>
		{% endblock %}
		
	对于子模板b.html，如法炮制：

		{% extends 'base.html' %}

		{% block title %} B {% endblock %}

		{% block content %}
			<h1>Chapter B</h1>
			<ul>
				<li>list 1</li>
				<li>list 2</li>
			</ul>
		{% endblock %}
		
这样，一旦定义好父模板的整体布局和CSS样式，编写子模板就会非常容易。

让我们通过uikit这个CSS框架来完成父模板__base__.html的编写：
	<!DOCTYPE html>
		pass

###### block作用

	用于子页面定义一些meta，例如rss feed：

		{% block meta %} ... {% endblock %}

	覆盖页面的标题：

		{% block title %} ... {% endblock %}

	子页面可以在<head>标签关闭前插入JavaScript代码：

		{% block beforehead %} ... {% endblock %}

	子页面的content布局和内容：

		{% block content %}
			...
		{% endblock %}

我们把首页改造一下，从__base__.html继承一个blogs.html：
	{% extends '__base__.html' %}
		pass
	
相应地，首页URL的处理函数更新如下：
	@get('/')
		pass

Blog的创建日期显示的是一个浮点数，因为它是由这段模板渲染出来的：
	<p class="uk-article-meta">发表于{{ blog.created_at }}</p>

解决方法是通过jinja2的filter（过滤器），把一个浮点数转换成日期字符串。我们来编写一个datetime的filter，在模板里用法如下：
	<p class="uk-article-meta">发表于{{ blog.created_at|datetime }}</p>

	filter需要在初始化jinja2时设置。相关代码如下：
		def datetime_filter(t):
			delta = int(time.time() - t)
			if delta < 60:
				return '1分钟前'
			if delta < 3600:
				return '%s分钟前' % (delta // 60)
			if delta < 86400:
				return '%s小时前' % (delta // 3600)
			if delta < 604800:
				return '%s天前' % (delta // 86400)
			dt = datetime.fromtimestamp(t)
			return '%s年%s月%s日' % (dt.year, dt.month, dt.day)
			
...
init_jinja2(app, filters=dict(datetime=datetime_filter))
...




