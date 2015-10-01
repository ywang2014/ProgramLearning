/*
 * 工厂使用代理，不使用具体操作的实现类
 */

package org.useradmin.factory;

import org.useradmin.dao.IUserDAO;
import org.useradmin.dao.proxy.IUserDAOProxy;


public class DAOFactory
{
	public static IUserDAO getIUserDAOInstance()
	{
		return new IUserDAOProxy();
	}
}
