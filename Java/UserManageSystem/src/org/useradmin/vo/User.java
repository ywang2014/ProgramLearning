package org.useradmin.vo;

import java.util.Date;

public class User
{
	private int id;
	private String name;
	private String sex;
	private Date birthday;
	
	public int getId()
	{
		return id;
	}
	public void setId(int id)
	{
		this.id = id;
	}
	
	public String getName()
	{
		return name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	
	public String getSex()
	{
		return sex;
	}
	public void setSex(String sex)
	{
		this.sex = sex;
	}
	
	public Date getBirthday()
	{
		return birthday;
	}
	public void setBirthday(Date birthday)
	{
		this.birthday = birthday;
	}
	
	public String toString()
	{
		return "编号：" + this.id + "；姓名：" + this.name + "；性别："
				+ this.sex + "；生日：" + this.birthday;
	}
}
