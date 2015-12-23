<?php 
/* 主页
* php 可以与 html 混合
* php解释器，见到<?php ?> 才当做php解释！
*/

header('content-type: text/html; charset=utf-8');
require("include/init.php");

@mysql_select_db($_CFG['dbname'], $conn) or die ("数据库连接失败！");

$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
$pageNum = 10;

$sql = "select * from blogs";
$total = mysql_num_rows(mysql_query($sql));
$pages = ceil($total/$pageNum);

/* 安全检查 */
if ($page > $pages)
{
	$page = $pages;	// 最大为pages，最后一页
}
else if ($page < 1)
{
	$page = 1;	// 最小为1，首页
}

$offset = ($page - 1)*$pageNum;
$sql = "select * from blogs order by ptime desc limit $offset, $pageNum";	// 逆序排列，新发项目的显示在前面
$list = getAll($sql, $conn);

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
			header, footer, section, article, aside, nav, figure{
				display:block;
				margin:0;
				padding:0;
				border:0;
			}
			
			a {text-decoration:none; color: blue; font-size: 20px;}
			a:hover {text-decoration:none; color: #ef7a82}
			
			p{
				font-size:20px;
			}
			
		</style>
		
	</head>

	<body style = "background-image:url('./static/template/images/blog.jpg'); filter:alpha(opacity:30);opacity:1;">
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

		<div id = "bg" >
					<script>
						var div = document.getElementById('bg');
						var div1 = document.getElementById('navMenu');
						div.height = window.screen.height - div1.style.height;
						div.width = document.body.clientWidth;
						// alert(div.height);
					</script>
					
					<div style = "float: left; width:10%">
						<h1> 专家博主 </h1>
						<div>
						</div>
					</div>
					<div style = "float: left; width:80%">
						<h1 align = "center"> 博客列表 </h1>
						<div>
							<!---------- blog start ------------>
							<?php
								foreach ($list as $v){
							?>	
			
							<div >
								<table >
									<tr>
										<td> 
											<a href = "blog_page.php?bid=<?php echo $v['bid']; ?>" title = "<?php echo $v['title']; ?>"> <?php echo $v['title']; ?> </a>
										</td>
										<td>
											<p> &nbsp; <?php echo $v['username']; ?> </p>
										</td>
										<td>
											<p> &nbsp; <?php echo date('Y-m-d H:i:s', $v['ptime']); ?> </p>
										</td>
									</tr>
								</table>
							</div>
				
							<?php } ?>
							<!------------ end ---------->
							<div>
								<p>
								<?php
									for($i = 1; $i <= $pages; $i++)
									{
										if ($i == 1)
										{
											$show = ($i != $page) ? "<a href='blog.php?page=".$i."'>首页</a>" : "<b>首页</b>";
										}
										else if ($i == $pages)
										{
											$show = ($i != $page) ? "<a href='blog.php?page=".$i."'>尾页</a>" : "<b>尾页</b>";
										}
										else
										{
											$show = ($i != $page) ? "[ <a href='blog.php?page=".$i."'>$i</a> ]" : "[ <b>$i</b> ]";
										}
										
										echo $show." ";
									}
									?>
								</p>
							</div>
						</div>
						
					</div>
					
					<div style = "float: left; width:10%">
						<h1> 友情链接 </h1>
						<div>
						</div>
					</div>
				</div>
				
	</body>
</html>