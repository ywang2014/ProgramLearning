#include <iostream>

using namespace std;

/*
递归算法：
自顶向下
*/

long long fib1(int n)
{
    if (n==1 || n==0)
    {
        return n;
    }
    return (fib1(n-1)+fib1(n-2));
}

/*
动态规划算法：
自底向上
*/

long long fib2(int n)
{
    if (n==1 || n==0)
    {
        return n;
    }
    long long f1 = 0, f2 = 1;
    for (int i=1;i<n;i++)
    {
        f2 += f1;
        f1 = f2 - f1;
    }
    return f2;
}

/*
记忆算法：记录表
自顶向下
计算过的存表，未计算法的则计算
？？？？？？？？？？？？？
*/

void fib3(long long *array, int n)
{
    array[0] = 0;
    array[1] = 1;
    for (int i=1; i<n; i++)
    {
        array[i+1] = array[i] + array[i-1];
    }
}

int main()
{
    int n=50;
    long long *array = new long long[n];
    fib3(array, n);
    for (int i=0; i<50; i++)
    {
        cout << "fib3=" << array[i] << endl;
    //    cout << "fib2=" << fib2(i) <<endl;
    //    cout << "fib1=" << fib1(i) <<endl;
    }
    return 0;
}
