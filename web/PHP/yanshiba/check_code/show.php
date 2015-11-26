<?php 

session_start(); 

echo "<img src=create.php border=0 align=absbottom>";//生成图片 

echo $_SESSION["code"];//生成验证码值 
?>