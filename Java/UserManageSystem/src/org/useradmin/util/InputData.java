package org.useradmin.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class InputData
{
	private BufferedReader buf = null;
	
	public InputData()
	{
		this.buf = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public int getInt(String info, String err)
	{
		int i = 0;
		boolean flag = true;
		
		while (flag)
		{
			String str = this.getString(info);
			if (str.matches("\\d+"))
			{
				i = Integer.parseInt(str);
				flag = false;
			}
			else
			{
				System.out.println(err);
			}
		}
		return i;
	}
	
	public String getString(String info)
	{
		String str = null;
		System.out.print(info);
		try
		{
			str = this.buf.readLine();
		} 
		catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return str;
	}
	
	public Date getDate(String info, String err)
	{
		Date date = null;
		boolean flag = true;
		
		while (flag)
		{
			String str = this.getString(info);
			if (str.matches("\\d{4}-\\d{2}-\\d{2}"))
			{
				try 
				{
					date = new SimpleDateFormat("yyyy-MM-dd").parse(str);
					flag = false;
				}
				catch (ParseException e)
				{
					e.printStackTrace();
				}
			}
			else
			{
				System.out.println(err);
			}
		}
		return date;
	}
}
