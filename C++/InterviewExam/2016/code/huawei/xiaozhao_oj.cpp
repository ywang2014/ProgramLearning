/**
    华为在线试题
    http://ilearning.hwclouds.com/exam/
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include<algorithm>

using namespace std;

int main()
{
    string inputStr;
    vector<unsigned> orderedId;
    map<unsigned, unsigned> timer;
    while (cin >> inputStr){
        int colonPos = inputStr.find(':');
        string opt = inputStr.substr(0, colonPos);
        if (opt == "starttimer"){
            int commaPos = inputStr.find(',', colonPos);
            string id = inputStr.substr(colonPos + 1, commaPos - colonPos - 1);
            unsigned id_u = (unsigned)atoi(id.c_str());
            string time = inputStr.substr(commaPos + 1, inputStr.size() - commaPos);
            unsigned time_u = (unsigned)atoi(time.c_str());
            timer[id_u] = time_u;
            orderedId.push_back(id_u);
        }
        else if (opt == "stoptimer"){
            string id = inputStr.substr(colonPos + 1, inputStr.size() - colonPos - 1);
            unsigned id_u = (unsigned)atoi(id.c_str());
            timer[id_u] = 0;
            // 重复启动timer会有顺序问题，所以必须删除
            vector<unsigned>::iterator id_pos = find(orderedId.begin(), orderedId.end(), id_u);
            if (id_pos != orderedId.end()){
                orderedId.erase(id_pos);
            }
        }
        else if (opt == "elapse"){
            string time = inputStr.substr(colonPos + 1, inputStr.size() - colonPos - 1);
            unsigned elapse = (unsigned)atoi(time.c_str());
            map<unsigned, unsigned>::iterator it;
            for(it = timer.begin();   it != timer.end(); ++it){
                if (it->second > elapse){
                    it->second -= elapse;
                }
                else{
                    it->second = 0;
                }
            }
        }
        else{
            break;
        }
    }

    vector<unsigned>::iterator it;
    int hasTimer = 0;
    for(it = orderedId.begin();   it != orderedId.end(); ++it){
        if (timer[*it] > 0){
            hasTimer = 1;
            printf("timer:%u,%u\n", *it, timer[*it]);
        }
    }
    if (hasTimer == 0){
        printf("none\n");
    }

    return 0;
}


/**
    挑大写字母

    题目描述：
    编写一个函数，将字符串中的大写的字母(A~Z)挑出来，同时保留原字符串中的空格，将挑出的大写字母和空格按原始位置组成新
    的字符串。
    例如：
    1）输入：AUStralia；
       输出：AUS
    2）输入：He Is a DoG
       输出：H I DG

    运行时间限制:	1 Sec
    内存限制:	128 MByte
    输入:
    字符串
    输出:
    仅有大写字母和空格的字符串
    样例输入:
    AUStralia
    样例输出:
    AUS
*/
void getCapital(){
    char input;
    while ((input = getchar()) != EOF){
        if ((input >= 'A' && input <= 'Z') || input == ' '){
            putchar(input);
        }
    }
}

//#include <stdio.h>
//
//int main()
//{
//    getCapital();
//    return 0;
//}

/**
    剩余的文件数

    描述:
    在一个空的文件夹中，即可以装订增加文件数，也可以摘除减少文件数，在多次装订、摘除后，请输出最后剩余的文件数
    注：如果摘除的文件数大于当前的文件数，则将当前的文件全部摘除
    运行时间限制:	无限制
    内存限制:	无限制
    输入:
    装订文件数：
        binding 20
        表明装订20个文件

    摘除文件数:
        remove 20
        表明摘除20个文件

    结束装订摘除:
        end
    输出:
    当前文件夹的文件数
        current 20
        表明当前还有20个文件在文件夹中
    样例输入:
    binding 30
    remove 20
    binding 10
    remove 10
    end
    样例输出:
    current 10
*/

void getFileNum(){
    string operation;
    int fileNum = 0;
    long long res = 0;
    while (cin >> operation){
        //cout << operation << endl;
        if (operation == "binding"){
                cin >> fileNum;
            res += fileNum;
        }
        else if (operation == "remove"){
            cin >> fileNum;
            res -= fileNum;
            res = (res < 0 ? 0 : res);
        }
        else{
            break;
        }
    }
    cout << "current " << res << endl;
}

/**
    定时器
    描述:
    设计一个定时器管理系统，可以动态启动、停止定时器，并能根据已逝去的时长自动调整剩余的时长以及停止定时器
    运行时间限制:	1 Sec
    内存限制:	无限制
    输入:
    启动定时器：﻿starttimer:ID,time
    举例：
    starttimer:1,1000
       启动一个定时器,其ID为1，定时时长time为1000ms
    注：定时器ID用例保证非负整数；定时时长一定为正整数

    停止定时器:stoptimer:ID
    举例：
        stoptimer:1
        停止一个ID为1的定时器
    注：定时器ID用例保证非负整数；如果停止的定时器ID不存在，则忽略

    逝去时长:elapse:time
    举例：
        elapse:1000
        时间逝去1000ms
    注：用例保证时长一定为正整数

    输入结束
        end
    输出:
    按启动顺序输出还没有停止的定时器，如下ID为1的定时器还有1000ms才结束
    timer:1,1000

    如果所有定时器都停止了，输出none
    none
    样例输入:
    starttimer:1,1000
    starttimer:2,2000
    elapse:1000
    end
    样例输出:
    timer:2,1000
*/

void timer(){
    string inputStr;
    vector<unsigned> orderedId;
    map<unsigned, unsigned> timer;
    while (cin >> inputStr){
        int colonPos = inputStr.find(':');
        string opt = inputStr.substr(0, colonPos);
        //printf("%s\n", opt.c_str());
        if (opt == "starttimer"){
            int commaPos = inputStr.find(',', colonPos);
            string id = inputStr.substr(colonPos + 1, commaPos - colonPos - 1);
            //printf("%s\n", id.c_str());
            unsigned id_u = (unsigned)atoi(id.c_str());
            string time = inputStr.substr(commaPos + 1, inputStr.size() - commaPos);
            //printf("%s\n", time.c_str());
            unsigned time_u = (unsigned)atoi(time.c_str());
            timer[id_u] = time_u;
            orderedId.push_back(id_u);
        }
        else if (opt == "stoptimer"){
            string id = inputStr.substr(colonPos + 1, inputStr.size() - colonPos - 1);
            //printf("%s\n", id.c_str());
            unsigned id_u = (unsigned)atoi(id.c_str());
            timer[id_u] = 0;
            // 重复启动timer会有顺序问题，所以必须删除
            vector<unsigned>::iterator id_pos = find(orderedId.begin(), orderedId.end(), id_u);
            if (id_pos != orderedId.end()){
                orderedId.erase(id_pos);
            }
        }
        else if (opt == "elapse"){
            string time = inputStr.substr(colonPos + 1, inputStr.size() - colonPos - 1);
            // printf("%s\n", time.c_str());
            unsigned elapse = (unsigned)atoi(time.c_str());
            map<unsigned, unsigned>::iterator it;
            for(it = timer.begin();   it != timer.end(); ++it){
                if (it->second > elapse){
                    it->second -= elapse;
                }
                else{
                    it->second = 0;
                }
            }
        }
        else{
            break;
        }
    }

    vector<unsigned>::iterator it;
    int hasTimer = 0;
    for(it = orderedId.begin();   it != orderedId.end(); ++it){
        if (timer[*it] > 0){
            hasTimer = 1;
            printf("timer:%u,%u\n", *it, timer[*it]);
        }
    }
    if (hasTimer == 0){
        printf("none\n");
    }
}
