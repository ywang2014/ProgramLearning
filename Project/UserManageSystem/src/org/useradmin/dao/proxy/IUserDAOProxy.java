/*
 * 接口实现类的代理类，专门负责数据库的链接和关闭
 * 		代理和实现类各司其职
 */

package org.useradmin.dao.proxy;

import java.util.List;
import org.useradmin.dao.IUserDAO;
import org.useradmin.dao.impl.IUserDAOImpl;
import org.useradmin.dbc.DataBaseConnection;
import org.useradmin.vo.User;


public class IUserDAOProxy implements IUserDAO
{
	private DataBaseConnection dbc = null;	// 负责完成链接
	private IUserDAO dao = null;	// 操作对象接口
	
	public IUserDAOProxy()
	{
		this.dbc = new DataBaseConnection();
		this.dao = new IUserDAOImpl(this.dbc.getConnection());
	}
	
	public boolean doCreate(User user) throws Exception	// 异常往上抛 
	{
		// TODO Auto-generated method stub
		boolean flag = true;
		try
		{
			flag = this.dao.doCreate(user);
		}
		catch (Exception e)
		{
			throw e;
		}
		finally
		{
			this.dbc.close();
		}
		return flag;
	}

	public boolean doUpdate(User user) throws Exception
	{
		// TODO Auto-generated method stub
		boolean flag = true;
		try
		{
			flag = this.dao.doUpdate(user);
		}
		catch (Exception e)
		{
			throw e;
		}
		finally
		{
			this.dbc.close();
		}
		return flag;
	}

	public boolean doDelete(int id) throws Exception
	{
		// TODO Auto-generated method stub
		boolean flag = true;
		try
		{
			flag = this.dao.doDelete(id);
		}
		catch (Exception e)
		{
			throw e;
		}
		finally
		{
			this.dbc.close();
		}
		return flag;
	}

	public User findByID(int id) throws Exception
	{
		// TODO Auto-generated method stub
		User user = null;
		try
		{
			user = this.dao.findByID(id);
		}
		catch (Exception e)
		{
			throw e;
		}
		finally
		{
			this.dbc.close();
		}
		return user;
	}

	public List<User> findAll(String keyWord) throws Exception
	{
		// TODO Auto-generated method stub
		List<User> all = null;
		try
		{
			all = this.dao.findAll(keyWord);
		}
		catch (Exception e)
		{
			throw e;
		}
		finally
		{
			this.dbc.close();
		}
		return all;
	}
}
