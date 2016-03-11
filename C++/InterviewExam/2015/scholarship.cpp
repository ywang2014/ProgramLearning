/**********************
网易笔试题： 奖学金
小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。

输入描述:

第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1

输出描述:

一行输出答案。

输入例子:

5 10 9
0 5
9 1
8 1
0 1
9 100

输出例子:

43

*********************************/

#include <iostream>
#include <algorithm>

using namespace std;

struct grade
{
    int a;
    int b;
};

bool cmp(grade a, grade b)
{
    return a.b < b.b;
}

int get_lchild(int i);
void heap_filter(grade *arr, int pivot, int n);
void heap_create(grade *arr, int n);

int main()
{
    int n, r, avg;

    while (cin >> n >> r >> avg)
    {
        long long total = n * avg;

        grade *gra = new grade[n];
        for (int i = 0; i < n; i++)
        {
            cin >> gra[i].a >> gra[i].b;
            total -= gra[i].a;
        }

        sort(gra, gra+n, cmp);

        long long time = 0;
        int i = 0;

        while (total > 0)
        {
            int bs = r - gra[i].a;
            if (total > bs && bs > 0) // bs = 0其实不影响的，但是不能为负，逻辑也说不过去！
            {
                time += bs * gra[i].b;
                total -= bs;
            }
            else if (total <= bs)
            {
                time += total * gra[i].b;
                break;
            }

            i++;
        }
        /****************************
        int len = n;
         while (total > 0)
        {
            int bs = r - gra[0].a;
            if (total > bs && bs > 0) // bs = 0其实不影响的，但是不能为负，逻辑也说不过去！
            {
                time += bs * gra[0].b;
                total -= bs;
            }
            else if (total <= bs)
            {
                time += total * gra[0].b;
                break;
            }

            gra[0] = gra[--len];
        }
        *****************************/

        cout << time << endl;
        delete[] gra;
    }

    return 0;
}


int get_lchild(int i)
{
    return 2 * i + 1;
}

void heap_filter(grade *arr, int pivot, int n)
{
    int i = pivot;
    int lchild = 0;
    int rchild = 0;
    grade temp;

    while (i < n)
    {
        lchild = get_lchild(i);
        rchild = lchild + 1;
        if (rchild <= n-1)  // 有右孩子的情况
        {
            // temp = (arr[lchild] < arr[rchild] ? arr[lchild] : arr[rchild])
            if (arr[lchild].b < arr[rchild].b)
            {
                if (arr[i].b > arr[lchild].b)
                {
                    temp = arr[i];
                    arr[i] = arr[lchild];
                    arr[lchild] = temp;
                    i = lchild; // 过滤下一层
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (arr[i].b > arr[rchild].b)
                {
                    temp = arr[i];
                    arr[i] = arr[rchild];
                    arr[rchild] = temp;

                    i = rchild; // 过滤
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (lchild == n - 1)   // 只有左孩子的情况
            {
                if (arr[i].b > arr[lchild].b)
                {
                    temp = arr[i];
                    arr[i] = arr[lchild];
                    arr[lchild] = temp;

                    i = lchild;
                }
            }

            break;  // 没有必要再继续了！
        }
    }
}

void heap_create(grade *arr, int n)
{
    int i = 0;

    // 建堆
    i = (n - 1) / 2;
    for (; i >= 0; i--)
    {
        heap_filter(arr, i, n);
    }
}
