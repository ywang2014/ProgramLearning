<?php
/* 主页
* php 可以与 html 混合
* php解释器，见到<?php ?> 才当做php解释！
*/

require("include/init.php");

$sql = 'select * from projects order by pubtime desc';	// 逆序排列，新发项目的显示在前面

@mysql_select_db($_CFG['dbname'], $conn) or die ("数据库连接失败！");

$list = getAll($sql, $conn);
//print_r($list); exit;

?>

<!DOCTYPE html>
<!-- STATUS OK -->
<html>
	<head>
		<meta charset = "utf-8">
		<title> OuLin-Consult </title>
		
		<link rel = "apple-touch-icon" href = "#">
		
		<style>
			header, footer, section, article, aside, nav, figure{
				display:block;
				margin:0;
				padding:0;
				border:0;
			}
			
			a:link{text-decoration:none; color: blue; font-size: 20px;}
			a:hover{text-decoration:none; color: #ef7a82}
			
			textarea{
				height:100px;
				width:310px;
				}
				
			input{
				height:30px;
				width:200px;
				}
				
			p{
				font-size:20px;
			}
				
		</style>
		
		<link rel = "shortcut-icon" href = "#">
		<link rel = "stylesheet" href = "css/tb_common_c1881cc9.css">
		<link rel = "stylesheet" href = "css/_page__7c11e86f.css">
		<link rel = "stylesheet" href = "css/_page__e78b2984.css">
		<link rel = "stylesheet" href = "css/_page__ea4a9f69.css">
	</head>
	
	<body>
		<div id = "local_flash_cnt"> </div>
		<div class = "wrap1">
			<div class = "wrap2">
				<div class = "wrap_clear"> </div>
				<div id = "head" class = "search search_theme_2 clearfix">
					<div class = "s_nav">
						<a href = "#" class = "s_logo" title = "首页"> </a>
						<div class = "s_tab_hdtag" style = "text-align:center;">
							<a href = "#" param = "word"> 新闻 </a>
							&#12288;
							<a href = "#" param = "wd"> 网页 </a>
							&#12288;
							<a href = "#" param = "word"> 知道 </a>
							&#12288;
							<a href = "#" param = "word"> MP3 </a>
							&#12288;
							<a href = "#" param = "word"> 图片 </a>
							&#12288;
							<a href = "#" param = "word"> 视频 </a>
							&#12288;
							<a href = "#" param = "word"> 地图 </a>
							&#12288;
							<a href = "#" param = "word"> 百科 </a>
							&#12288;
							<a href = "#" param = "word"> 文库 </a>
							&#12288;
							<a href = "#"> 欧麟 </a>
						</div>
						<hr>
					</div>
				</div>
				
				<div style = "position:bottom; height:80%" >
					<div style = "float: left; width:10%">
						<h1> 成功案例 </h1>
						<div>
						</div>
					</div>
					<div style = "float: left; width:80%">
						<h1 align = "center"> 项目案例 </h1>
						<div>
							<!---------- project start ------------>
							<?php
								/* 分离技术
								*  php 遇到 <?php 开始，遇到 ?> 停止解析
								*  更加高级的方法，使用 smarty模板
								*/
								foreach ($list as $v){
							?>	
			
							<div>
								<table >
									<tr>
										<td> 
											<a href = "project_page.php?pid=<?php echo $v['pid']; ?>" title = "<?php echo $v['title']; ?>"> <?php echo $v['title']; ?> </a>
										</td>
										<td>
											<p> <?php echo $v['pubtime']; ?> </p>
										</td>
									</tr>
								</table>
							</div>
				
							<?php } ?>
							<!------------ end ---------->
						</div>
						<!-- ******************* 发布项目 *********************** -->
				<div style = "text-align:center; position:bottom; height: 20%;">
					<hr>
					<form name = "project" action = "project_process.php" method = "post">
						<div class = "editor_title_txt" > 
							<h1> 发布项目 </h1> 
							<p class = "p">
								用户名称：
								<input type = "text" name = "username" class = "input" value = "">
							</p>
							<p class = "p">
								项目标题：
								<input type = "text" name = "title" class = "input" value = "">
							</p>
							<p>
								<textarea class = "textarea" name = "content"> </textarea>
							</p>
							<input type = "submit" class = "subbtn_bg" value = "提交">
						</div>
					</form>
				</div>
				<!-- ******************* 发布项目 end *********************** -->
					</div>
					<div style = "float: left; width:10%">
						<h1> 友情链接 </h1>
						<div>
						</div>
					</div>
				</div>
				
				
				
			</div>
		</div>
	</body>
</html>