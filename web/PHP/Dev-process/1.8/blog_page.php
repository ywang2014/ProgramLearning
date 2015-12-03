<?php
/*
* 动态页面
*/
header('content-type: text/html; charset=utf-8');

require('./include/init.php');

$bid = $_GET['bid'] + 0;	// 通过id查询
if ($bid < 1)
{
	// id 不可能小于1，非法
	exit('id 非法');
}

$sql = "select * from blogs where bid = '$bid'";

$blog = getRow($sql, $conn);
if (empty($blog))
{
	exit('查找失败，id非法！');
}

//$sql = "select * from reply where pid = '$pid' order by replytime";
$sql = "select * from comments where bid = '$bid' order by ptime";

if($comments = getAll($sql, $conn))	// 回复可能有多行记录
{
	// 有回复
}
else
{
	$comments = false;
}


?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Blog Show </title>
		
		<style>
			header, footer, section, article, aside, nav, figure{
				display:block;
				margin:0;
				padding:0;
				border:0;
			}
			
			a {text-decoration:none; color: blue; font-size: 20px;}
			a:hover {text-decoration:none; color: #ef7a82}
			
		</style>
	</head>
	
	<body>
		<center>
		<div>
			<h1> <?php echo stripslashes($blog['title']); ?></h1>
		</div>
		
		<table border = 0 width = "80%" style = "border:1px solid #ddd; margin: 10px auto; overflow:scroll;">
			<tr>
				<td colspan = 2>
					<div style = "padding:0px; margin:0px; height:30px; background-color:#ddd; vertical-align: middle;"> 
					<p>
						<strong style = "font-weight:bold;"> <?php echo stripslashes($blog['title']); ?> </strong>
						&nbsp; <strong style = "font-weight:bold"> <?php echo stripslashes($blog['username']); ?> </strong>
						&nbsp; <strong style = "font-weight:bold"> <?php echo stripslashes($blog['types']); ?> </strong>
						&nbsp; <?php echo date('Y-m-d H:i:s', $blog['ptime']); ?>
					</p>
					</div>
					<div>
						<p> <?php //echo nl2br(stripslashes($blog['content']))); 
								echo stripslashes($blog['content']);
							?></p>
					</div>
				</td>
			</tr>
			
			<!-- ************** 评论开始 ***************** -->
			<?php 
			if ($comments)
			{
				foreach($comments as $v)
				{ ?>
					<tr> <td colspan = 2> <div style="width:100%; height:1px; border-top:1px solid #999; clear:both;"></div> </td> </tr>
					<tr>
						<td style="height:100px;width:60px;">
							<a href = "#"> <strong style = "font-weight:bold"> <?php echo stripslashes($v['username']); ?> </strong> </a>
							<p> 回复时间：<?php echo date("Y-m-d", $v['ptime']); ?> </p>
						</td> 
						<td style="height:100px;width:200px; vertical-align:top;">
							<?php echo stripslashes($v['content']); ?> 
						</td>
					</tr>
			<?php } 
			}
			else
			{
				echo '<tr><td><p> 暂时没有评论！</p></td></tr>';
			}	?>
			<!-- ************** 评论结束 ***************** -->
		</table>
		
			<div>
				<form action = "comment_act.php" method = "post">
					<p>
						<input type = "hidden" name = "bid" value = "<?php echo $blog['bid']; ?>">
					</p>
					<p>
						&nbsp;用户名：<input type = "text" name = "username">
					</p>
					<p>
						<?php
									include_once "./ckeditor_ckfinder/ckeditor/ckeditor.php";            //引用关键文件
									include_once "./ckeditor_ckfinder/ckfinder/ckfinder.php";            //引用关键文件
									$initialValue = '';    			                    //编辑区域显示的默认值
									$CKEditor = new CKEditor();                            //实例化
									$CKEditor->basePath = './ckeditor_ckfinder/ckeditor/';                //设定ckeditor的目录
									$CKEditor->config['width'] = 500;                    //宽度 
									$CKEditor->config['height'] = 100;                    //高度 
									$config['skin'] = 'office2003';                                        //kama,office2003,v2
									CKFinder::SetupCKEditor($CKEditor, './ckeditor_ckfinder/ckfinder/');//定义ckfinder的目录
									$CKEditor->editor("content", $initialValue, $config);    //建立editor1窗口,editor1的名字,$initialValue默认值,$config设置皮肤
								?>
					</p>
					<p>
						&nbsp;<input type = "submit" value = "回复">
					</p>
				</form>
			</div>
	</body>
</html>
