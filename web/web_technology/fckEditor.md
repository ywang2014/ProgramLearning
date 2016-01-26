#配置FCK_editor总结

文件上传路径配置：

******* fckeditor *******

	修改文件上传路径： fckeditor\editor\filemanager\connectors\php/config.php
	$Config['UserFilesPath'] = '/127.0.0.100/wuliuzixun/data/images/images_fck/';
	
	修改导航条里面显示的内容
	fckconfig.js
	FCKConfig.ToolbarSets["Default"]

该文件中，不能有index.php文件，否则不能上传！