<?php 

if(!empty($_POST["sub"]))
{
    echo $_POST["title"];
    echo "<br>";
    echo $_POST["content"];
}

?>
<html>
<head>
	<meta http-equiv="content-type" content="text/html;charset=utf-8">
    <title>Sample CKEditor Site</title>
</head>
<body>
    <form method="post">
        <p>
            My Editor:<br />
            <input type="text" name="title" placeholder = "title">
		</p>
		<p>
            <textarea name="content" rows = 20 cols = 150>
            <?php
				include "assets/posteddata.php";
                include '../ckeditor/ckeditor.php'; //include ckeditor.php
                $ckeditor = new CKEditor;
                $ckeditor->editor('content');    
            ?>
            </textarea>
        </p>
        <p>
            <input type="submit" name="sub"/>
        </p>
    </form>
</body>
</html>