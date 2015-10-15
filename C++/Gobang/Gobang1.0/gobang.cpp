#include "gobang.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Gobang::Gobang(int n)
{
    boardSize = n;

    board = new ChessBoard*[boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = new ChessBoard[boardSize];
    }
}

Gobang::~Gobang()
{
    for (int i = 0; i < boardSize; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

/*
裁判：
    如果出现连子数大于等于5，则游戏结束，返回相应的棋子颜色，用于判断哪一方胜利
    根据 referee()函数的返回值，确定show()函数输出状态
    禁手检查??????????
*/
int Gobang::referee()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j].color == 0)
            {
                continue;
            }

            if (board[i][j].sequenceNumbersXX >= 5 || board[i][j].sequenceNumbersXY >= 5 || board[i][j].sequenceNumbersYY >= 5 || board[i][j].sequenceNumbersYX >= 5)
            {
                // 直接返回，跳出函数
                return board[i][j].color;
            }
        }
    }

    return 0;
}


void Gobang::player()
{
    //
}

void Gobang::show()
{
    system("cls");
    cout << "\n\n\n";

    for (int i = 0; i < boardSize; i++)
    {
        cout << endl;
        for (int j = 0; j < boardSize; j++)
        {
            cout << "     ";
            // 特殊字符：┼ ┽ ┾┿╀╁╂╃╄╅╆╇╈╉╊╋  〇○●

            if (board[i][j].color == 0)
            {
                cout << "┼";
            }
            else if (board[i][j].color == 1)
            {
                cout << "●";
            }
            else
            {
                cout << "〇";
            }
        }
    }
}

void Gobang::initial()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j].color = 0;
            board[i][j].sequenceNumbersXX = 0;
            board[i][j].sequenceNumbersXY = 0;
            board[i][j].sequenceNumbersYY = 0;
            board[i][j].sequenceNumbersYX = 0;
        }
    }
}

void Gobang::retract()
{
    //
}
