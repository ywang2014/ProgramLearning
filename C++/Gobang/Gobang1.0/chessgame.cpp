#include "chessgame.h"
#include <iostream>
#include <cstdlib>

void ChessGame::menu()
{
    using namespace std;

    system("cls");
    cout << "     ------------------ 欢迎来到棋类游戏世界 ------------------" << endl;
    cout << endl;
    cout << "     ------------------------ 游戏菜单 ------------------------" << endl;
    cout << endl;
    cout << "     1.单人游戏 " << endl;
    cout << "     2.双人游戏 " << endl;
    cout << "     3.游戏帮助 " << endl;
    cout << "     4.作者介绍 " << endl;
    cout << "     0.退出游戏 " << endl;
}
