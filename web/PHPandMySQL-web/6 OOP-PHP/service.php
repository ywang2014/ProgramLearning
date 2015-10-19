<?php
// service.php -- service页面继承了Page类。
// 重载了Display()操作，从而改变输出

require("page_class.inc");

class ServicePage extends Page
{
	private $row2buttons = array(
								"Re-engineering" => "reengineering.php",
								"Standards Compliance" => "standards.php",
								"Buzzword Compliance" => "buzzword.php",
								"Mission Statements" => "mission.php"
								);
	public function Display()
	{
		echo "<html>\n\t<head>\n";
		$this->DisplayTitle();
		$this->DisplayKeywords();
		$this->DisplayStyles();
		
		echo "\t</head>\n\t<body>\n";
		$this->DisplayHeader();
		$this->DisplayMenu($this->buttons);
		$this->DisplayMenu($this->row2buttons);
		
		echo $this->content;
		$this->DisplayFooter();
		echo "\t</body>\n</html>\n";
	}
}

$service = new ServicePage();

$service->content = "<p> At TLA Consulting, we offer a number of services. Perhaps the productivity of your ".
					"employees would improve if we re-engineered your business. Maybe all your business needs ".
					"is a fresh mission statement, or a new batch of buzzwords.</p>";
					
$service->Display();

?>