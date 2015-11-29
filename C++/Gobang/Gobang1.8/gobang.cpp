/*******************************************************
    五子棋实现的辅助类

        游戏类函数实现：

********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gobang.h"
#include "globalcontent.h"

using namespace std;

Gobang::Gobang()
{
    /*
        不能直接使用赋值，应该是赋值函数没有定义
        赋值运算符、拷贝构造函数
        可以使用对象指针，然后new创建对象
    */

    //cBoard = ChessBoard();    // 对象会自动析构
    timer = time(0);   // 计时 -- 倒计时方式
    /*cout << timer;
    exit(0);
    */
    man = Player(MAN);
}

Gobang::Gobang(int flag)
{
    Gobang();
    if (flag != 0)
    {
        computer = Player(MAN);
    }
}


void Gobang::gameInitial()
{
    cBoard.init();
    timer = time(0);
}

int Gobang::gameReferee()
{
    for (int i = 0; i < cBoard.getBoardSize(); i++)
    {
        for (int j = 0; j < cBoard.getBoardSize(); j++)
        {
            if (cBoard.pBoard[i][j].getColor() != 0 && cBoard.pBoard[i][j].getMaxLianzishu() >= 5)
            {
                return cBoard.pBoard[i][j].getColor();
            }
        }
    }

    return 0;
}

void showGameFinale(int flag)
{
    if (flag == 1)
    {
        cout << "Congratulations, BLACK win the game!" << endl;
    }
    else if (flag == 2)
    {
        cout << "Congratulations, WHITE win the game!" << endl;
    }
    else
    {
        cout << "Congratulations, the game end in a draw!" << endl;
    }
}

void Gobang::gamePlay()
{
    computer.play(cBoard, BLACK);
    man.play(cBoard, WHITE);
}

void Gobang::gameShow()
{
    system("cls");
    cout << "\n\n\n";
    cBoard.showBoard();
}

void Gobang::gameUndo()
{
    //
}

void Gobang::gameMenu()
{
    //
}

void Gobang::chessGameManage()
{
    gameInitial();
    gameMenu();
    gameShow();
}
