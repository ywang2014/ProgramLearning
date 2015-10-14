<?php
/*
* PHP zend email 验证函数 MailVal()
* 正则表达式，验证邮箱格式

**************************************************************************************************
English to Chinese:
* 此函数核查电子邮箱地址的格式，共有五个检查等级：
 
   * 1 -基本格式检查。保证：
 
		*有一个@符号在字符串中间，两边都有些其他的字符
 
		*在@符号的右边，至少有一个'.'，点的左右也都有一些字符串。
 
		*在左后一个'.'的右边，有2个或者3个字母，或者一些如"arpa"的特例。
 
   * 2 -满足1，再加上最后一个'.'的右边字母满足：
 
		*com, net, org, edu, mil, gov, int, arpa 或者是两个字母的国家编码之一，比如：中国"cn"
 
   * 3 -满足1,2，再加上尝试检查是否是一个域名的邮件交换记录(MX (Mail eXchange)).
 
   * 4 -满足上述条件，加上尝试连接到邮件服务器
 
   * 5 -满足上述条件，再加上检查是否能够从邮件服务器得到响应。函数的三个参数是可选的，设置在等待服务器响应时的循环次数。
   默认值是15000. 当然了，实际的等待时间，也依赖于您的服务器速度等因素。
 
   *第1级是防弹：如果该地址不满足这个等级要求，它是很糟糕的。 
 
   *第2级仍然是非常稳固，但不太确定：写这个函数的时候，应该有一个顶级域名被忽略了，或者应该添加一个新域名。
 
   *第3级有更少的不确定性：在任意特定时间内，对于一个有效的地址，有很多东西可以防止找到一个MX记录。
 
   *第4、5等级，仍然有些不确定性。
 
   *基本上，唯一绝对有效的测试邮箱地址的方法，就是向该邮箱地址发送邮件。

   *返回值：对于一个有效的地址，函数返回0，对于无效的地址，函数返回对应的检查失败等级。
**************************************************************************************************/

function MailVal($addr, $level, $timeout = 15000)
{
	// Valid top-level domains
	$gTLDs = "com:net:org:edu:gov:mil:int:arpa:";
	$CCs = "ad:ae:af:ag:ai:al:am:an:ao:aq:ar:as:at:au:aw:az:".
			"ba:bb:bd:be:bf:bg:bh:bi:bj:bm:bn:bo:br:bs:bt:bv:bw:by:bz:".
			"ca:cc:cf:cd:cg:ch:ci:ck:cl:cm:cn:co:cr:cs:cu:cv:cx:cy:cz:".
			"de:dj:dk:dm:do:dz:".
			"ec:ee:eg:eh:er:es:et:".
			"fi:fj:fk:fm:fo:fr:fx:".
			"ga:gb:gd:ge:gf:gh:gi:gl:gm:gn:gp:gq:gr:gs:gt:gu:gw:gy:".
			"hk:hm:hn:hr:ht:hu:".
			"id:ie:il:in:io:iq:ir:is:it:".
			"jm:jo:jp:".
			"ke:kg:kh:ki:km:kn:kp:kr:kw:ky:kz:".
			"la:lb:lc:li:lk:lr:ls:lt:lu:lv:ly:".
			"ma:mc:md:mg:mh:mk:ml:mm:mn:mo:mp:mq:mr:ms:mt:mu:mv:mw:mx:my:mz:".
			"na:nc:ne:nf:ng:ni:nl:no:np:nr:nt:nu:nz:".
			"om:".
			"pa:pe:pf:pg:ph:pk:pl:pm:pn:pr:pt:pw:py:".
			"qa:".
			"re:ro:ru:rw:".
			"sa:sb:sc:sd:se:sg:sh:si:sj:sk:sl:sm:sn:so:sr:st:su:sv:sy:sz:".
			"tc:td:tf:tg:th:tj:tk:tm:tn:to:tp:tr:tt:tv:tw:tz:".
			"ua:ug:uk:um:us:uy:uz:".
			"va:vc:ve:vg:vi:vn:vu:".
			"wf:ws:".
			"ye:yt:yu:".
			"za:zm:zr:zw:";
	
	// The countries can have thier own 'TLDs', e.g. mydomain.com.au
	$cTLDs = "com:net:org:edu:gov:mil:co:ne:or:ed:go:mi:";
	
	$fail = 0;
	
	// Shift the address to lowercase to simplify checking
	$addr = strtolower($addr);
	// Split the address into user and domain parts
	$ud = explode("@", $addr);
	if (sizeof($ud) != 2 || !$ud[0])
	{
		$fail = 1;
	}
	
	// Split the domain part into its levels
	$levels = explode(".", $ud[1]);
	$sLevels = sizeof($levels);
	if ($slevels < 2)
	{
		$fail = 1;
	}
	
	// Get the TLD, strip off trailing ]})> and check the length
	$tld = $levels[$sLevels - 1];
	$tld = ereg_replace("[>)}]$|]$", "", $tld);
	if (strlen($tld) < 2 || strlen($tld) > 3 && $tld != "arpa")
	{
		$fail = 1;
	}
	
	$level--;
	
	// if the string after the last dot isn't in the generic TLds or country codes, it's invalid.
	if ($level && !$fail)	// Start the LEVEL 2:
	{
		$level--;
		// int ereg(string pattern, string string, array [regs]); 字符串对比解析 preg_match()更加规范、高效
		if (! ereg($tld.":", $gTLDs) && ! ereg($tld.":", $CCs))
		{
			$fail = 2;
		}
	}
	
	if ($level && !$fail)
	{
		// If it is country code, check for a country TLD; add on the domain name.
		$cd = $sLevels - 2;
		$domain = $levels[$cd].".".$tld;
		if (ereg($levels[$cd].":", $cTLDs))
		{
			$cd--;
			$domain = $levels[$cd].".".$domain;
		}
	}
	
	// See if there is an MX record for the domain
	if ($level && ! $fail)
	{
		$level--;
		/*
		int getmxrr(string hostname, array mxhosts, array [weight]);
		本函数用来检查 DNS 字段纪录中的 MX 字段，也就是电子邮件服务器 Mail eXchanger 字段。
		若找到了指定网址 DNS 纪录的 MX 字段，返回 true；若未找到指定的 DNS MX 字段或是有错误均会返回 false。
		指定网址的所有 MX 字段纪录的机器都会传入数组参数 mxhosts 中。
		若有指定数组参数 weight，则同时返回 MX 机器的优先顺序。
		*/
		if (! getmxrr($domain, $mxhosts, $weight))
		{
			$fail = 3;
		}
	}
	
	// Attemp to connect to port 25 on an MX host
	if ($level && ! $fail)
	{
		$level--;
		while (! $sh && list($nul, $maxhost) = each($mxhosts))
		{
			$sh = fsockopen($mxhost, 25);
		}
		if (! $sh)
		{
			$fail = 4;
		}
	}
	
	// see if anyone answers
	if ($level && ! $fail)
	{
		$level--;
		set_socket_blocking($sh, false);
		$out = "";
		$t = 0;
		while ($t++ < $timeout && !$out)
		{
			$out = fgets($sh, 256);
		}
		if (! ereg("^220", $out))
		{
			$fail = 5;
		}
	}
		
	if ($sh)
	{
		fclose($sh);
	}
		
	return $fail;
} // MailVal

/*
注释：MX记录 （Mail Exchange）邮件路由记录
            用户可以将该域名下的邮件服务器指向到自己的mail server上，然后即可自行操作控制所有的邮箱设置。您只需在线填写您服务器的主机名或主机IP地址，即可将您域名下的邮件全部转到您自己设定相应的邮件服务器上。
　　这个大家都明白了吗？就是将你的域名中邮件服务器分开，将它设置到其它的IP去！
　　比如同样是 cnMonkey_com ，如果你设置A记录是指向123.12.123.123，而MX记录你设置是指向222.22.222.222，那么你的DNS服务器接收到别人的邮件路 由请求时就将会将它的请求解释到222.22.222.222上去！而别人访问你的网页的时候仍然是访问123.12.123.123。　
　　可以使用nslookup -qt=mx test_com来解析mx的指向。例子中以test_com为例。
*/

?>