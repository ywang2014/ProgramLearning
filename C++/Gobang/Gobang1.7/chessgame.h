/*******************************************************
    棋类游戏的基类

        第一步抽象：继承于游戏的共性
        第二步抽象：棋类游戏的共性

            棋盘
            棋子
            多为对弈，两方、多方
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
    void gameMenu()
    {
        chessGameMenu();
    }
    void chessGameMenu();

    virtual void chessGameManage() = 0;
};

#endif // __CHESSGAME__
