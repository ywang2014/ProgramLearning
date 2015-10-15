/********************************************************************************************
*
* 五子棋项目程序
*
*   简介：二次开发，磨练项目开发能力
*   语言：C++
*   技能：面向对象、封装、多态、剪枝算法
*   项目想法：来自于杨立祥老师的C++课程、张文生老师的人工智能课程
*
*   @date:      2015-09-30
*   @author:    ywang
*   @versiom:   1.0
*   @right:     It can only be used for study unless be authorized by the author!
*
**********************************************************************************************/

#include <iostream>
#include "gobang.h"

using namespace std;

int main()
{
    std::cout << "我始终\n";
    Gobang gob = Gobang(14);
    gob.show();

    return 0;
}


/*
中文输出解决办法：
-fexec-charset = gbk
-finput-charset = utf-8

cygwin 改变了电脑的配置，使得成为了Linux系统！！！！
*/
