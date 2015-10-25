<?php
/* 主页
* php 可以与 html 混合
* php解释器，见到<?php ?> 才当做php解释！
*/

require(./include/init.php);

$sql = 'select * from project order by pubtime desc';	// 逆序排列，新发项目的显示在前面

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
						<div class = "s_tab_hdtag">
							<a href = "#" param = "word"> 新闻 </a>
							&#12288;
							<a href = "#" param = "wd"> 网页 </a>
							&#12288;
							<b> 欧麟 </b>
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
						</div>
					</div>
					<div>
						<form name = "f1" id = "tb_header_search_form" class = "f" action = "/f">
							<input autocomplete = "off" size = "42", tabindex = "1" id = "wd1" name = "kw" class = "s_ip_i">
						</form>
					</div>
				</div>
			</div>
			<div id = "editor" class = "frs_rich_editor">
				<form name = "project" action = "project.php" method = "post">
					<div class = "editor_title_txt"> 发布项目 </div>
					<p>
						用户名：<input type = "text" name = "username" class = "editor_title_field" value = "">
					</p>
					<p>
						标题：<input type = "text" name = "title" class = "editor_title_field" value = "">
					</p>
					<p>
						<textarea name = "content"> </textarea>
					</p>
					<input type = "submit" class = "subbtn_bg" value = "提交">
				</form>
			</div>
			
			<!---------- project start ------------>
			<?php
				/* 分离技术
				*  php 遇到 <?php 开始，遇到 ?> 停止解析
				*  更加高级的方法，使用 smarty模板
				*/
				foreach ($list as $v){
			?>	
				<table >
					<tr>
						<td> 
							<a href = "project_page.php?tid=<?php echo $v['tid']; ?>" title = "<?php echo $v['title']; ?>"> <?php echo $v['title']; ?> </a>
						</td>
						<td>
							<p> <?php echo $v['pubtime']; ?> </p>
							<p> <?php echo $v['content']; ?> </p>
						</td>
					</tr>
				</table>
				
			<?php } ?>
			<!------------ end ---------->
		</div>
	</body>
</html>