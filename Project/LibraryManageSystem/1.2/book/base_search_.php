
		
		<center>
			<form action = "search.php" method = "post">
				<table border = 0>
					<tr>
						<td>
							<select name = "search_topic" style = "height:40px">
								<option value = "name" selected = "selected"> 书名 </option>
								<option value = "author"> 作者 </option>
								<option value = "pubtime"> 出版日期 </option>
								<option value = "content"> 内容 </option>
							</select>
						</td>
						<td>
							<input type = "text" style = "width:300px; height:40px" name = "search_keyword" value = "请输入关键字">
						</td>
						<td>
							<input type = "submit" style = "width:80px; height:40px" value = "信息搜索">
						</td>
					</tr>
				</table>
			</form>
		</center>
		