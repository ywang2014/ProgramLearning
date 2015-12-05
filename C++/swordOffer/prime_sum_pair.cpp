/*
题目描述

NowCoder发现某些整数可以拆分成两个不同的素数的和。例如7=2+5、20=3+17=7+13等。他想知道每个正整数都有几种拆分的方法，你能帮他解决吗？ 
输入描述:

输入包括多组数据。
每组数据仅有一个整数n (1≤n≤100000)。


输出描述:

对应每个整数，输出其拆成不同素数和的个数，每个结果占一行。

输入例子:

30
26
20

输出例子:

3
2
2

*/

// write your code here cpp
#include <iostream>
#include <cstdio>

using namespace std;
static const int Nmax = 100001;

int main()
    {
    int n = 0;
    static bool prime[Nmax];
    static int prime_pair[Nmax] = {0};
    // initialize
    prime[0] = prime[1] = false;
    for(int i = 2; i < Nmax; i++)
    {
        prime[i] = true;
    }

    for (int i = 2; i < Nmax; i++)
    {
        if (prime[i])
        {
            for (int j = 2*i; j <= Nmax; j += i)
            {
                prime[j] = false;
            }
        }
    }

	static int *prime_num = new int[10000];	// 不超过10000的，简单处理如此！
	int prime_nums = 0;
	for (int i = 2; i < Nmax; i++)
	{
		if (prime[i])
		{
			prime_num[prime_nums++] = i;
		}
	}

    prime_pair[5] = 1;  // 5比较特殊
    for (int i = 7; i < Nmax; i++)
    {
        for (int j = 0; prime_num[j] < i/2; j++)  // 5比较特殊 需要等于		**j 肯定小于 prime_nums
        {
            if (prime[i-prime_num[j]])
            {
                prime_pair[i]++;
            }
        }
    }

    while ((scanf("%d", &n) != EOF))
        {
        printf("%d\n", prime_pair[n]);
    }

    return 0;
}


/*
// write your code here cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main()
    {
    int n = 0;
    static bool prime[100001];
    static int prime_pair[100001] = {0};
    // initialize
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 100000; i++)
    {
        prime[i] = true;
    }

    for (int i = 2; i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = 2*i; j <= 100000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 5; i <= 100000; i++)
    {
        for (int j = 2; j <= i/2; j++)  // 5比较特殊 需要等于
        {
            if (prime[j] && prime[i-j])
            {
                prime_pair[i]++;
            }
        }
    }

    for (int i = 0; i < 40; i++)
    {
        cout << prime_pair[i] << endl;
    }

    while ((scanf("%d", &n) != EOF))
        {
        printf("%d\n", prime_pair[n]);
    }

    return 0;
}
*/

/*
    速度太慢！
// write your code here cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main()
    {
    int n = 0;
    static bool prime[100001];
    // initialize
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 100000; i++)
    {
        prime[i] = true;
    }

    for (int i = 2; i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = 2*i; j <= 100000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    while ((scanf("%d", &n) != EOF))    // while (cin>>n)
        {
        int count = 0;
        if (n > 4)
        {
            int difference = 0;
            for (int i = 2; i <= n/2; i++)
                {
                if (prime[i])
                    {
                    difference = n - i;
                    if (i != difference && prime[difference])
                    {
                        count++;
                    }
                }
            }
        }

        printf("%d\n", count);;
    }

    return 0;
}
*/
