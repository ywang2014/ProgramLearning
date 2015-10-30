/*******************************************************
    五子棋实现的辅助类

        游戏玩家类的声明：

********************************************************/

#ifndef __GAMEPLAYER_H
#define __GAMEPLAYER_H

#include "chessboard.h"
#include "globalcontent.h"

class Player
{
private:
    enum status{COMPUTER, MAN};
    status identity;   // 玩家身份

public :

    Player();

    Player(int identity);

    /* 类变量参数，使用引用！
       如此就可以实现玩家在棋盘上操作了！
    */
    void play(ChessBoard& cb, eColor color);

    void play(ChessBoard& cb);

    void manGetPiecesPosition(int&x, int& y);

    void AIgetPiecesPosition(int& x, int& y);

    void movePieces(ChessBoard& cb, int x, int y, eColor color);

};


#endif // __GAMEPLAYER_H

