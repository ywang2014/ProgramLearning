/*
	创建一个XMLHTTPRequest对象案例	-- 支持所有浏览器
*/
function getXMLHTTPRequest()
{
	var req = false;
	try
	{
		/* for Firefox */
		req = new XMLHttpRequest();
	}
	catch (err)
	{
		try
		{
			/* for some versions of IE */
			req = new ActiveXObject("Msxml2.XMLHTTP");
		}
		catch (err)
		{
			try 
			{
				/* for some other versions of IE */
				req = new ActiveXObject('Microsoft.XMLHTTP');
			}
			catch (err)
			{
				req = false;
			}
		}
	}
	
	return req;
}

// 向服务器发送请求，向尝试在数据库里插入记录的PHP脚本发送请求
function addNewBookmark()
{
	var url = "add_bms.php";
	var params = 'new_url=' + encodeURL(document.getElementById('new_url').value);
	
	myReq.open("POST", url, true);
	myReq.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	myReq.setRequestHeader("Content-length", params.length);
	myReq.setRequestHeader("Connection", "close");
	myReq.onreadystatechange = addBMResponse;
	myReq.send(params);
}

function addBMResponse()
{
	if (myReq.readyState == 4)
	{
		if (myReq.status == 200)
		{
			result = myReq.responseText;
		}
		else
		{
			alert('There was a problem with the request.');
		}
	}
}

