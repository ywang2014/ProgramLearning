<?php
$file_handle = fopen("problem.txt", "r");

// 窗口标题的字数
$t_num = fopen($file_handle, 5);
$t_num = int($t_num);

// 试卷题目的字数
$e_t_num = fread($file_handle, 5);
$e_t_num = int($e_t_num);

// 第一大题题目字数
$n1_zi_num = fread($file_handle, 5);
$n1_zi_num = int($n1_zi_num);

// 第二大题题目字数
$n2_zi_num = fread($file_handle, 5);
$n2_zi_num = int($n2_zi_num);

// 第三大题题目字数
$n3_zi_num = fread($file_handle, 5);
$n3_zi_num = int($n3_zi_num);


// 第一大题题目的个数
$n1_ge_num = fread($file_handle, 5)
$n1_ge_num = int($n1_ge_num);

// 第二大题题目的个数
$n2_ge_num = fread($file_handle, 5)
$n2_ge_num = int($n2_ge_num);

// 第三大题题目的个数
$n3_ge_num = fread($file_handle, 5)
$n3_ge_num = int($n3_ge_num);


// 第一大题小题题目的字数
$n1_szi_num = fread($file_handle, 5);
$n1_szi_num = int($n1_szi_num);

// 第二大题小题题目的字数
$n2_szi_num = fread($file_handle, 5);
$n2_szi_num = int($n2_szi_num);

// 第三大题小题题目的字数
$n3_szi_num = fread($file_handle, 5);
$n3_szi_num = int($n3_szi_num);

// 第一大题答案字数
$n1_ans_num = fread($file_handle, 5);
$n1_ans_num = int($n1_ans_num);

// 第一大题各题间的字符串间隔数
$n1_str_num = fread($file_handle, $n1_ans_num)
?>

<html>
	<head>
		<title> 
			<?php
			$title = fread($file_handle, $t_num);
			echo "$title";
			?>
		</title>
	</head>
	
	<body>
		<?php
		// 读取考试标题
		$exam_title = fread($file_handle, $e_t_num);
		echo "<h1 align = center> $exam_title </h1> \n";
		
		// 读取考试时间
		$exam_time = fread($file_handle, 8);
		$exam_time_year = substr($exam_time, 0, 4);
		$exam_time_month = substr($exam_time, 4, 2);
		
		echo "<font size = 2>";
		echo "<p align = right>";
		echo "$exam_time_year - $exam_time_month";
		echo "&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;"
		echo "</p>";
		echo "</font>";
		?>
		
		<hr>
		<ol>
			<lh> <big> <b> 考生注意: </b> </big>
			<br>
			<li> 请填好自己的姓名及准考证号，否则考卷无效!
			<li> 答完考题后，点击"提交"提交试卷
		</ol>
		<br>
		<form method = "post" action = "check.php">
			姓名：<input type = "text" name = "exam_man">
			<br>
			准考证号: <input type = "password" name = "exam_pas">
			<hr>
			<?php
			// 读取第一题题目，并显示
			$nol_title = fread($file_handle, $n1_zi_num);
			echo "<p size = 4> $nol_title </p>";
			echo "<ol>";
			
			for ($i = 1; $i <= $n1_ge_num; $i++)
			{
				// 选择题题目
				echo "<li>";
				echo fread($file_handle, n1_szi_num);
				echo "<ol>";
				echo "<br>";
				
				echo "答案：";
				$ans_cou = 0;
				do
				{
					// 给表单编号
					$ans_cou++;
					$ans_name = "I".(string)$i;
					echo "<input type = "checkbox" name = $ans_name>";
					
					// 选择题答案选项读取并输出
					$nol_answer = fread($file_handle, $n1_ans_num);
					echo $nol_answer;
					echo "<br>";
				}
				while ($nol_answer < $n1_str_num)	// 可能有不同数目的选项
				echo "</ol>";
				
				// 第二题大题目读取并显示
				$no2_title = fread($file_handle, $n2_zi_num);
				echo "<input type = \"submit\" value = \"提交\">";
				echo "</form>";
				
				echo "<p size = 4> $no2_title </p>";
				echo "<ol>";
				for ($i = 1; $i <= $n2_ge_num; $i++)
				{
					// 第二题各小题题目读取并显示
					echo "<p>";
					echo "<form method = \"post\" action = \"check1.php\">";
					echo "<li>";
					echo fread($file_handle, $n2_szi_num);
					
					echo "<br>";
					echo "答案";
					// 编号
					$ans_name = "II".(string)$i;
				}
				
				// 第三大题题目说明
				echo "</ol>";
				$no3_title = fread($file_handle, $n3_zi_num);
				echo "<p size =4> <b> $no3_title </b> </p>";
				
				for ($i = 1; $i <= $n3_ge_num; $i++)
				{
					// 小题题目读取并显示
					echo "<p>";
					echo fread($file_handle, $n3_szi_num);
					echo "</p>";
					
					$ans_name = "III".(string)$i;
					
					echo "<textarea name = $ans_name rows = 9 cols = 100>";
					echo "</textarea>";
				}
				
				fcolse($file_handle);
			}
			?>
			<input type = "submit" value = "交流">
		</form>
	</body>
	<!-- 存储文件的方法：文件存储必须按照特定格式 -->
</html>