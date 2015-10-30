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

        第一次框架改建：2015-10-15 《代码大全》

********************************************************/

#include "chessgame.h"
#include "boardandpieces.h"

#ifndef __GOBANG__
#define __GOBANG__

class Gobang: public ChessGame
{
private:
    ChessBoard cBoard;
    int timer;   // 计时
    Player man;
    Player computer;

public:
    int gameReferee();
    void gamePlay();
    void gameShow()
    {
        show();
    }
    void show();
    void gameInitial();
    void gameUndo();
    void chessGameManage();
};


#endif // __GOBANG__

/***********************************************************************************
#include "chessgame.h"

#ifndef __GOBANG__
#define __GOBANG__

enum eColor{BLACK, WHITE, GRAY};

class ChessPieces
{
private:
    static int amount;  // 总的棋子数
    static int usedAmout;   // 已经使用棋子数
    eColor color;
    int shape;
    int psize;      // 棋子大小

public:
    ChessPieces()
    {
        color = GRAY;
        usedAmout++;
    }

    static void init(int amounts)
    {
        amount = amounts;
        usedAmout = 0;
    }

    void setColor(int color)
    {
        this->color = (eColor)color;
    }

    eColor getColor(void)   // 使用的时候，int()强制类型转换即可！
    {
        return color;
    }
};

class ChessBoard
{
    // 棋盘是有一个一个的点组成的，如此才有棋盘矩阵！
private:
    ChessPieces pieces;         // 棋盘上的棋子
    int sequenceNumbersXX;      // 连子数: 水平方向
    int sequenceNumbersXY;      // 连子数：45度方向
    int sequenceNumbersYY;      // 连子数：竖直方向
    int sequenceNumbersYX;      // 连子数：135度方向
public:
    ChessBoard()
    {
        board = new int*[BSIZE];
        for (int i = 0; i < BSIZE; i ++)
        {
            board[i] = new int[BSIZE];
        }
    }
    ~ChessBoard()
    {
        for (int i = 0; i < BSIZE; i ++)
        {
            delete [] board[i];
        }
        delete [] board;
    }

    void init()
    {
        // 这种模式很难初始化，各种问题！
        pieces.init();
    }
};

class Gobang: public ChessGame
{
private:
    int boardSize;  // 棋盘大小
    ChessBoard **board;    // 棋盘矩阵

    ************************************************************************
        棋盘副本，用于存储游戏的上一步状态，用于悔棋一步！
        或者保存每一步棋的状态与文件中，悔棋则读取相应的文件，并删除
        游戏结束时，可选择保存游戏记录，默认删除游戏记录
    ************************************************************************
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


************************************************************************************/
