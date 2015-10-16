<?php
// 设计风格一致的网页，能够动态修改部分内容
// 创建 Page类，减少创建新网页时所需要的HTML代码，尽可能实现重用

class Page
{
	// class page's atrributes
	// 将需要修改的内容设置为属性：变量成员
	public $title = "TLA Consulting Pty Ltd";	// 提供默认值，防止为空
	public $content;
	
	// metatages 便于搜索引擎对其检索
	public $keywords = "TLA Consulting, Three Letter Abbreviation, some of my best friends are search engines";
	
	// 导航条，所有页面基本框架相同，但是数量、内容可能不同
	// 使用一个数组保存按钮的文本标签和按钮指向的URL
	public $buttons = array("Home" => "home.php",
							"Contact" => "contact.php",
							"Services" => "services.php",
							"Site Map" => "map.php"
							);
							
	public function __get($name)
	{
		if (isset($this->$name))
		{
			return $this->$name;
		}
		return NULL;
	}
	
	public function __set($name, $value)
	{
		$this->$name = $value;
	}
	
	public function Display()
	{
		echo "<html>\n\t<head>\n";
		echo "\t\t<meta charset = "utf-8">\n"
		
		$this->DisplayTitle();
		$this->DisplayKeywords();
		$this->DisplayStyles();
		
		echo "\t</head>\n\t<body>\n";
		
		$this->DisplayHeader();
		$this->DisplayMenu($this->$buttons);
		
		echo $this->content;
		
		$this->DisplayFooter();
		
		echo "\t</body>\n</html>\n";
		
	}
	
	public function DisplayTitle()
	{
		echo "\t\t<title>".$this->title." </title>";
	}
	
	public function DisplayKeywords()
	{
		echo "\t<meta name = \"keywords\" content = \"".$this->keywords."\">";
	}
	
	public function DisplayStyles()
	{
	?>	// end php 
		<style type = "text/css">
			h1{color:white; font-size:24pt; text-align:center; font-family:arial,sans-serif}
			
			.menu{color:white; font-size:12pt; text-align:center; font-family:arial,sans-serif; font-weight:bold}
			
			td{background:black}
			
			p{color:black; font-size:12pt; text-align:justify; font-family:arial,sans-serif; font-weight:bold}
			
			a:link, a:visited, a:active{color:gray}
		</style>
	<?php
	}
	
	public function DisplayHeader()
	{
	?>
		<table width = "100%" cellpadding = "12" cellspacing = "0" border = "0">
			<tr bgcolor = "black">
				<td align = "left">
					<img src = "logo.gif">
				</td>
				<td>
					<h1> TLA Consulting Pty Ltd </h1>
				</td>
				<td align = "right">
					<img src = "logo.gif"
				</td>
			</tr>
		</table>
	<?php 
	}
	
	public function DisplayMenu($buttons)
	{
		echo "<table width = \"100%\" bgcolor = \"white\" cellpadding = \"4\" cellspacing = \"4\">\n";
		echo "<\ttr>\n";
		
		// calculate button size
		$width = 100/count($buttons);
		
		while (list($name, $url) = each($buttons))
		{
			$this->DisplayButton($width, $name, $url, !$this->IsURLCurrentPage($url));
		}
		echo "<\t/tr>\n";
		echo "</table>\n";
	}
	
	public function IsURLCurrentPage($url)
	{
		return strpos($_SERVER["PHP_SELF"], $url)
	}
	
	public function DisplayButton($width, $name, $url, $active = true)
	{
		if ($active)
		{
			echo "<td width = \"".$width."%\">".
			"<a href = \"".$url."\">".
			"<img src = \"s-logo.jpg\" alt = \"".$name."\" border = \"0\"> </a>".
			"<a href = \"".$url."\"> <span class = \"menu\">".$name."</span> </a>".
			"</td>";
		}
		else
		{
			echo "<td width = \"".$width."%\">".
			"<img src = \"side-logo.jpg\">".
			"<span class = \"menu\">".$name."</span>".
			"</td>";
		}
	}
	
	public function DisplayFooter()
	{
	?>
		<table width = "100%" bgcolor = "black" cellpadding = "12" border = "0">
			<tr>
				<td>
					<p class = "foot">&copy: TLA Consulting Pty Ltd. </p>
					<p class = "foot">Please see our <a href = "legal.html">legal information page </a> </p>
				</td>
			</tr>
		</table>
	<?php 
	}
}

?>