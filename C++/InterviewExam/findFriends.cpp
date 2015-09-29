/**************************************************************
* 360面试题1
* 找老乡：
    输入: m,n   2个整数： m 代表有m个同学，n代表n组关系
        n行关系输入！
        继续 m,n
        ...
        m = 0, n = 0时，输入结束！

    输出：n    老乡个数

    规则：来自同一个地方的同学属于老乡。

    3 1
    2 4
    2 6

    2 (2号同学的老乡数)

    思路：不相交集
        来自同一个地方，则有相同的根节点，统计集合大小即可
        union() / find()
********************************************************************/


#include <iostream>

int students[1001]; // 学生数组，假设学生人数不超过1000

void init(int students[], int len);
int find(int stu);

int main()
{
    using namespace std;

    int stu1;
    int stu2;
//    int stu = 1;    // 需要寻找老乡数的同学，小妮

    while (true)
    {
        int m;
        int n;
        cin >> m >> n;
        if (m == 0 && n == 0)
        {
            break;
        }

        init(students, 1001);

        while (n--)
        {
            cin >> stu1 >> stu2;
            int root1 = find(stu1);
            int root2 = find(stu2);

            students[root1] += students[root2] - 1;

            students[stu2] = root1;
            students[root2] = root1;
 //           for (int i = 0; i <= m; i++)
 //           {
 //               cout << students[i] << endl;
 //           }
        }

        int poeple = 0 - students[find(1)];

        cout << poeple << endl;
    }
    return 0;
}

void init(int students[], int len)
{
    for (int i = 1; i < len; i++)
    {
        students[i] = 0;
    }
}

int find(int stu)
{
    if (students[stu] > 0)
    {
        return find(students[stu]);
    }
    return stu;
}
