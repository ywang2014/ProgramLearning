/*******************************************************
    五子棋实现的辅助类

        棋子类的声明

********************************************************/

#ifndef __CHESSPIECES_H
#define __CHESSPIECES_H

class ChessPieces
{

private:
    enum eColor{BLANK, BLACK, WHITE};   // 定义颜色常量
    eColor color;
    static int directions;   // 0、45、90、135度方向
    int* lianzishu;         // 连子数：

public:

    ChessPieces();

    ~ChessPieces();

    void init();

    void setColor(int color);

    int getColor(void);

    void setLianzishu(int nums, int site);

    int getLianzishu(int site);

    int getMaxLianzishu();
};

#endif // ___CHESSPIECES_H


