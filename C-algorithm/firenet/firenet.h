/**
* 非递归方法
*/
#include <stdio.h>

struct node
{
    int row;
    int column;
    char flag;
};

int flag_stack[16]; //数组当做栈用。
int flag_rank;


Phinecos(洞庭散人)
专注于开源技术的研究与应用
ZOJ1002 Fire Net(非递归版）

以前用递归的回溯搜索思路做过一次，参见ZOJ1002 Fire Net(递归版)，今天想着用非递归的方法试试看，呵呵，比我想象中要难啊，主要还是堆栈里究竟放什么，这一点上思路一直没理清。因此用了整整一天的时间，总算用非递归的方法把1002给AC掉了，在代码中我引入了堆栈层次的概念，模拟系统堆栈的行为，并且在搜索时加入了剪枝，但代码写得还是很烂，继续思考如何改进。
复制代码
/********************************
Written by : phinecos(洞庭散人)
Data       : 2/11/2008 16:30
Description: 非递归，模拟系统堆栈解决类似八皇后问题
State : Accepted
Run Time: 0ms
Run Memory:    184KB
****************************************/

#include<iostream>
#include <stack>
using namespace std;

const int MAXSIZE = 4;// 地图最大大小
char map[MAXSIZE][MAXSIZE];// 地图
int maxNum,n;

struct Node
{
    int row;//行
    int col;//列
    int level;//当前层次
};

bool CanPut(int row, int col)
{//测试是否可以放置碉堡到row行col列处，因为位置是从小到大前进的，因此只需要测试比待测试点小的位置
    int i;
    //测试col列上是否有面对面的碉堡
    for (i = row - 1; i >= 0; --i)
    {
        if (map[i][col] == 'O') return false;
        if (map[i][col] == 'X') break;
    }
    //测试row行上是否有面对面的碉堡
    for (i = col - 1; i >= 0; --i)
    {
        if (map[row][i] == 'O') return false;
        if (map[row][i] == 'X') break;
    }
    return true;
}

void Solve(int k,int curNum)
{
    stack<Node> s1;//解决树堆栈
    Node node;
    int row,col,i;
    int curLevel = 0;//当前层次

    //起始结点入栈
    node.row=k/n;
    node.col = k%n;
    node.level = curLevel;//当前堆栈层次是第0层
    s1.push(node);

    while (!s1.empty())
    {
        node = s1.top();
        row = node.row;
        col = node.col;

        if (map[row][col]=='.'&&CanPut(row,col)==true)
        {//map[row][col]空闲并且经测试可以放置,则占据此位置
            map[row][col] = 'O';
            //堆栈层次加1
            curLevel++;
            node.level = curLevel;//作为这个堆栈层此的排头兵
            s1.pop();
            s1.push(node);
            curNum++;//放置的棋子数目加1
        }

        if (row==n-1&&col==n-1)
        {//来到这个堆栈层的最后一个结点了
            if (curNum>maxNum)
            {//保存这一层的最大数目
                maxNum = curNum;
            }
            if (curLevel==0)
            {//若回到第0层，则说明已经考虑完所有情况了
                break;
            }

            /*
            *下面这段代码非常低级趣味，我居然用了两重while循环，It's rubbish,不喜勿进!!!!
            */

            //去掉当前堆栈层
            while (!s1.empty())
            {
                node = s1.top();
                if (node.level==curLevel)
                {
                    s1.pop();
                    --k;
                }
                else
                {
                    curLevel--;
                    curNum--;
                    break;
                }
            }
            //有一种情况是栈此时是空的，但还是需要将层次数和棋子数减1，因为循环中它给跳过去了。。。汗。
            if(s1.empty())
            {
                curLevel--;
                curNum--;
            }
            //将上一层的排头兵恢复回来（就是把'O'再此变回'.',并且层次改为这一层）
            ++k;
            row = k/n;
            col = k%n;
            map[row][col] = '.';
            node.row = row;
            node.col = col;
            node.level = curLevel;
            s1.push(node);
            //以上一层排头兵的下一个结点为起点，继续
            if (k+1<n*n)
            {
                ++k;
                node.row = k/n;
                node.col = k%n;
                node.level = curLevel;
                s1.push(node);
            }
            else
            {//当来到最后一个元素时，又有一个特殊的情形，此时当前层次所有情况都已经考虑完毕，因此需要将当前堆栈层给清空掉，哎，这个清空动作和前面是一样的，可居然又单独列了遍代码，吐了。。。
                if (curLevel==0)
                {
                    break;
                }
                while (!s1.empty())
                {
                    node = s1.top();
                    if (node.level==curLevel)
                    {
                        s1.pop();
                        --k;
                    }
                    else
                    {
                        curLevel--;
                        curNum--;
                        break;
                    }
                }

                if (s1.empty())
                {
                    curLevel--;
                    curNum--;
                }
                ++k;
                row = k/n;
                col = k%n;
                map[row][col] = '.';
                node.row = row;
                node.col = col;
                node.level = curLevel;
                s1.push(node);

                ++k;
                node.row = k/n;
                node.col = k%n;
                node.level = curLevel;
                s1.push(node);
            }

        }
        else
        {//还没来到这一堆栈层次的最后一个节点，继续吧
            ++k;
            node.row = k/n;
            node.col = k%n;
            node.level = curLevel;
            s1.push(node);
        }
    }
}

int main()
{
    int i,j;
    while(cin>>n&&n!=0)
    {
        //输入地图
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
        }
        maxNum=0;//最多可能放置的数目
        //开始深搜,起点设置为左上角
        Solve(0,0);
        cout<<maxNum<<endl;
    }
    return 0;
}


