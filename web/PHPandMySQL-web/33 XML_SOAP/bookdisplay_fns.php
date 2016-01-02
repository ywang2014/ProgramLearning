<?php
/*
	bookdisplayfunctions.php 
*/
// for a particular browsenode, display a page of products
function showBrowseNode($browsenode, $page, $mode)
{
	$ars = getARS($browse, array('browsenode' => $browseNode, 'page' => $page, 'mode' => $mode));
	
	showSummary($ars->products(), $page, $ars->totalResults(), $mode, $browseNode);
}

?>