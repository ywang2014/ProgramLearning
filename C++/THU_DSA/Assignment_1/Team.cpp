/**
THU2014 1-1 Team
描述
　　教练员A、B和C将要从编号为1到n的队员中挑选自己的队员。为公平起见，每个教练都根据自己的喜好程度将队员排序；你负责根据以下规则为他们分配队员。

　　你拿到的数据是a、b、c三个数组，表示三个教练对队员的喜好程度排序，每个数组都是数字1到n的一个排列，下标越小表示教练越喜欢该队员。你的分组规则是，从还未被分配的队员中找一个教练A最喜欢的队员分到A组；然后，在未分配的队员中分配教练B最喜欢的队员到B组；然后是教练C；再是教练A、B......依次类推直到所有队员分配完毕。

　　现在队员k希望知道自己被分配给哪位教练，请你来告诉他。

输入
　　共5行。

　　第1行包含一个整数n。

　　第2至4行依次是数组a、b和c，每行都是整数[1, n]的一个排列。

　　第5行包含一个整数k。

输出
　　仅一个字符，A、B或C，表示队员k被分配给哪位教练。

输入样例1

3
1	2	3
1	2	3
1	2	3
3
输出样例1

C
输入样例2

5
1	2	3	4	5
1	3	5	4	2
5	4	3	2	1
4
输出样例2

B
限制
1 <= n <= 500,000

1 <= k <= n

时间：1 sec

空间：256 MB

*/

#include <stdio.h>
#include <memory.h>
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);

	// 三个教练对队员喜好程度数据
	int **member = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		member[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &member[i][j]);
		}
	}

	int k = 0;
	scanf("%d", &k);

	char *choice = new char[n];
	memset(choice, 0, n);

	int index_a = 0;
	int index_b = 0;
	int index_c = 0;
	int num_people = 0;
	while (num_people < n)
	{
		// 第一步，A教练选择
		while (index_a < n && choice[member[0][index_a]] != 0)
		{
			index_a ++;
		}
		if (num_people < n)
		{
			choice[member[0][index_a]] = 'A';
            num_people++;
		}
		else
		{
			break;
		}

		// 第二步，B教练选择
		while (index_b < n && choice[member[1][index_b]] != 0)
		{
			index_b ++;
		}
		if (num_people < n)
		{
			choice[member[1][index_b]] = 'B';
			num_people++;
		}
		else
		{
			break;
		}

		// 第三步，C教练选择
		while (index_c < n && choice[member[2][index_c]] != 0)
		{
			index_c ++;
		}
		if (num_people < n)
		{
			choice[member[2][index_c]] = 'C';
			num_people++;
		}
		else
		{
			break;
		}
	}

	printf("%c\n", choice[k]);

	return 0;
}


/*******************  第一次提交的源代码	**/
#include <stdio.h>


int que_search(int * arr,int hi,int key);
int search(int *a,int *b,int *c,int ,int k);

int main()
{
	int i=0;
	int n=0;
	scanf("%d",&n);
	int * a = new int[n];
	int * b = new int[n];
	int * c = new int[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	int k=0;
	scanf("%d",&k);

	int flag=0;
	flag=search(a,b,c,n,k);
	switch(flag)
	{
	case 1 : printf("A");break;
	case 2 : printf("B");break;
	case 3 : printf("C");break;
	default : printf("return error!");
	}

	return 0;
}

int search(int *a,int *b,int *c,int n,int k)
{
	int i=0;
	int * array = new int[n];
	int j1=0;
	int j2=0;
	int j3=0;
	if(k == a[0])
	{
		return 1;
	}
	else array[0]=a[j1++]; 
	int ii=0;
	for(i=1;i<n;i++)
	{
		switch(i%3)
		{
		case 0 :
			{
				while(que_search(array,i-1,a[j1])!=-1)//查找成功，说明挑选了，不能挑选。
				{
					j1++;
				}
				if(k == a[j1])
				{
					return 1;
				}
				else array[i]=a[j1++]; 
				break;
			}
		case 1 :
			{
				while(que_search(array,i-1,b[j2])!=-1)//查找成功，说明挑选了，不能挑选。
				{
					j2++;
				}
				if(k == b[j2])
				{
					return 2;
				}
				else array[i]=b[j2++];
				break;
			}
		case 2 :
			{
				while(que_search(array,i-1,c[j3])!=-1)//查找成功，说明挑选了，不能挑选。
				{
					j3++;
				}
				if(k == c[j3])
				{
					return 3;
				}
				else array[i]=c[j3++];
				break;
			}
		default : printf("error!");
		}
	}

	return 0;
}

int que_search(int * arr,int hi,int key)
{
	while(hi>=0)
	{
		if(key==arr[hi--]) return 0;
	}
	return -1;
}
