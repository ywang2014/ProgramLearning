/*******************************************************
    棋类游戏的基类

        第一步抽象：继承于游戏的共性
        第二步抽象：棋类游戏的共性

            棋盘
            棋子
            多为对弈
            可悔棋

********************************************************/
#include "game.h"

#ifndef __CHESSGAME__
#define __CHESSGAME__

class ChessGame: public Game
{
public:
    // ChessGame();
    // ~ChessGame();
    virtual int referee() = 0;
    virtual void player() = 0;
    virtual void show() = 0;
    virtual void initial() = 0;
    void menu();
};

#endif // __CHESSGAME__
