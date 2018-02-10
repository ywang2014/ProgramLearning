/*
 * 操作接口：制定表的完整操作标准
 * 
 * 接口命名：加上"I"
 * 		接口名与要操作的代码进行关联
 * 		DAO：数据库操作对象，表示的是操作数据的
 * 
 * ###############################################################
 * 1.所有程序在设计的时候，都应该以接口为操作标准
 * 2.每一个类只完成一个具体的功能，如果有多个功能，则要分开类进行实现
 * 3.本程序中菜单和操作类都不是重点，关键是数据操作类和接口的关系
 
 * 4.工厂设计和代理设计是在开发中使用最多的设计思路，重点掌握！！！！
 
 * 5.集合操作在开发中此种情况使用的是最多的
 * 
 * 先学习思想，再创新和改革
 */

package org.useradmin.dao;

import java.util.List;
import org.useradmin.vo.User;

public interface IUserDAO
{
	/**
	 * 表示数据库的添加操作、更新操作
	 * 
	 * @param user
	 * @return
	 * @throws Exception
	 * @author ywang
	 */
	public boolean doCreate(User user) throws Exception;
	
	public boolean doUpdate(User user) throws Exception;
	
	/**
	 * 表示数据库的删除操作
	 * 
	 * @param id(int)
	 * @return
	 * @throws Exception
	 * @author ywang
	 */
	public boolean doDelete(int id) throws Exception;
	
	/**
	 * 表示数据库的查询操作
	 * 
	 * @param id(int)
	 * @return
	 * @throws Exception
	 * @author ywang
	 */
	public User findByID(int id) throws Exception;
	
	/**
	 * 数据库的查询操作，返回一组对象
	 * 
	 * @param id(int)
	 * @return
	 * @throws Exception
	 * @author ywang
	 */
	public List<User> findAll(String keyWord) throws Exception;
}
