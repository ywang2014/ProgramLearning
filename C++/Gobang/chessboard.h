/*******************************************************
    五子棋实现的辅助类

        棋盘类的声明：

********************************************************/

#ifndef __CHESSBOARD_H
#define __CHESSBOARD_H

#include "chesspieces.h"

class ChessBoard
{
    // 棋盘是有一个一个的点组成的，如此才有棋盘矩阵！,这种思路不好，冗余太多，棋盘差不多退化成了棋子，一个一个的
    // 棋盘就是棋子矩阵，是一个矩阵，显示为棋盘，元素是棋子，具有显示棋子的功能

private:
    static int BOARDSIZE;
    int numPieces;  // 棋子数

public:

    ChessPieces **pBoard;       // 棋盘

    ChessBoard();
    ChessBoard(int n);
    ~ChessBoard();

    void init();    // 再来一局，需要初始化

    void setPieces(int x, int y, int color);

    int getBoardSize(void);

    void showBoard();

    bool fullBoard();
};

#endif // __CHESSBOARD_H


