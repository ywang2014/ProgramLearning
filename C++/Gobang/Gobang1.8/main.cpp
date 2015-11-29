/********************************************************************************************
*
* 五子棋项目程序
*
*   简介：二次开发，磨练项目开发能力
*   语言：C++
*   技能：面向对象、封装、多态、剪枝算法
*   项目想法：来自于杨立祥老师的C++课程、张文生老师的人工智能课程
*
*   优化想法来自于《代码大全》
*       为所有自然界的对象都创建一个类
*       隐藏实现细节
*       version1.5 计划实现接口、语义一致性
*
*   @date:      2015-09-30
*   @author:    ywang
*   @versiom:   1.2
*   @right:     It can only be used for study unless be authorized by the author!
*
**********************************************************************************************/

#include <iostream>
#include "gobang.h"
#include <windows.h>
#include "test.h"


using namespace std;

int main()
{
    Gobang gob;
    gob.gameShow();
    //test t;
    //t.pcb->showBoard();

    return 0;
}




