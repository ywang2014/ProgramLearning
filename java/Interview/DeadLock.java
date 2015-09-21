/*
 * 美团面试题：死锁检测工具 jstack
 * 进程死锁问题: 进程占有一些资源(锁)，等待一些资源(锁)
 * 输入：字符串总数 n
 * 		n行：进程id 占有锁id(列表',') 等待锁id(列表',') 空格表示无资源!!!
 * 		example
 * 		7
 * 		123 1001,1002 1003
 * 		127   1100
 * 		128 1010
 * 		129
 * 		124 1007 1008
 * 		125 1003 1004
 * 		126 1004 1002
 * 输出：死锁数字  int
 * 		1
 * 
 */

package Test;

import java.util.*;
import java.io.*;

public class DeadLock
{
	public static void main(String[] args) throws IOException
	{
		Scanner input = new Scanner(System.in);
		int n;
		if(input.hasNext())
			n = (int) input.nextInt();
		else 
			n=0;
		
		ArrayList[] id_have = new ArrayList[n];
		ArrayList[] id_wait = new ArrayList[n];
		for (int i = 0; i < n; i++)
		{
			id_have[i] = new ArrayList();
			id_wait[i] = new ArrayList();
		}
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str_in = new String();
		
		for (int i = 0; i< n; i++)
		{
			str_in = br.readLine();
			char char_in[] = str_in.toCharArray();
			String num[] = str_in.split(" ");
			
			//int leng = str_in.length(); // 包含空格
			int len = num[0].length();
			int leng = num.length;
			
			if (leng == 1)
			{
				// 没有占有进程和等待进程
				continue;
			}
			else if (leng == 2)
			{
				if (char_in[len] == ' ')
				{
					// 没有占有进程
					String wait[] = num[1].split(",");
					for (int w = 0; w < wait.length; w++)
					{
						// 正好直接字符串存储
						id_wait[i].add(wait[w]);
					}
				}
				else
				{
					// 没有等待进程
					String have[] = num[1].split(",");
					for (int h = 0; h < have.length; h++)
					{
						id_have[i].add(have[h]);
					}
				}
			}
			else
			{
				String have[] = num[1].split(",");
				for (int h = 0; h < have.length; h++)
				{
					id_have[i].add(have[h]);
				}
				
				String wait[] = num[2].split(",");
				for (int w = 0; w < wait.length; w++)
				{
					id_wait[i].add(wait[w]);
				}
			}
		}
		
		input.close();
		br.close();
		
		// 求解死锁
		int counter = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int flag = 0;
			
			Iterator it_h = id_have[i].iterator();
			while (it_h.hasNext())
			{
				int id_h = Integer.parseInt((String)it_h.next());
				
				for (int j = i + 1; j < n; j++)	// j = i+1 往前递推，不重复
				{
					Iterator it_w = id_wait[j].iterator();
					while (it_w.hasNext())
					{
						int id_w = Integer.parseInt((String)it_w.next());
						
						if (id_h == id_w)
						{
							flag = 1;	// 不能简单的counter++
						}
					}
				}
			}
			
			// 一次同时遍历等待和占有锁资源的列表，可以消去一个进程与多个进程抢资源的矛盾问题！
			// 不能消去 A -> B  B -> C 的情况，因为A已经先考虑了，除非先考虑B
			Iterator it_w2 = id_wait[i].iterator();
			while (it_w2.hasNext())
			{
				int id_w2 = Integer.parseInt((String) it_w2.next());
				
				for (int j = i + 1; j < n; j++)
				{
					Iterator it_h2 = id_have[j].iterator();
					while (it_h2.hasNext())
					{
						int id_h2 = Integer.parseInt((String) it_h2.next());
						
						if (id_h2 == id_w2)
						{
							flag = 1;	// 不能简单的counter++
						}
					}
				}
			}
			
			if (flag == 1)
			{
				counter++;
			}
		}
		
		System.out.println(counter);
		
	}
}



/*****************************************

 		Scanner input = new Scanner(System.in);
		int n;
		if(input.hasNext())
			n = (int) input.nextInt();
		else 
			n=0;
		
		int[][] id_have = new int[n][10];	// 假设仅有10个资源
		int[][] id_wait = new int[n][10];	// 假设仅有10个资源
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str_in = new String();
		
		for (int i = 0; i< n; i++)
		{
			str_in = br.readLine();
			
			// 单个字符解析，数组越界，抛出异常
			char char_in[] = str_in.toCharArray();
			int len = char_in.length;
			
			int j = 0;
			int k = 0;
			int t = 0;
			
			// 解析进程号
			String res = new String("");
			while (char_in[j] != ' ')
			{
				res += char_in[j++];
			}
			id_have[i][k++] =  Integer.parseInt(res);	// 放在id_have[][0]处
				
			// 解析占有进程号
			if (char_in[j+1] == ' ')
			{
				j = j + 3;
			}
			else
			{
				j = j + 1;
				while(true)
				{
					res = new String("");
					while (char_in[j] != ',' && char_in[j] != ' ')
					{
						res += char_in[j++];
					}
					id_have[i][k++] = Integer.parseInt(res);
					if (char_in[j] == ',')
					{
						j = j + 1;
					}
					else if (char_in[j] == ' ')
					{
						j = j + 1;
						break;
					}
				}
			}
			
			// 解析等待进程号
			if (char_in[j] != ' ')
			{
				while(j < len)
				{
					res = new String("");
					while (j < len && char_in[j] != ',' && char_in[j] != ' ')
					{
						res += char_in[j];
						j++;
					}
					id_wait[i][t++] =  Integer.parseInt(res);
					if (j < len && char_in[j] == ',')
					{
						j = j + 1;
					}
					else // if (j < len && char_in[j] == ' ')
					{
						break;
					}
				}
			}
		}
		
7
123 1001,1002 1003
127   1100
128 1010  
129    
124 1007 1008
125 1003 1004
126 1004 1002
 
 *****************************************/
