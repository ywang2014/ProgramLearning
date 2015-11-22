<?php
/*
* 动态页面
*/
header('content-type: text/html; charset=utf-8');

require('./include/init.php');

$pid = $_GET['pid'] + 0;	// 通过id查询
if ($pid < 0)
{
	// id 不可能小于等于0，比如非法
	exit('id 非法');
}

$sql = "select * from projects where pid = '$pid'";

// 此句必须要，否则插入、查找等都会失败！
mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");
mysql_query("SET names utf8");

$project = getRow($sql, $conn);
if (empty($project))
{
	exit('查找失败，id非法！');
}

// print_r($project);

$sql = "select * from reply where pid = '$pid' order by replytime";

mysql_select_db($_CFG['dbname'], $conn) or die("数据库连接失败！");
$replys = getAll($sql, $conn);	// 回复可能有多行记录

?>

<html>
	<head>
		<meta charset = "utf-8">
		<title> Project Show </title>
	</head>
	
	<body>
		<center>
		<div>
			<h1> <?php echo $project['title']; ?></h1>
		</div>
		
		<table border = 0 width = "80%" style = "border:1px solid #ddd; margin: 10px auto; overflow:scroll;">
			<tr>
				<td colspan = 2>
					<div style = "padding:0px; margin:0px; height:30px; background-color:#ddd; vertical-align: middle;"> 
					<p>
						<strong style = "font-weight:bold;"> <?php echo $project['title']; ?> </strong>
						<strong style = "font-weight:bold"> <?php echo $project['username']; ?> </strong>
						 <?php echo $project['pubtime']; ?>
					</p>
					</div>
					<div>
						<p> <?php echo nl2br($project['content']); ?></p>
					</div>
				</td>
			</tr>
			
			<?php foreach($replys as $v)
			{ ?>
			<!-- ************** 回复开始 ***************** -->
			<tr> <td colspan = 2> <div style="width:100%; height:1px; border-top:1px solid #999; clear:both;"></div> </td> </tr>
			<tr>
				<td style="height:100px;width:60px;">
					<a href = "#"> <strong style = "font-weight:bold"> <?php echo $v['username']; ?> </strong> </a>
					<p> 回复时间：<?php echo date("Y-m-d", $v['replytime']); ?> </p>
				</td> 
				<td style="height:100px;width:200px; vertical-align:top;">
					<?php echo $v['content']; ?> 
				</td>
			</tr>
			<?php } ?>
			<!-- ************** 回复结束 ***************** -->
		</table>
		
			<div>
				<form action = "replyaction.php" method = "post">
					<p>
						<input type = "hidden" name = "pid" value = "<?php echo $_GET['pid']; ?>">
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
