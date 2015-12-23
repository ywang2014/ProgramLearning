<?php 
/* 
	主页
*/

header('content-type: text/html; charset=utf-8');

?>
<div >
	<table width = "60%" style = "border:2px solid #aef; background-color:#eee; margin:20px auto" >
		<tr>
			<td align = "center" >
				<h1 style = "color:#f00;"> Notice <h1>
				<h3 >
					<?php echo $err_msg; ?>
				</h3>
				<a href = "../file/filesys.php"> 返回文件系统 </a>
			</td>
		</tr>
	</table>
</div>

