/*******************************************************
    五子棋实现的辅助类

        棋盘类的声明：

********************************************************/

#ifndef __CHESSBOARD_H
#define __CHESSBOARD_H

#include "chesspieces.h"

class ChessBoard
{

private:
    int BOARDSIZE;
    int numPieces;  // 棋子数

public:

    ChessPieces **pBoard;       // 棋盘

    /*
        使用默认参数的构造函数，更加高大上
        但是很奇怪，不能通过默认构造函数调用含参数的构造函数
        ？？？
    */
    ChessBoard(int n = 14);
    ~ChessBoard();

    void init();    // 再来一局，需要初始化

    void setPieces(int x, int y, int color);

    int getBoardSize(void);

    void showBoard();

    bool fullBoard();
};

#endif // __CHESSBOARD_H


