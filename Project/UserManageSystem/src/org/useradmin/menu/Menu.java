package org.useradmin.menu;

import org.useradmin.operate.UserOperate;
import org.useradmin.util.InputData;

public class Menu
{
	public Menu()
	{
		while(true)
		{
			this.show();
		}
	}
	
	public void show()
	{
		System.out.println("========== MLDN人员管理系统 ==========");
		System.out.println("    1.增加用户");
		System.out.println("    2.修改用户");
		System.out.println("    3.删除用户");
		System.out.println("    4.查询单个用户");
		System.out.println("    5.查询全体用户");
		System.out.println("    6.退出系统");
		
		InputData input = new InputData();
		int ch = input.getInt("\n请选择：", "请输入正确的选项！");
		
		switch(ch)
		{
			case 1:
			{
				UserOperate.insert();
				break;
			}
			case 2:
			{
				UserOperate.update();
				break;
			}
			case 3:
			{
				UserOperate.delete();
				break;
			}
			case 4:
			{
				UserOperate.findId();
				break;
			}
			case 5:
			{
				UserOperate.findAll();
				break;
			}
			case 6:
			{
				System.exit(1);
				break;
			}
			default:
			{
				System.out.println("请选择正确的选项！");
				break;
			}
		}
	}
}
