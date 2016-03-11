/*************************************************
网易面试题：路灯
一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai，每盏灯可以覆盖到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。

输入描述:

每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。

输出描述:

输出答案，保留两位小数。


输入例子:

7 15
15 5 3 7 9 14 0


输出例子:

2.5

****************************************/

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

void myMerge(long long *arr, int lo, int mid, int hi);
void merge_sort(long long *arr, int lo, int hi);

int main()
{
    int n;
    long long l;
    while (cin >> n >> l)
    {
        long long *pos = new long long[n];
        for (int i = 0; i < n; i++)
        {
            cin >> pos[i];
        }

        merge_sort(pos, 0, n);

        double maxinterval = 0;
        for (int i = 0; i < n-1; i++)
        {
            long long temp = pos[i+1] - pos[i];
            if (maxinterval < temp)
            {
                maxinterval = temp;
            }
        }
        maxinterval /= 2.0;
        if (maxinterval < pos[0])   // 考虑左端点
        {
            maxinterval = pos[0];
        }
        if (maxinterval < l - pos[n-1]) // 考虑右端点
        {
            maxinterval = l - pos[n-1];
        }

        printf("%0.2f\n", maxinterval); // 不能使用 "%0.2lf"?????

        delete[] pos;
    }

    return 0;
}

void myMerge(long long *arr, int lo, int mid, int hi)
{
    int i = 0, j= 0, k = 0;
    int l_len = mid - lo;   // 左边部分数组长度
    int r_len = hi - mid;   // 右边部分数组长度
    long long l_arr[l_len];
    long long r_arr[r_len];

    // 复制左右数组内容到临时数组
    /*
    * 换一种思路，直接此时排序到临时数组，排完序再复制回去即可！
    */
    for (i = 0; i < l_len; i++)
    {
        l_arr[i] = arr[lo+i];
    }
    for (i = 0; i < r_len; i++)
    {
        r_arr[i] = arr[mid+i];
    }

    i = lo;
    while (i < hi)
    {
        if (j < l_len && (k == r_len || l_arr[j] <= r_arr[k]))
        {
            arr[i++] = l_arr[j++];
        }
        if (k < r_len && (j == l_len || r_arr[k] < l_arr[j]))
        {
            arr[i++] = r_arr[k++];
        }
    }
}

void merge_sort(long long *arr, int lo, int hi)
{
    int mid = 0;

    // 左闭右开区间
    if (lo < hi - 1)
    {
        mid = (lo + hi) >> 1;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid, hi);
        myMerge(arr, lo, mid, hi);
    }
}

/** 总结
* 输入不能主观猜测输入一次怎么样的，最好使用：while(cin)
* 安全且完美！
* cout << setprecision(2) 保留2位小数，很奇怪，使用的是 2.5e5格式
* 算法题目一定要细心，注意边界情况！
* 学会使用语言库：algorithm 排序算法 Sort(arr, arr+n, cmp)
*
*/ 
