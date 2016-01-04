<?php
/*
	cachefunctions.php	
*/
// get an amazonResultSet either from cache or a live query. if a  live query add it to the cache 
function getARS($type, $parameters)
{
	$cache = cached($type, $parameters);
	if ($cache)
	{
		return $cache;
	}
	else
	{
		$ars = new AmazonResultSet;
		if ($type == 'asin')
		{
			$ars->ASINSearch($parameters['asin'], $parameters['mode']);
		}
		else if ($type == 'browse')
		{
			$ars->browseNodeSearch($parameters['browsenode'], $parameteres['page'], $parameters['mode']);
		}
		else if ($type == 'search')
		{
			$ars->keywordSearch($parameters['search'], $parameters['page'], $parameters['mode']);
		}
		cache($type, $parameters, $ars);
	}
	return $ars;
}

// check if Amazon data is in the cache 
function cached($type, $parameters)
{
	if ($type == 'browse')
	{
		$filename = CACHE.'/browse.'.$parameters['browsenode'].'.'.$parameters['page'].'.'.$parameters['mode'].'.dat';
	}
	else if ($type == 'search')
	{
		$filename = CACHE.'/search.'.$parameters['search'].'.'.$parameters['page'].'.'.$parameters['mode'].'.dat';
	}
	else if ($type == 'asin')
	{
		$filename = CACHE.'/asin.'.$parameters['asin'].'.'.$parameters['mode'].'.dat';
	}
	
	// is cached data missing or > 1 hour old?
	if (!file_exists($filename) || ((mktime() - filemtime($filename)) > 60 * 60))
	{
		return false;
	}
	
	$data = file_get_contents($filename);
	return unserialize($data);	//将已序列化的字符串变回 PHP 的值，unserialize()
}

// add Amazon data to the cache 
function cache($type, $parameters, $data)
{
	if ($type == 'browse')
	{
		$filename = CACHE.'/browse.'.$parameters['browsenode'].'.'.$parameters['page'].'.'.$parameters['mode'].'.dat';
	}
	else if ($type == 'search')
	{
		$filename = CACHE.'/search.'.$parameters['search'].'.'.$parameters['page'].'.'.$parameters['mode'].'.dat';
	}
	else if ($type == 'asin')
	{
		$filename = CACHE.'/asin.'.$parameters['asin'].'.'.$parameters['mode'].'.dat';
	}
	
	$data = serialize($data);	//产生一个可存储的值的表示，有利于存储或传递 PHP 的值，同时不丢失其类型和结构
	
	$fp = fopen($filename, "wb");
	if (!$fp || (fwrite($fp, $data) == -1))
	{
		echo "<p> Error, could not store cache file";
	}
	
	fclose($fp);
}









?>