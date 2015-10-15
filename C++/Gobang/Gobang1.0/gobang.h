/*******************************************************
    五子棋类

        第一步抽象：继承于棋类游戏的共性
        第二步抽象：五子棋游戏的特性

            棋盘大小：14*14 (可智能选择)
            棋子：黑白色两种
            双人对弈

            游戏规则：
                一人一步，在棋盘上放子：棋子必须在空位置上
                当某一色棋子中有大于等于5颗棋子在一条线(横、竖、对角线)上的时候，则胜利
                先手必须有禁手：平衡先手优势


********************************************************/
#include "chessgame.h"

#ifndef __GOBANG__
#define __GOBANG__


struct ChessBoard
{
    int color;  // 0代表无子，1代表黑子，2代表白子
    int sequenceNumbersXX;    // 连子数: 水平方向
    int sequenceNumbersXY;    // 连子数：45度方向
    int sequenceNumbersYY;    // 连子数：竖直方向
    int sequenceNumbersYX;    // 连子数：135度方向
};

class Gobang: public ChessGame
{
private:
    int boardSize;  // 棋盘大小
    ChessBoard **board;    // 棋盘

    /*
        棋盘副本，用于存储游戏的上一步状态，用于悔棋一步！
        或者保存每一步棋的状态与文件中，悔棋则读取相应的文件，并删除
        游戏结束时，可选择保存游戏记录，默认删除游戏记录
    */
    ChessBoard **boardCopy;    // 棋盘副本

public:
    Gobang(int );
    ~Gobang();
    int referee();
    void player();
    void show();
    void initial();
    void retract();
};


#endif // __GOBANG__

