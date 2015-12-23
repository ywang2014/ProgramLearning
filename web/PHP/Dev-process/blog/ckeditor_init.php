<?php
	include_once "../ckeditor_ckfinder/ckeditor/ckeditor.php";            //引用关键文件
	include_once "../ckeditor_ckfinder/ckfinder/ckfinder.php";            //引用关键文件
	$initialValue = '';    			                    //编辑区域显示的默认值
	$CKEditor = new CKEditor();                            //实例化
	$CKEditor->basePath = '../ckeditor_ckfinder/ckeditor/';                //设定ckeditor的目录
	$CKEditor->config['width'] = 1200;                    //宽度 
	$CKEditor->config['height'] = 350;                    //高度 
	$config['skin'] = 'office2003';                                        //kama,office2003,v2
	CKFinder::SetupCKEditor($CKEditor, '../ckeditor_ckfinder/ckfinder/');//定义ckfinder的目录
	$CKEditor->editor("content", $initialValue, $config);    //建立editor1窗口,editor1的名字,$initialValue默认值,$config设置皮肤
?>