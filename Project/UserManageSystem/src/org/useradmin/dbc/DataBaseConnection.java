/*
 * 专门负责进行数据库连接操作的类
 * Java连接MySQL的最新驱动包下载地址 
 * 		http://www.mysql.com/downloads/connector/j
 * 
 * 负责数据库的链接和关闭
 */

package org.useradmin.dbc;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;

public class DataBaseConnection
{
	private static final String DBDRIVER = "org.gdt.mm.mysql.Driver";
	private static final String DBURL = "jdbc:mysql://localhost:3306/mldn";
	private static final String DBUSER = "root";
	private static final String DBPASS = "root";
	private Connection conn = null;
	
	public DataBaseConnection()
	{
		try
		{
			Class.forName(DBDRIVER);
		}
		catch (ClassNotFoundException e)
		{
			e.printStackTrace();
		}
		try
		{
			conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
		} catch (SQLException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public Connection getConnection()
	{
		return this.conn;
	}
	
	public void close()
	{
		if (this.conn != null)
		{
			try
			{
				this.conn.close();
			} catch (SQLException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
