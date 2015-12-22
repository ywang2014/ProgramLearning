<?php
/*
	treenode.class.php
	
*/

class Treenode
{
	public $m_postid;
	public $m_title;
	public $m_author;
	public $m_post_time;
	public $m_children;
	public $m_childlist;
	public $m_depth;
	
	public function __construct($postid, $title, $author, $post_time, $children, $expand, $depth, $expanded, $sublist)
	{
		$this->m_postid = $postid;
		$this_m_title = $title;
		$this->m_author = $author;
		$this->m_post_time = $post_time;
		$this->m_children = $children;
		$this->m_childlist = array();
		$this->m_depth = $depth;
		
		if (($sublist || $expand) && $children)
		{
			$conn = db_connect();
			$sql = "select * from header where parent = '$postid' order by post_time";
			
			$result = mysql_query($sql);
			for ($count = 0; $row = @mysql_fetch_array($result); $count++)
			{
				if ($sublist || $expanded[$row['postid']] == true)
				{
					$expand = true;
				}
				else
				{
					$expand = false;
				}
				
				// 创建新节点，自动递归！构造函数实现的巧妙
				$this->m_childlist[$count] = new treenode($row['postid'], $row['title'], $row['author'], 
												$row['post_time'], $row['children'], $expand, $depth+1, 
												$expanded, $sublist);
			}
		}
	}
	
	function display($row, $sublist = false)
	{
		if ($this->m_depth > -1)
		{
			echo "<tr> <td bgcolor = \"";
			if ($row % 2 == 1)
			{
				echo "#ccc\" >";
			}
			else
			{
				echo "#fff\" >";
			}
			
			// indent replies to the depth of nesting
			for ($i = 0; $i < $this->m_depth; $i++)
			{
				echo "<img src = \"images/spacer.gif\" height = \"22\" width = \"22\" alt = \" \" valign = \"bottom\" />";
			}
			
			// display + or - or a spacer
			if ((!$sublist) && ($this->m_children) && (sizeof($this->m_childlist)))
			{
				echo "<a href = \"index.php?collapse=".$this->m_postid."#".$this->m_postid."\" >".
						"<img src = \"images/minus.gif\" valign = \"bottom\" height = \"22\" width = \"22\" alt = \"Collapse Thread\" ".
					"border = \"0\" /> </a> \n";
			}
			else if (!$sublist && $this->m_children)
			{
				echo "<a href = \"index.php?expand=".$this->m_postid."#".$this->m_postid."\" >".
						"<img src = \"images/plus.gif\" valign = \"bottom\" height = \"22\" width = \"22\" alt = \"Expand Thread\" ".
					"border = \"0\" /> </a> \n";
			}
			else
			{
				echo "<img src = \"images/spacer.gif\" height = \"22\" width = \"22\" alt = \" \" valign = \"bottom\" /> \n";
			}
			
			echo "<a name = \"".$this->m_postid."\"> <a href = \"view_post.php?postid=".$this->m_postid."\">".
					$this->m_title." - ".$this->m_author." - ".reformat_date($this->m_post_time)."</a> </td> </tr>";
					
			// increment row counter to alternate colors ??? --> 110行递归调用
			$row++;
		}
		
		$num_children = sizeof($this->m_childrenlist);
		for ($i = 0; $i < $num_children; $i++)
		{
			$row = $this->m_childlist[$i]->display($row, $sublist);	// 递归
		}
		return $row;
	}
}

?>