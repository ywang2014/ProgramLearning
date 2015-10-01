/*
 * 在实际的开发中，操作数据库的最前端代码是不能出现任何sql包的导入语句
 */

package org.useradmin.test;

import java.util.Date;
import java.util.Scanner;

import org.useradmin.factory.DAOFactory;
import org.useradmin.vo.User;

public class TestInsert
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		User user = new User();
		
		System.out.println("Please input the item which you want to insert:");
		System.out.println("Please input the name:");
		String name = input.next();
		user.setName(name);
		
		System.out.println("Please input the sex:");
		String sex = input.next();
		user.setSex(sex);

		input.close();
		
		user.setBirthday(new Date());
		try
		{
			DAOFactory.getIUserDAOInstance().doCreate(user);
		} catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}