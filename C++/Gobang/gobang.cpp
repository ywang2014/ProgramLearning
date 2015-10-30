
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gobang.h"
#include "globalcontent.h"

using namespace std;

Gobang::Gobang()
{
    Gobang(0);
}

Gobang::Gobang(int flag)
{
    man = Player(MAN);
    timer = time(0);

    if (flag != 0)
    {
        // 人人对战游戏
        computer = Player(MAN);
    }
}


void Gobang::gameInitial()
{
    cBoard.init();
    timer = time(0);
}

/*
裁判：
    如果出现连子数大于等于5，则游戏结束，返回相应的棋子颜色，用于判断哪一方胜利
    根据 referee()函数的返回值，确定show()函数输出状态
    禁手检查??????????
*/
int Gobang::gameReferee()
{
    for (int i = 0; i < cBoard.getBoardSize(); i++)
    {
        for (int j = 0; j < cBoard.getBoardSize(); j++)
        {
            // 利用 && 符号的顺序点特性！
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

void Gobang::chessGameManage()
{
    gameInitial();
    gameMenu();
    gameShow();
}
