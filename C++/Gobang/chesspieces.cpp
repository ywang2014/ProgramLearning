/*******************************************************
    五子棋实现的辅助类

        棋子类的函数实现：

********************************************************/

#include "chesspieces.h"

int ChessPieces::directions = 4;

ChessPieces::ChessPieces()
{
    color = BLANK;
    lianzishu = new int[directions];
}

ChessPieces::~ChessPieces()
{
    delete [] lianzishu;
}

void ChessPieces::init()
{
    color = BLANK;
    for (int i = 0; i < directions; i++)
    {
        lianzishu[i] = 0;
    }
}

void ChessPieces::setColor(int color)
{
    this->color = (eColor)color;
}

int ChessPieces::getColor(void)   // 使用的时候，int()强制类型转换即可！
{
    return int(color);
}

void ChessPieces::setLianzishu(int nums, int site)
{
    lianzishu[site] = nums;
}

int ChessPieces::getLianzishu(int site)
{
    return lianzishu[site];
}

int ChessPieces::getMaxLianzishu()
{
    int maxnums = 0;
    for (int i = 0; i < directions; i++)
    {
        if (maxnums < lianzishu[i])
        {
            maxnums = lianzishu[i];
        }
    }
    return maxnums;
}



