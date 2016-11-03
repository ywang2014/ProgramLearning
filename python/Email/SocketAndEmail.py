# -*- coding: utf-8 -*-

# php 程序

'''
    /*
    名称：用Socket发送电子邮件
    描述：本类实现了直接使用需要验证的SMTP服务器直接发送邮件
    作者：小露珠3.3 ，欢迎和我联系交流PHP QQ6550382
    MAIL：cleverzhang@tom.com
    参考文章《用Socket发送电子邮件》作者：limodou
    */
'''
    # set_time_limit(120);
class smtp_mail {
    var $host; //主机
    var $port; //端口 一般为25
    var $user; //SMTP认证的帐号
    var $pass; //认证密码
    var $debug = false; //是否显示和服务器会话信息？
    var $conn;
    var $result_str; //结果
    var $in; //客户机发送的命令
    var $from; //源信箱
    var $to; //目标信箱
    var $subject; //主题
    var $body; //内容
    function smtp_mail($host,$port,$user,$pass,$debug=false) {
    $this->host = $host;
    $this->port = $port;
    $this->user = base64_encode($user);
    $this->pass = base64_encode($pass);
    $this->debug = $debug;
    $this->socket = socket_create (AF_INET, SOCK_STREAM, SOL_TCP); //具体用法请参考手册
    if($this->socket) {
    $this->result_str = "创建SOCKET:".socket_strerror(socket_last_error());
    $this->debug_show($this->result_str);
    } else {
    exit("初始化失败，请检查您的网络连接和参数");
    }
    $this->conn = socket_connect($this->socket,$this->host,$this->port);
    if($this->conn) {
    $this->result_str = "创建SOCKET连接:".socket_strerror(socket_last_error());
    $this->debug_show($this->result_str);
    } else {
    exit("初始化失败，请检查您的网络连接和参数");
    }
    $this->result_str = "服务器应答：".socket_read ($this->socket, 1024)."";
    $this->debug_show($this->result_str);
    }
    function debug_show($str) {
    if($this->debug) {
    echo $str."\r\n";
    }
    }
    function send($from,$to,$subject,$body) {
    if($from == "" || $to == "") {
    exit("请输入信箱地址");
    }
    if($subject == "") $sebject = "无标题";
    if($body == "") $body = "无内容";
    $this->from = $from;
    $this->to = $to;
    $this->subject = $subject;
    $this->body = $body;
    $All = "From:".$this->from."\n";
    $All .= "To:".$this->to."\n";
    $All .= "Subject:".$this->subject."\n";
    $All .= $this->body;
    /*
    如过把$All的内容再加处理，就可以实现发送MIME邮件了
    */
    //以下是和服务器会话
    $this->in = "EHLO HELO\r\n";
    $this->docommand();
    $this->in = "AUTH LOGIN\r\n";
    $this->docommand();
    $this->in = $this->user."\r\n";
    $this->docommand();
    $this->in = $this->pass."\r\n";
    $this->docommand();
    $this->in = "MAIL FROM:".$this->from."\r\n";
    $this->docommand();
    $this->in = "RCPT TO:".$this->to."\r\n";
    $this->docommand();
    $this->in = "DATA\r\n";
    $this->docommand();
    $this->in = $All."\r\n.\r\n";
    $this->docommand();
    $this->in = "QUIT\r\n";
    $this->docommand();
    //结束，关闭连接
    }
    function docommand() {
    socket_write ($this->socket, $this->in, strlen ($this->in));
    $this->debug_show("客户机命令：".$this->in);
    $this->result_str = "服务器应答：".socket_read ($this->socket, 1024)."";
    $this->debug_show($this->result_str);
    }
    }
    //以上为类
    $smtp = new smtp_mail("smtp.126.com","25","name","pass",true); //无会话
    //$smtp = new smtp_mail("smtp.163.com","25","你的163.com的帐号","你的密码",true); //有会话
    $smtp->send("name@126.com","to@to.com","subject","body");


在网上找了一个用socket发送邮件的类，但是在mail from:me@163.com这里出错了，请教下。debug信息如下:
创建SOCKET:Success
创建SOCKET连接:Success

服务器应答：220 163.com Coremail SMTP(Anti Spam) System

客户机命令：
EHLO HELO

服务器应答：250-mail 250-PIPELINING 250-AUTH LOGIN PLAIN NTLM 250-AUTH=LOGIN PLAIN NTLM 250 8BITMIME

客户机命令：AUTH LOGIN

服务器应答：334 dXNlcm5hbWU6

客户机命令：cGFfZmVuX2RlX3Jlbg==

服务器应答：334 UGFzc3dvcmQ6

客户机命令：MTk3OTA0MDQ=

服务器应答：235 Authentication successful

客户机命令：MAIL FROM:*@163.com

服务器应答：500 Error: bad syntax

客户机命令：RCPT TO:*@163.com

服务器应答：503 bad sequence of commands


原代码如下:
<?
/*
作者：小露珠3.3 ，欢迎和我联系交流php qq6550382
mail：cleverzhang@tom.com
*/
set_time_limit(120);
class smtp_mail
{
var $host; //主机
var $port; //端口 一般为25
var $user; //smtp认证的帐号
var $pass; //认证密码
var $debug = false; //是否显示和服务器会话信息？
var $conn;
var $result_str; //结果
var $in; //客户机发送的命令
var $from; //源信箱
var $to; //目标信箱
var $subject; //主题
var $body; //内容
function smtp_mail($host,$port,$user,$pass,$debug=false)
{
$this->host = $host;
$this->port = $port;
$this->user = base64_encode($user);
$this->pass = base64_encode($pass);
$this->debug = $debug;
$this->socket = socket_create (AF_INET, SOCK_STREAM, SOL_TCP); //具体用法请参考手册
if($this->socket)
{
$this->result_str = "创建socket:".socket_strerror(socket_last_error());
$this->debug_show($this->result_str);
}
else
{
exit("初始化失败，请检查您的网络连接和参数");
}
$this->conn = socket_connect($this->socket,$this->host,$this->port);
if($this->conn)
{
$this->result_str = "创建socket连接:".socket_strerror(socket_last_error());
$this->debug_show($this->result_str);
}
else
{
exit("初始化失败，请检查您的网络连接和参数");
}
$this->result_str = "服务器应答：<font color=#cc0000>".socket_read ($this->socket, 1024)."</font>";
$this->debug_show($this->result_str);

}
function debug_show($str)
{
if($this->debug)
{
echo $str."<p>\r\n";
}
}
function send($from,$to,$subject,$body)
{
if($from == "" || $to == "")
{
exit("请输入信箱地址");
}
if($subject == "") $sebject = "无标题";
if($body == "") $body = "无内容";
$this->from = $from;
$this->to = $to;
$this->subject = $subject;
$this->body = $body;
$all = "from:".$this->from."\n";
$all .= "to:".$this->to."\n";
$all .= "subject:".$this->subject."\n";
$all .= $this->body;
/*
如过把$all的内容再加处理，就可以实现发送mime邮件了
不过还需要加很多程序
*/

//以下是和服务器会话
$this->in = "ehlo helo\r\n";
$this->docommand();
$this->in = "auth login\r\n";
$this->docommand();
$this->in = $this->user."\r\n";
$this->docommand();
$this->in = $this->pass."\r\n";
$this->docommand();
$this->in = "mail from:".$this->from."\r\n";
$this->docommand();
$this->in = "rcpt to:".$this->to."\r\n";
$this->docommand();
$this->in = "data\r\n";
$this->docommand();
$this->in = $all."\r\n.\r\n";
$this->docommand();
$this->in = "quit\r\n";
$this->docommand();
//结束，关闭连接

}
function docommand()
{
socket_write ($this->socket, $this->in, strlen ($this->in));
$this->debug_show("客户机命令：".$this->in);
$this->result_str = "服务器应答：<font color=#cc0000>".socket_read ($this->socket, 1024)."</font>";
$this->debug_show($this->result_str);
}
}
//这个是我做的测试，我用的是smtp.163.com，那你的信箱也必须是163.com的，要不人家不让你发！！
//你用这个类的时候你修改成你自己的信箱就可以了
$smtp = new smtp_mail("smtp.163.com","25","t_design","000000",true);
//如果你需要显示会话信息，请将上面的修改成
//$smtp = new smtp_mail("smtp.163.com","25","你的163.com的帐号","你的密码",true);
$smtp->send("t_design@163.com","t_beijing@yahoo.com.cn","你好","你好");
?>