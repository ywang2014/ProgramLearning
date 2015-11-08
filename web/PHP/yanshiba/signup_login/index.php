<html>

<?php
	if (isset($_SESSION['username']) && !empty($_SESSION['username']))
	{?>
		您好，<font color = "red"> <?php echo $_SESSION['username']; ?> </font>，欢迎访问我们的网站！
		<a href = '#'>用户中心</a>
		<a href = 'logout.php'>退出</a>
<?php }
	else
	{
	?>
		欢迎光临我们的网站
		<a href = 'login_session.php'>登录</a>
		<a href = '#'>注册</a>
<?php } ?>

<div>
	内容。。。。

</div>
</html>