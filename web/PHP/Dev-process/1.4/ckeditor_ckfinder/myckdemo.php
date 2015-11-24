<html>
	<head>
		<meta http-equiv="content-type" content="text/html;charset=utf-8">
		<title>CKEditor</title>
	</head>
	<body>

<div align="center">
<form action="demo_act.php" method="post">
<?php
	include_once "./ckeditor/ckeditor.php";            //引用关键文件
	include_once "./ckfinder/ckfinder.php";            //引用关键文件
	$initialValue = '';    			                    //编辑区域显示的默认值
	$CKEditor = new CKEditor();                            //实例化
	$CKEditor->basePath = './ckeditor/';                //设定ckeditor的目录
	$CKEditor->config['width'] = 1000;                    //宽度 
	$CKEditor->config['height'] = 600;                    //高度 
	$config['skin'] = 'office2003';                                        //kama,office2003,v2
	CKFinder::SetupCKEditor($CKEditor, 'ckfinder/');//定义ckfinder的目录
	$CKEditor->editor("content", $initialValue, $config);    //建立editor1窗口,editor1的名字,$initialValue默认值,$config设置皮肤
?>
<input name="Submit" type="submit" value="Submit"/>
</form>
</div>
	
	</body>
</html>
