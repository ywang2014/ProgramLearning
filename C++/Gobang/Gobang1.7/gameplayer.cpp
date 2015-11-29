/*******************************************************
    五子棋实现的辅助类

        游戏玩家类函数实现：

********************************************************/

#include <iostream>
#include "gameplayer.h"

Player::Player()
{
    identity = COMPUTER;    // 默认玩家角色为电脑
}

Player::Player(int identity)
{
    this->identity = (status)identity;
}

void Player::play(ChessBoard& cb, eColor color)    // 有利于实现人人对战
{
    //TODO
    int x = 0, y = 0;
    while (true)
    {
        manGetPiecesPosition(x, y);
        if (cb.pBoard[x][y].getColor() == BLANK)
        {
            break;
        }
        std::cout << "Sorry, (" << x << ", " << y << ") has a pieces!" << std::endl;
    }

    movePieces(cb, x, y, color);
}

void Player::play(ChessBoard& cb)
{
    int x = 0, y = 0;

    if (identity == MAN)
    {
        manGetPiecesPosition(x, y);
        movePieces(cb, x, y, WHITE);
    }
    else
    {
        AIgetPiecesPosition(x, y);
        movePieces(cb, x, y, BLACK);
    }
}

void Player::manGetPiecesPosition(int&x, int& y)
{
    using namespace std;

    while (true)
    {
        cout << "Please choose a position: x, y " << endl;
        cin >> x >> y;
        if (x < 0 || x > 13 || y < 0 || y > 13)
        {
            cout << "Sorry, your input is illegal, Please input again!";
        }
        else
        {
            break;
        }
    }
}

void Player::AIgetPiecesPosition(int& x, int& y)
{
    // TODO
}

void Player::movePieces(ChessBoard& cb, int x, int y, eColor color)
{
    cb.setPieces(x, y, color);
}


