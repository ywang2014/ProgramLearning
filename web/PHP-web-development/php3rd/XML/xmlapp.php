<?php
// 类的实例应用

// 首先包含类的定义到脚本中
require(CLASS_DIR."xmlParser.php");
// 创建类的实例，并且设置文件性为我们的xml文档的实际链接
$news = new Newsboy()
$news->xml_file = "xml/mynews.xml";
// 或 $news->xml_file = http://xmdocs.mysite.com/mynews.xml

// 调用分析器来分析文档
$news->parse();
// 打印html到屏幕上
print($news->html);
// 释放类
$news->destroy();

?>