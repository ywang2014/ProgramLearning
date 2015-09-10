<?php
// 设计搜索界面的HTML表格，用来给用户执行搜索

// 定制表格
echo ("<CENTER> <FROM action = '\"$PHP_SELF\"' method = '\"GET\"'>");	// $PHP_SELF全局常量，代表脚本页面的自身
echo ("Search in: <SELECT name = '\"SERVER_ID\"'>");
// 循环以建立SELECT选项
for ($i = 0; $i < COUNT($LDAP_NAME); <br $i++ = >)
{
	echo "<OPTION selected value = '\"$i\"'>".$LDAP_NAME[$i]."</OPTION>";
	echo "</SELECT>";
}	
echo "Search for: <INPUT name = '\"common\"' type = '\"text\"'>";
echo "<INPUT name = '\"lookup\"' type = '\"submit\"' value = '\"go\"'>";
echo "</FORM> </CENTER>";

?>

<?php
// 显示结果
if ($result_lsit)
{
	echo "<CENTER> <TABLE border = '\"1\"' cellPadding = '\"10\"' cellSpacing = '\"0\"' BGCOLOR = \"#FFFFEA\" WIDTH = \"450\"> <TBODY> <TR> <TD> $result_list </TD> </TR> </TBODY> </TABLE> </CENTER>";
}
else
{
	echo "No Results";
}
?>