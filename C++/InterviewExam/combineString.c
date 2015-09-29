/*
笔试题目：

字符串拼接函数：
    一个 unsigned long 变量，需要转化为字符串
    一个 char 数组
    输入：20150929
		 "date"
	输出："20150929_date"
*/

#include <stdio.h>
#include <stdlib.h>

char* CombineString(unsigned long version, char *vendor);
char inttochar(int n);
void GetData(char *buffer, int length, int index)
{
    //
    return ;
}

int main()
{
    unsigned long version = 0;
    char vendor[100];
    char *p;

    scanf("%ld", &version);
    scanf("%s", vendor);

    p = CombineString(version, vendor);

    printf("%s\n", p);
    return 0;
}

char* CombineString(unsigned long version, char *vendor)
{
    char *p = vendor;
    char* int2c =(char*)malloc(sizeof(char) * 100); // 必须开空间，否则返回的指针无效！
    int i = 0;
    int j = 0;
    long k = version;

    for (i = 0; i < 100; i++)
    {
        int2c[i] = '\0';
    }

    if (k == 0)
    {
        int2c[0] = '0';
    }
    else
    {
        i = 1;
        while (k > 0)
        {
            k /= 10;
            i *= 10;
        }

        i = i / 10;
        j = 0;

        while (version > 0 && i > 0)
        {
            int2c[j++] = inttochar(version / i);
            version %= i;
            i /= 10;
        }
    }

    int2c[j++] = '_';

    while (*p != '\0')
    {
        int2c[j++] = *p++;
    }

    int2c[j] = '\0';

    vendor = int2c;
    return vendor;
}

char inttochar(int n)
{
    switch (n)
    {
        case 0: return '0'; break;
        case 1: return '1'; break;
        case 2: return '2'; break;
        case 3: return '3'; break;
        case 4: return '4'; break;
        case 5: return '5'; break;
        case 6: return '6'; break;
        case 7: return '7'; break;
        case 8: return '8'; break;
        case 9: return '9'; break;
        default: return '\0'; break;
    }
}

