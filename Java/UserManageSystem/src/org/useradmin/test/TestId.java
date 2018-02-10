package org.useradmin.test;

import org.useradmin.factory.DAOFactory;
import org.useradmin.vo.User;

public class TestId
{
	public static void main(String[] args) throws Exception
	{
		User user = DAOFactory.getIUserDAOInstance().findByID(1);
		System.out.println(user);
	}
}