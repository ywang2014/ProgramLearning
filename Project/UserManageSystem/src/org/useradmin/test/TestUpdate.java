package org.useradmin.test;

import java.util.Date;
import java.util.Scanner;

import org.useradmin.factory.DAOFactory;
import org.useradmin.vo.User;

public class TestUpdate
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		User user = new User();
		
		System.out.println("Please input the id of the item which you want to modify:");
		int id = input.nextInt();
		user.setId(id);
		
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
			DAOFactory.getIUserDAOInstance().doUpdate(user);
		} catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}