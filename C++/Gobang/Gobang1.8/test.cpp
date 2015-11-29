#include <iostream>
#include "test.h"

test::test()
{
    //cb = ChessBoard();    // 很奇怪，不能这么使用？？？
    pcb = new ChessBoard(10);
    std::cout << "test\n";
}

test::~test()
{
    delete pcb;
    std::cout << "~test\n";
}
