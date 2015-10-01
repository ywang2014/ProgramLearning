package org.useradmin.operate;

import java.util.Iterator;
import java.util.List;
import org.useradmin.factory.DAOFactory;
import org.useradmin.util.InputData;
import org.useradmin.vo.User;

public class UserOperate
{
	public static void insert()
	{
		User user = new User();
		InputData input = new InputData();
		user.setName(input.getString("请输入姓名："));
		user.setSex(input.getString("请输入性别："));
		user.setBirthday(input.getDate("请输入生日：", "日期格式必须满足：yyyy-mm-dd！"));
		
		try
		{
			DAOFactory.getIUserDAOInstance().doCreate(user);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
	
	public static void update()
	{
		InputData input = new InputData();
		int id = input.getInt("请输入要更新的用户编号：", "编号必须是整数！");
		User user = null;
		
		try
		{
			user = DAOFactory.getIUserDAOInstance().findByID(id);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		if (user != null)
		{
			user.setName(input.getString("请输入姓名(原姓名：" + user.getName() + ")："));
			user.setSex(input.getString("请输入性别(原性别：" + user.getSex() + ")："));
			user.setBirthday(input.getDate("请输入生日(原生日：" +user.getBirthday() +")：", "日期格式必须满足：yyyy-mm-dd！"));
			
			try
			{
				DAOFactory.getIUserDAOInstance().doUpdate(user);
			} catch (Exception e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		else
		{
			System.out.println("要查找的用户不存在！");
		}
	}

	public static void delete()
	{
		InputData input = new InputData();
		int id = input.getInt("请输入要删除的用户编号：", "编号必须是整数！");
		try
		{
			DAOFactory.getIUserDAOInstance().doDelete(id);
		} catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void findId()
	{
		InputData input = new InputData();
		int id = input.getInt("请输入要查询的编号：", "编号必须是整数！");
		User user = null;
		
		try
		{
			user = DAOFactory.getIUserDAOInstance().findByID(id);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		if (user != null)
		{
			System.out.println(user);
		}
		else
		{
			System.out.println("要查找的用户不存在！");
		}
	}

	public static void findAll()
	{
		InputData input = new InputData();
		String keyWord = input.getString("请输入要查询的关键字：");
		List<User> allUser = null;
		try
		{
			allUser = DAOFactory.getIUserDAOInstance().findAll(keyWord);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		Iterator<User> iter = allUser.iterator();
		while (iter.hasNext())
		{
			System.out.println(iter.next());
		}
	}
}
