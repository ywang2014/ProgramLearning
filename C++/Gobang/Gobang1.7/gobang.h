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
#include "chessboard.h"
#include "gameplayer.h"

#ifndef __GOBANG__
#define __GOBANG__

class Gobang: public ChessGame
{
private:
    ChessBoard cBoard;
    int timer;   // 计时 -- 倒计时方式
    Player man;
    Player computer;

public:

    Gobang();
    Gobang(int flag);
    int gameReferee();
    void gamePlay();
    void gameShow();
    void gameInitial();
    void gameUndo();
    void chessGameManage();
};


#endif // __GOBANG__

