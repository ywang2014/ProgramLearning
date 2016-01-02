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









?>