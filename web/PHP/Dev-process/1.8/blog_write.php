<?php 
header('content-type: text/html; charset=utf-8');
?>

<!DOCTYPE html >
<html >
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title> Online-System </title>
		<meta name="keywords" content="博客系统, 文件系统, 数据库管理, 搜索功能" />
		<meta name="description" content="文件上传、下载， 博客发布， 博客评论" />
		<link rel="stylesheet" type="text/css" href="./static/template/css/css.css">
		<style>
			p{
				font-size:16px;
			}
			input{
				height:30px;
			}
		</style>
		
	</head>

	<body>
		<div id="navMenu" style = "overflow:hidden;">
			<ul>
			<li class="onelink">
				<a href='index.php' target="_blank"> 
					<img src="./static/template/images/log02.jpg" alt="首页" title="首页" style = "width:80px; height:40px; vertical-align:middle;">
				</a>
			</li>
			<li><a href='#' rel='dropmenu1' target="_blank"> 搜索引擎 </a></li>
			<li><a href='#' rel='dropmenu2' target="_blank"> 新闻资源 </a></li>
			<li><a href='#' rel='dropmenu3' target="_blank"> 学术领域 </a></li>
			<li><a href='blog.php' rel='dropmenu4' target="_blank"> 博客系统 </a></li>
			<li><a href='filesys.php' rel='dropmenu5' target="_blank"> 文件系统 </a></li>
			<li><a href='#' rel='dropmenu6' target="_blank"> 音乐空间 </a></li>
			</ul>
			
			<ul >
			<li style = "width:60px;"> <a href='#'  target="_blank"> &nbsp; </a></li>
			<li > <a href='#'  rel='dropmenu7' target="_blank"> 用户中心 </a></li>
			<li style = "width:120px;">
				<button > 
					<a href='#' target="_blank"> 
						登录/注册 
					</a> 
				</button> 
			</li>
			<li style = "width:120px;">
				<button class = "nav_blog">
					<a href='blog_write.php' target="_blank">
						撰写博客
					</a>
				</button> 
			</li>
			</ul>
		</div>

		<script type='text/javascript' src='./static/template/js/dropdown.js'></script>
			<ul id="dropmenu1" class="dropMenu">
				<li><a href="http://www.google.com.hk" target="_blank"> Google </a></li>
				<li><a href="http://www.baidu.com" target="_blank"> 百度 </a></li>
				<li><a href="http://www.sou360.com" target="_blank"> 360 </a></li>
				<li><a href="https://www.sogou.com/" target="_blank"> 搜狗 </a></li>
				<li><a href="http://sma.so/" target="_blank"> 神马 </a></li>
			</ul>
			<ul id="dropmenu2" class="dropMenu">
				<li><a href="http://news.baidu.com/" target="_blank"> 百度新闻 </a></li>
				<li><a href="http://news.163.com/" target="_blank"> 网易新闻 </a></li>
				<li><a href="http://news.sina.com.cn/" target="_blank"> 新浪新闻 </a></li>
				<li><a href="http://news.qq.com/" target="_blank"> 腾讯新闻 </a></li>
				<li><a href="http://www.china.org.cn/chinese/" target="_blank"> 中国网新 </a></li>
			</ul>
			<ul id="dropmenu3" class="dropMenu">
				<li><a href="http://scholar.glgoo.org/" target="_blank"> Google学 </a></li>
				<li><a href="http://www.nlc.gov.cn/" target="_blank"> 国家图书 </a></li>
				<li><a href="http://www.soci.org/" target="_blank"> SCI </a></li>
				<li><a href="http://www.accm.com/" target="_blank"> ACCM </a></li>
			</ul>
			<ul id="dropmenu4" class="dropMenu">
				<li><a href="" target="_blank"> 精彩博客 </a></li>
				<li><a href="" target="_blank"> 发布博客 </a></li>
				<li><a href="" target="_blank"> 博客搜索 </a></li>
				<li><a href="" target="_blank"> 博客推荐 </a></li>
			</ul>
			<ul id="dropmenu5" class="dropMenu">
				<li><a href="" target="_blank"> 文件列表 </a></li>
				<li><a href="" target="_blank"> 文件搜索 </a></li>
				<li><a href="" target="_blank"> 文件下载 </a></li>
			</ul>
			<ul id="dropmenu6" class="dropMenu">
				<li><a href="http://music.baidu.com/" target="_blank"> 百度音乐 </a></li>
				<li><a href="http://www.kugou.com/" target="_blank"> 酷狗音乐 </a></li>
				<li><a href="http://y.qq.com/" target="_blank"> QQ音乐 </a></li>
			</ul>
			<ul id="dropmenu7" class="dropMenu">
				<li><a href="" target="_blank"> 个人中心 </a></li>
				<li><a href="" target="_blank"> 用户管理 </a></li>
				<li><a href="" target="_blank"> 账号设置 </a></li>
			</ul>
		<script type="text/javascript">cssdropdown.startchrome("navMenu")</script> 

		<!--//nav-->
		
		<div >
			<h1 align = "center"> 写博客 </h1> 
			<form action = "blog_act.php" method = "post">
				<table width = "90%" style = "border:0px solid #ddd; margin:10px auto;">
					<tr> <td style = "padding-letf:20px; ">
					<div class = "editor_title_txt" > 
						<!--
						<p >
							用户名称：
							<input type = "text" name = "username" style = "width:300px;" value = "">
						</p>
						-->
						<p >
							标题：
							<input type = "text" name = "title" style = "width:800px;" value = "">
						</p>
						<p >
							用户名：
							<input type = "text" name = "username" style = "width:350px;" value = "">
							&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;类型：
							<input type = "text" name = "types" style = "width:346px;" value = "">
						</p>
						<p>
							<?php
								include_once "./ckeditor_ckfinder/ckeditor/ckeditor.php";            //引用关键文件
								include_once "./ckeditor_ckfinder/ckfinder/ckfinder.php";            //引用关键文件
								$initialValue = '';    			                    //编辑区域显示的默认值
								$CKEditor = new CKEditor();                            //实例化
								$CKEditor->basePath = './ckeditor_ckfinder/ckeditor/';                //设定ckeditor的目录
								$CKEditor->config['width'] = 1200;                    //宽度 
								$CKEditor->config['height'] = 350;                    //高度 
								$config['skin'] = 'office2003';                                        //kama,office2003,v2
								CKFinder::SetupCKEditor($CKEditor, './ckeditor_ckfinder/ckfinder/');//定义ckfinder的目录
								$CKEditor->editor("content", $initialValue, $config);    //建立editor1窗口,editor1的名字,$initialValue默认值,$config设置皮肤
							?>
						</p>
						
						<input type = "submit" style = "width:100px;" value = "提交">
					</div>
					</tr></td>
				</table>
			</form>
		</div>
	</body>
</html>