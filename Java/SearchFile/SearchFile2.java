/**
 * @parameter: args
 * 		args[0]: 要扫描的目录
 * 		args[1]: 结果保存文件夹
 * @function: 读取目标文件夹里面的所有文件，子目录递归访问
 * 
 */
package Test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class SearchFile2
{
	BufferedWriter bw = null;
	static FileWriter fw = null;
	BufferedReader brInput = null;
	File dirFile = null;
	File txtFile = null;
	static int level;
	
	public SearchFile2()
	{
		this.level = 0;
		this.brInput = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public void createDirFile(String filename)
	{
		this.dirFile = new File(filename);
	}
	
	public void createTxtFile(String filename)
	{
		txtFile = new File(filename);
		if (! txtFile.exists())
		{
			try
			{
				txtFile.createNewFile();
				fw = new FileWriter(txtFile, false);
				bw = new BufferedWriter(fw);
			} catch (IOException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public boolean isTrueFile()
	{
		if (dirFile == null || ! dirFile.exists())
		{
			return false;
		}
		
		return true;
	}
	
	public void readPathAndDest()
	{
		String src = null;
		System.out.println("请输入目录路径，输入*quit退出！");
		try
		{
			while ((src = brInput.readLine()) != null)
			{
				if (src.equals("*quit"))
				{
					System.out.println("程序退出...");
					System.exit(0);
				}
				createDirFile(src);
				if (isTrueFile())
				{
					break;
				}
				else
				{
					System.out.println("Error: " + src + "no such directory or file!");
					System.out.println("Please input again!");
					System.out.println("请输入目录路径，输入*quit退出！");
				}
			}
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		String dst = null;
		System.out.println("请输入输出文件路径，输入*quit退出！");
		try
		{
			while ((dst = brInput.readLine()) != null)
			{
				if (dst.equals("*quit"))
				{
					System.out.println("程序退出...");
					System.exit(0);
				}
				createTxtFile(dst);
				break;
			}
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public String getName()
	{
		return dirFile.getName();
	}
	
	public File getFile()
	{
		return dirFile;
	}
	
	public static void searchDir(File file)
	{
		String charSeq = file.getName() + "/" + "\r\n";	// \n  \n\r不行
		try
		{
			fw.append(charSeq);
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		level++;
		
		File[] listFiles = file.listFiles();
		
		for (int i = 0; i < listFiles.length; i++)
		{
			if (listFiles[i].isFile())
			{
				String format = "";	// 不能使用 null, 否则输出null
				for (int j = 0; j < level; j++)
				{
					format += '\t';
				}
				format += listFiles[i].getName() + "\r\n";
				try
				{
					fw.append(format);
				} catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			else if (listFiles[i].isDirectory())
			{
				String format = "";
				for (int j = 0; j < level; j++)
				{
					format += '\t';
				}
				format += '\n';
				try
				{
					fw.append(format);
				} catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				searchDir(listFiles[i]);
			}
		}
	}
	
	
	public static void main(String[] args)
	{
		SearchFile2 sfile = new SearchFile2();
		
		if (args != null && args.length > 1)
		{
			sfile.createDirFile(args[0]);
			sfile.createTxtFile(args[1]);
			
			if (! sfile.isTrueFile())
			{
				System.out.println("Error: " + args[0] + "no such directory or file!");
				System.exit(0);
			}
		}
		else
		{
			sfile.readPathAndDest();
		}
		
		System.out.println("开始扫描目录：" + sfile.getName());
		
		searchDir(sfile.getFile());
		
		try
		{
			fw.flush();
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("扫描完成！");
	}
}
