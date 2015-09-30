<?php
// XML 分析器类的实现
class Newsboy
{
	// define member variable
	var $xml_parser;
	var $xml_file;
	var $html;
	var $open_tag;
	var $close_tag;
	
	// Construction function
	function Newsboy()
	{
		$this->xml_parser = "";
		$this->xml_file = "";
		$this->html = "";
		// those are default value, which are easy to modify
		$this->open_tag = array("NEWSBOY" => "\n<!-- XML Starts here --> \n <TABLE COLS = 1 CELLPADDINNG = 5>", 
								"STORY" => "<TR> <TD BGCOLOR = #222222>", "DATE" => "<FONT COLOR = #BBBB00>",
								"SLUG" => "<FONT COLOR = #00AACC> <B> &nbsp; &nbsp;", 
								"TEXT" => "<FONT COLOR = #AAAAAA>", "PIC" => "", "NEWLINE" => "");
		$this->close_tag = array("NEWSBOY" => "</TABLE> \n <!-- XML Ends here --> \n \n", 
								"STORY" => "</TD> </TR>", "DATE" => "</FONT>",
								"SLUG" => "</B> </FONT> <BR>", 
								"TEXT" => "</FONT> \n", "PIC" => "<IMAGE SRC=", "NEWLINE" => "<BR>");
		// 数组的关键字与后面将要分析的标记是一样的，并且它们相应的值包含格式化打开与关闭标记的HTML代码
	}
	
	// Destructor (PHP不支持自动析构函数，需要手动添加)
	function destroy()
	{
		// 释放xml分析器
		xml_parser_free($this->xml_parser);
	}
	
	// class member function
	function concat($str)
	{
		$this->html .= $str;
	}
	
	function startElement($parser, $name, $attrs)
	{
		// $open_tag 是全局变量
		if ($format = $this->open_tag[$name])
		{
			$this->html .= $fromat;
		}
	}
	
	function endElement($parser, $name)
	{
		if ($format = $this->close_tag[$name])
		{
			$this->html .= $format;
		}
	}
	
	function characterData($parser, $data)
	{
		$this->html .= $data;
	}
	
	function parse()
	{
		$this->xml_parser = xml_parser_create();
		// 注册一个类方法的回调函数		&$this PHP对象的实例地址
		xml_set_object($this->xml_parser, &$this);
		// use case-folding(大小写折叠) so we are sure to find the tag in $map_array
		xml_parser_set_option($this->xml_parser, XML_OPTION_CASE_FOLDING, true);
		// 指定用于开始和结束标记的回调函数，名字是"startElement"和"endElement"
		xml_set_element_handler($this->xml_parser, "startElement", "endElement");	
		xml_set_character_data_handler($this->xml_parser, "characterData");
		// xml_set_processing_instruction_handler($this->xml_parser, "PIHandler");
		if (! ($fp = fopen($this->xml_file, "r")))
		{
			die("could not open XML input");
		}
		while ($data = fread($fp, 4096))
		{
			if (! xml_parse($this->xml_parser, $data, feof($fp)))
			{
				die(sprintf("XML error: %s at line %d", xml_error_string(xml_get_error_code($this->xml_parser)), xml_get_current_line_number($this->xml_parser)));
			}
		}
	}
}	// class end!
?>