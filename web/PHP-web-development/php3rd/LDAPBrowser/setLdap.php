<?php
// 设置公共的LDAP服务器信息
$LDAP_NAME[0] = "Netscape Net Center";	// LDAP项目名字
$LDAP_SERVER[0]	= "memberdir.netscape.com";	// LDAP项目的IP地址或主机名
$LDAP_ROOT_DN[0] = "ou = member_directory, o = netcenter.com";	// LDAP项目根的辨识名 
$LDAP_NAME[1] = "Bigfoot";
$LDAP_SERVER[1] = "ldap.bigfoot.com";
LDAP_ROOT_DN[1] = "";
// 如果没有选择服务器的话，将它设置为0
if (! SERVER_ID)
{
	$SERVER_ID = 0;
}
?>

<?php 
// 建立LDAP查询
// LDAP查询与SQL查询不同：语句要受到一定的限制
Create Query $ldap_query = "cn = $common";	// "cn":要进行搜索的属性，$common有所搜的from中得到的字符串变量
// LDAP查询语句，可以使用通配符“*”
?>

<?php 
// 连接到LDAP服务器
// 连接到LDAP，并将连接的识别号赋给一个变量，就好像连接到通常的数据库一样
$connect_id = ldap_connect($LDAP_SERVER[$SERVER_ID]);
// $connect_id 连接的识别号
// $LDAP_SERVER 可能的ldap服务器组
// $SERVER_ID由搜索表格得到的LDAP服务器变量
?>

<?php 
// 处理查询
// 如果连接成功，得到一个有效的LDAP连接识别号，就可以处理查询
if ($connect_id)
{
	// 认证 ldap_bind()
	$bind_id = ldap_bind($connect_id);	// 匿名绑定到公共的LDAP服务器
	// 执行搜索 ldap_search()
	$search_id = ldap_search($connect_id, $LDAP_ROOT_DN[$SERVER_ID], $ldap_query);
	// 将结果集合分配给一个数组 ldap_get_entries()
	$result_array = ldap_get_entries($connect_id, $search_id);
}
else
{
	// 显示连接错误
	echo ("Could not connect to LDAP server: $LDAP_SERVER[$SERVER_ID]");
}
?>

<?php
// 如果搜索成功，将结果排序
/*
"cn" = Common Name
"dn" = Distinguished Name
"sn" = Last Name
"mail" = E-mail 
*/
if ($result_array)
{
	for ($i = 0; $i < $result_array; $i++)
	{
		// 查询结果，被格式化用作输出
		$format_array[$i][0] = strtolower($result_array[$i]["cn"][0]);	// 将所有值变成小写
		$format_array[$i][1] = $result_array[$i]["dn"];
		$format_array[$i][2] = strtolower($result_array[$i]["givenname"][0]);
		$format_array[$i][3] = strtolower($result_array[$i]["sn"][0]);
		$format_array[$i][4] = strtolower($result_array[$i]["mail"][0]);
	}
	// 排序数组
	sort($format_array, "SORT_STRINC");
	for ($i = 0; $i < $result_array; $i++)
	{
		$cn = $format_array[$i][0];
		$dn = $format_array[$i][1];
		$fname = ucwords($format_array[$i][2]);
		$lname = ucwords($format_array[$i][3]);
		$email = $format_array[$i][4];
		if ($dn && $fname && $lname && $email)
		{
			$result_list.= "$fname $lname";
			$result_list.= " <$email> \n";
		}
		elseif ($dn && $cn && $email)
		{
			// 超链接中使用的是：ldap 的 URL 格式
			$result_list.= "<A href = '/"ldap://$LDAP_SERVER[$SERVER_ID]/$dn/"' > $cn </A>";
			$result_list.= " <A href = '/"mailto: $email/"' > $email </A> \n";
		}
		else
		{
			echo ("Result set empty for query: $ldap_query");
		}
	}
}
?>

<?php 
// 关闭连接
// 数据已经包含在$result_list中，可以安全地关闭LDAP连接
ldap_close($connect_id);
?>