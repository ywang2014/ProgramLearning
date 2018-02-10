package org.useradmin.test;

import java.util.Scanner;

import org.useradmin.factory.DAOFactory;

public class TestDelete
{
	public static void main(String[] args) throws Exception
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Please input the id which item will be deleted:");
		int id = input.nextInt();

		input.close();
		
		DAOFactory.getIUserDAOInstance().doDelete(id);
	}
}