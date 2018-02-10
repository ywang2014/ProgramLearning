/**
 * 功能：在当前路径下的所有文件中，查找给定的字符串
 * @parameter: args[]
 */
package Test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class DirectorySearch
{
	static int mount = 0;
	
	public static void main(String[] args)
	{
		if (args.length > 0)
		{
			String filename = "D:\\Soft\\eclipse\\workspace\\Exercise\\src";	// "./"可行:即为当前目录	 "../"不可行 		当前目录为Excercise
			File file = new File(filename);
			findFile(file, args[0]);
			printResult(args[0]);
		}
	}
	
	static boolean isTrueFile(File file)
	{
		if (!file.exists())
		{
			return false;
		}
		if (!file.canRead())
		{
			return false;
		}
		if (file.getName().startsWith("."))
		{
			return false;
		}
		if (file.getName().endsWith("."))
		{
			return false;
		}
		
		return true;
	}
	
	public static void findFile(File file, String word)
	{
		File[] listFiles = file.listFiles();
		for (int i = 0; i < listFiles.length; i++)
		{
			if (listFiles[i].isDirectory())
			{
				findFile(listFiles[i], word);
			}
			else if (isTrueFile(listFiles[i]))
			{
				try
				{
					SearchWords(listFiles[i], word);
				} catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
	public static void SearchWords(File file, String word) throws IOException
	{
		try
		{
			String str = null;
			FileReader fread = new FileReader(file);
			int ich = 0;
			while ((ich = fread.read()) != -1)
			{
				str += (char)ich;
			}
			if (str != null)
			{
				int j = 0, k = 0;
				while (str.indexOf(word, j) != -1)
				{
					k += 1;
					j = str.indexOf(word, j) + 1;
				}
				
				if (k > 0)
				{
					System.out.println("在\"" + file.getAbsolutePath() + "\"有" + k + "处");
					mount++;
				}
			}
			try
			{
				fread.close();
			} catch (IOException e1)
			{
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
	}
	
	public static void printResult(String word)
	{
		if (mount != 0)
		{
			System.out.println("\n------------------------------------\n");
			System.out.println("共找到 " + mount + " 个文本包含关键字\"" + word + "\"!");
			mount = 0;
		}
		else
		{
			System.out.println("没有一个文本包含此关键字！");
		}
	}
}
