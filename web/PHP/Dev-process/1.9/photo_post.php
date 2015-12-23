<?php
header('content-type: text/html; charset=utf-8');

?>
<!DOCTYPE html>
	<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title> 照片上传 </title>
		<style type="text/css">
			body{font-size:18px;}
			input{vertical-align:middle; margin:0; padding:0}
			.file-box{position:relative;width:600px}
			.txt{height:40px; border:1px solid #cdcdcd; width:380px;}
			.btn{font-size:18px; background-color:#FFF; border:1px solid #CDCDCD;height:40px; width:100px;}
			.file{position:absolute; top:0; right:80px; height:24px; filter:alpha(opacity:0);opacity: 0;width:260px }
		</style>
	</head>
	<body>
		<div >
			<h1 align = "center"> 照片上传 </h1>
			<table width = "60%" cellpadding = "10" style = "border:1px solid #ddd; margin:20px auto;">
				<form action="photo_act.php" method="post" enctype="multipart/form-data">
					<tr>
						<td style = "padding-top:20px;">
							<div class="file-box">
								<input type='text' name='textfield' id='textfield' class='txt' />  
								<input type='button' class='btn' value='浏览...' />
								<input type="file" name="file" class="file" id="file" size="28" onchange="document.getElementById('textfield').value=this.value" />
								<input type="submit" class="btn" value="上传" />
							</div>
						</td>
					</tr>
					<tr>
						<td>
							用户名：<input type = "text" name = "username"  style = "width:400px; height:30px;"/> 
						</td>
					</tr>
				</form>
			</table>
		</div>
	</body>
</html>