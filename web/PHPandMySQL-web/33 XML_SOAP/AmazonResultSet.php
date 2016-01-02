<?php
/*
	AmazonResultSet.php 
	处理与Amazon站点连接的类
*/
if (METHOD == 'SOAP')
{
	include_once('nusoap/lib/nusoap.php');
	// exit;
}

class AmazonResultSet
{
	private $browseNode;
	private $page;
	private $mode;
	private $url;
	private $type;
	private $totalResults;
	private $currentProduct = null;
	private $products = array();
	
	function products()
	{
		return $this->products;
	}
	
	function totalResults()
	{
		return $this->totalResults;
	}
	
	function getProduct($i)
	{
		if (isset($this->products[$i]))
		{
			return $this->products[$i];
		}
		else
		{
			return false;
		}
	}
	
	function browseNodeSearch($browseNode, $page, $mode)
	{
		$this->Service = "AWSECommerceService";
		$this->Operation = "ItemSearch";
		$this->AWSAccessKeyId = DEVTAG;
		$this->AssociateTag = ASSOCIATEID;
		$this->BrowseNode = $browseNode;
		$this->ResponseGroup = 'Large';
		$this->SearchIndex = $mode;
		$this->Sorts = salesrank;
		$this->TotalPages = $page;
		
		if (METHOD == 'SOAP')
		{
			$soapclient = new nusoap_client(
				"http://ecs.amazonaws.com/AWSECommerceService/AWSECommerceService.wsdl", "wsdl");
				
			$soap_proxy = $soapclient->getProxy();
			
			$request = array("Service" => $this->Service, "Operation" => $this->Operation, "BrowseNode" => $this->BrowseNode, 
							"ResponseGroup" => $this->ResponseGroup, "SearchIndex" => $this->SearchIndex, "Sort" => $this->Sorts, 
							"TotalPages" => $this->TotalPages);
							
			$parameters = array("AWSAccessKeyId" => DEVTAG, "AssociateTag" => ASSOCIATEID, "Request" => array($request));
			
			$result = $soap_proxy->ItemSearch($parameters);
			
			if (isSOAPError($result))
			{
				return false;
			}
			
			$this->totalResults = $result['TotalResults'];
			
			foreach ($result['Items']['Item'] as $product)
			{
				$this->products[] = new Product($product);
			}
			
			unset($soapclient);
			unset($soap_proxy);
		}
		else
		{
			$this->url = "http://ecs.amazonaws.com/onca/xml?".
						"Service=".$this->Service.
						"&Operation=".$this->Operation.
						"&AssociateTag=".$this->AssociateTag.
						"&AWSAccessKeyId=".$this->AWSAccessKeyId.
						"&BrowseNode=".$this->BrowseNode.
						"&ResponseGroup=".$this->ResponseGroup.
						"&SearchIndex=".$this->SearchIndex.
						"&Sort=".$this->Sorts.
						"&TotalPages="$this->TotalPages;
			$this->parseXML();
		}
		
		return $this->products;
	}
	
	// Given an ASIN, get the URL of the large image 
	function getImageUrlLarge($ASIN, $mode)
	{
		foreach ($this->products as $product)
		{
			if ($product->ASIN() == $ASIN)
			{
				return $product->imageURLLarge();
			}
		}
		
		// if not found
		$this->ASINSearch($ASIN, $mode);
		return $this->products(0)->imageURLLarge();
	}
	
	function ASINSearch($ASIN, $mode = 'books')
	{
		$this->type = 'ASIN';
		$this->ASIN = $ASIN;
		$this->mode = $mode;
		$ASIN = padASIN($ASIN);
		
		$this->Service = "AWSECommerceService";
		$this->Operation = "ItemLookup";
		$this->AWSAccesssKeyId = DEVTAG;
		$this->AssociatedTag = ASSOCIATEID;
		$this->ResponseGroup = 'Large';
		$this->IdType = 'ASIN';
		$this->ItemId = $ASIN;
		
		if (METHOD == SOAP)
		{
			$soapclient = new nusoap_client(
				"http://ecs.amazonaws.com/AWSECommerceService/AWSECommerceService.wsdl", 'wsdl');
				
			$soap_proxy = $soapclient->getProxy();
			
			$request = array("Service" => $this->Service, "Operation" => $this->Operation, "ResponseGroup" => $this->ResponseGroup, 
				"IdType" => $this->IdType, "ItemId" => $this->ItemId);
				
			$parameters = array("AWSAccessKeyId" => DEVTAG, "AssociateTag" => ASSOCIATEID, "Request" => array($request));
			
			$result = $soap_proxy->ItemLookup($parameters);
			
			if (isSOAPError($result))
			{
				return false;
			}
			
			$this->products[0] = new Product($result['Items']['Item']);
			
			$this->totalResults = 1;
			unset($soapclient);
			unset($soap_proxy);
		}
		else
		{
			// form URL and call parseXML to download and parse it 
			$this->url = "http:// ecs.amazonaws.com/onca/xml?".
						"Service=".$this->Service.
						"&Operation=".$this->Operation.
						"&AssociateTag=".$this->AssociateTag.
						"&AWSAccessKeyId=".$this->AWSAccessKeyId.
						"&ResponseGroup=".$this->ResponseGroup.
						"&IdType=".$this->IdType.
						"&ItemId=".$this->ItemId;
			$this->parseXML();
		}
		return $this->products[0];
	}
	
	// perform a query to get a page full of products with a keyword search
	function keywordSearch($search, $page, $mode = 'Books')
	{
		$this->Service = 'AWSECommerceService';
		$this->Operation = 'ItemSearch';
		$this->AWSAccessKeyId = DEVTAG;
		$this->AssociateTag = ASSOCIATEID;
		$this->ResponseGroup = "Large";
		$this->SearchIndex = $mode;
		$this->Keywords = $search;
		
		if (METHOD == 'SOAP')
		{
			$soapclient = new nusoap_client(
				"http://ecs.amazonaws.com/AWSECommerceService/AWSECommerceService.wsdl", 'wsdl');
				
			$soap_proxy = $soapclient->getProxy();
			
			$request = array("Service" => $this->Service, "Operation" => $this->Operation, 
							"ResponseGroup" => $this->ResponseGroup, "SearchIndex" => $this->SearchIndex, 
							"Keywords" => $this->Keywords);
							
			$parameters = array("AWSAccessKeyId" => DEVTAG, "AssociateTag" => ASSOCIATEID, "Request" => array($request));
			
			$result = $soap_proxy->ItemSearch($parameters);
			if (isSOAPError($result))
			{
				return false;
			}
			
			$this->totalResults = $result['TotalResults'];
			foreach ($result['Items']['Item'] as $product)
			{
				$this->products[] = new Product($product);
			}
			unset($soapclient);
			unset($soap_proxy);
		}
		else
		{
			$this->usl = "http:// ecs.amazonaws.com/onca/xml?".
						"Service=".$this->Service.
						"&Operation=".$this->Operation.
						"&AssociateTag=".$this->AssociateTag.
						"&AWSAccessKeyId=".$this->AWSAccessKeyId.
						"&ResponseGroup=".$this->ResponseGroup.
						"&SearchIndex=".$this->SearchIndex.
						"&Keywords=".$this->Keywords;
						
			$this->parseXML();
		}
		return $this->products;
	}
	
	// parse the XML into Product object(s)
	function parseXML()
	{
		$xml = @simplexml_load_file($this->url);
		if (!$xml)
		{
			// try a second time in case just server busy.
			$xml = @simplexml_load_file($this->url);
			if (!$xml)
			{
				return false;
			}
		}
		
		$this->totalResults = (integer)$xml->TotalResults;
		foreach ($xml->Items->Item as $productXML)
		{
			$this->products[] = new Product($productXML);
		}
	}
}




?>