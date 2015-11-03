/*************************
禁止查看网页源代码
*************************/

1、将以下代码加入到HEML的之间

以下为引用的内容：
<SCRIPT language=javascript> 
function click() {if (event.button==2) {alert('不许你偷看！');}}document.onmousedown=click 
</SCRIPT>

2、禁止查看网页源代码

真正能实现源代码屏蔽的单纯的。htm是不可能的！想看源代码是没办法阻止的。用TELEPROT可以下载任何文件，相当于做镜像网站，除非服务器进行安全设置、加密。

下面给几种参考方法，使在浏览我的个人主页时不能使用右键或者不能看到源程序或源代码等。

1)在主页上输入代码：

以下为引用的内容：
<SCRIPT language=javascript> 
function click() { 
if (event.button==2) { 
alert(\'对不起,禁止使用此功能^_^.\') 
} 
} 
document.onmousedown=click 
</SCRIPT> 
<script language="JavaScript"> 
<!-- 
locate = 0; 
function scroller() { 
if (locate !=500 ) { 
locate++; 
scroll(0,locate); 
clearTimeout(timer); 
var timer = setTimeout("scroller()",3); 
timer; 
} 
} 
// --> 
</script> 　　

2)网页安全技术指南

随着Internet的飞速发展，网站的数量正呈几何级速度递增，网页上的信息极大丰富，但网站的安全与信息的版权却不断受到威胁。近来，全球各大网站先后遭到黑客攻击，接着，为了顺应新形势，国内首家有关网络安全专题的网站(天网安全阵线)诞生了。网站与网页的安全性受到越来越多的关注，本文将由浅入深地介绍关于加强网页安全性的各种技术和技巧，对关心网页源代码版权和网页数据安全保护的读者有较大的帮助。

初级入门篇

对广大网页编写者来说，对源代码的保护是最为关注的，但往往却没有任何办法。辛辛苦苦编写的网页在浏览者面前毫无遮掩，只要被别人轻轻点击鼠标右键，选择(查看源代码)一项后，即可获得网页完全代码，甚至稍加修改后就成为他人的网页。本篇将通过采用JavaScript技术，对页面源代码的修改，使浏览者无法获得源码，达到保护代码的目的。

首先，应屏蔽Internet Explorer工具栏中-查看-源代码一项的功能，即将页面采用框架结构的方式。若你的页面并未使用框架结构，且不需使用框架结构，可使用"零框架"技术(即将页面分为左右两帧，左帧的宽度为1，右帧为原页面)，该方法的代码如下：

以下为引用的内容：
<html> 
<head> 
<title>欢迎光临网页教学网</TITLE> 
</HEAD> 
<FRAMESET COLS="1,*" frameborder=0 framespacing=0> 
<FRAME SRC="PS.HTM" NAME="count" noresize scrolling=no> 
<FRAME SRC="search.HTM" NAME="search" noresize> 
</frameset> 
</html>

将该文件存为主文件index.htm，建立一空文件ps.htm，原页面文件现另存为index.html(与主文件名仅在扩展名上略有不同)。采用零框架技术有以下优点：

1.浏览者在用工具栏中的源代码项无法直接得到页面代码，仅能得到框架主文件的代码(即上述代码)。

2.可利用左帧文件ps.htm加载一些网页的高级应用，如背景音乐，网页计数器，cookie应用等。

其次，应屏蔽鼠标右键的显示源文件功能，即在所需保护的页面文件(上例中为index.html文件)中加入以下代码：

以下为引用的内容：
<script Language="JavaScript"> 
function click() { 
if (event.button==2||event.button==3) {alert(\'"用右键要干嘛？"^_^\') }} 
//引号中提示可自定义 
document.onmousedown=click 
</script>

最后，为防止一些了解网页编写语言的人通过框架主文件中的连接手工找出被保护页面后获得源代码，还应在被保护页面中加入以下代码：

以下为引用的内容：
<script language="javascript"> 
if(top==self)top.location="index.html" 
</script>

这段代码将提供跳回功能，使浏览器无法直接看到该页，而是自动跳回框架主文件index.html，起到保护该页面的作用。

在完成以上三个步骤，对你的主页按照框架结构进行了修改后，你的主页源代码将不能被浏览者在网上获得，可以小小庆贺一下了。

另外，若你确实不想用框架页面，那么可用特殊的方法打开浏览器新窗口，再结合屏蔽鼠标的功能代码后亦可收到同样的效果，打开方法如下：

以下为引用的内容：
<a href=javascript:window.open("key.html","被保护页面的标题","height=170,width=290,left=0,top=0,toolbar=0,location=0,directories=0,status=0,menubar=0, 
scrollbars=0,resizable=0,copyhistory=0") target=_blank>打开被保护页面的连接</a>
　　
代码中，key.html为被保护页面的文件名。新窗口的高度height与宽度width的值可由用户自定义，单位为像素。
注意：嵌入式的 JavaScript代码应加在原文件的元素区内。

中级深入篇

上篇中是采用JavaScript技术达到保护在线网页的目的。正所谓"强中自有强中手"，有些人使用Webzip，TelePro，Offline等离线浏览器下载你的主页，就可绕过JavaScript保护在线网页的防线，将网页下载后再慢慢剖析。有矛必有盾，你亦可用JavaScript建立的动态转向文件是大多数离线浏览器无法下载你的网页，方法如下。你可将上例中的被保护页面更名为index1.html，而将文件index.html改为以下代码：

以下为引用的内容：
<script> 
window.location.replace(\'index1.html\') //本句产生网页跳转功能 
</script>

对Internet Explorer5新增的离线浏览功能(脱机工作)，以上方法有时失灵，可通过对网页设置cookie的高级技术达到保护的目的。一旦cookie超期，即使网页已被下载到本机也无法浏览，呵呵，厉害吧:)

应加入文件中的cookie代码段如下：

以下为引用的内容：
<script language="JavaScript"> 
function getCookieVal (offset) 
{ 
var endstr = document.cookie.indexOf (";", offset); 
if (endstr == -1) 
endstr = document.cookie.length; 
return unescape(document.cookie.substring(offset, endstr)); 
} 
function GetCookie (name) 
{ 
var arg = name + "="; 
var alen = arg.length; 
var clen = document.cookie.length; 
var i = 0; 
while (i < clen) 
{ 
var j = i + alen; 
if (document.cookie.substring(i, j) == arg) 
return getCookieVal (j); 
i = document.cookie.indexOf(" ", i) + 1; 
if (i == 0) 
break; 
} 
return null; 
} 
function SetCookie (name, value) 
{ 
var argv = SetCookie.arguments; 
var argc = SetCookie.arguments.length; 
var expires = (2 < argc) ? argv[2] : true; 
var path = (3 < argc) ? argv[3] : true; 
var domain = (4 < argc) ? argv[4] : true; 
var secure = (5 < argc) ? argv[5] : true; //安全模式生效 
document.cookie = name + "=" + escape (value) + 
((expires == null) ? "" : ("; expires=" + expires.toGMTString())) + 
((path == null) ? "" : ("; path=" + path)) + 
((domain == null) ? "" : ("; domain=" + domain)) + 
((secure == true) ? "; secure" : ""); 
} 
function ResetCounts(name) 
{ 
visits = 0; 
SetCookie(expdate , "/", true, true); 
location.reload(); 
} 
</script> 
<script language="JavaScript"> 
var expdate = new Date(); 
var visits; 
expdate.setTime(expdate.getTime() + (24*60*60 * 1000)); //COOKIES超期时间设置,此处为1天 
if(!(visits = GetCookie("visits"))) 
visits = 0; 
visits++; 
SetCookie(expdate, "/", true, true); 
</script>
如果你已经做到这一步了，那么你的网页所受到的保护就不再是常规意义上的出于道德观念或版权意识，而是真正的技术上的保护手段。

高级研究篇

对网页的保护并不仅仅是涉及源代码的保护，更应该包含对网页数据或网络数据库的保护。对网络数据库的保护可采用基于IIS的CGI接口的认证程序，SQL的安全技术，ASP安全认证程序，Java Applet安全认证程序等手段，属于更高层次的安全措施，包含大量内容，本文不作介绍。本篇将介绍应用JavaScript技术构造的页面认证接口。将仅供有限人群访问的需要数据保护的页面中加入以下代码：

以下为引用的内容：
<script LANGUAGE="JAVASCRIPT"> 
<!-- 
loopy() 
function loopy() { 
var sWord ="" 
while (sWord != "hibow") { 
sWord = prompt("输入正确密码登陆! ") 
} 
alert("身份识别......允许登陆") 
} 
//--> 
</script>