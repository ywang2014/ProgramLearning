package org.useradmin.test;

import java.util.Iterator;
import java.util.List;

import org.useradmin.factory.DAOFactory;
import org.useradmin.vo.User;

public class TestAll
{
	public static void main(String[] args) throws Exception
	{
		List<User> allUser = DAOFactory.getIUserDAOInstance().findAll("");
		Iterator<User> iter = allUser.iterator();
		while (iter.hasNext())
		{
			User user = iter.next();
			System.out.println(user);
		}
	}
}