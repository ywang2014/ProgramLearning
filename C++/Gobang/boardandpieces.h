/*******************************************************
    五子棋实现的辅助类

        第一次框架改建：2015-10-15 《代码大全》
        所有对象都创建一个类，完善面向对象
        加强数据的封装，隐藏信息

        棋子单独创建一个类
        棋盘创建一个类
        玩家创建一个类

        如何实现三个类的通信？？？？？

********************************************************/

#ifndef __BOARDANDPIECES__
#define __BOARDANDPIECES__

enum eColor{BLANK, BLACK, WHITE};

class ChessPieces
{
private:
    //static int amount;  // 总的棋子数
    //static int usedAmout;   // 已经使用棋子数
    eColor color;
    //int shape;
    //int psize;      // 棋子大小
    const int NUMBERS = 4;
    int* lianzishu;           // 连子数：0、45、90、135度方向

public:
    ChessPieces()
    {
        color = BLANK;
        lianzishu = new int[NUMBERS];
    }

    ~ChessPieces()
    {
        delete [] lianzishu;
    }

    void init()
    {
        color = BLANK;
        for (int i = 0; i < NUMBERS; i++)
        {
            lianzishu[i] = 0;
        }
    }

    void setColor(int color)
    {
        this->color = (eColor)color;
    }

    eColor getColor(void)   // 使用的时候，int()强制类型转换即可！
    {
        return color;
    }

    void setLianzishu(int nums, int site)
    {
        lianzishu[site] = nums;
    }

    int getLianzishu(int site)
    {
        return lianzishu[site];
    }

    int getMaxLianzishu()
    {
        int maxnums = 0;
        for (int i = 0; i < NUMBERS; i++)
        {
            if (maxnums < lianzishu[i])
            {
                maxnums = lianzishu[i];
            }
        }
        return maxnums;
    }
};



class ChessBoard
{
    // 棋盘是有一个一个的点组成的，如此才有棋盘矩阵！,这种思路不好，冗余太多，棋盘差不多退化成了棋子，一个一个的
    // 棋盘就是棋子矩阵，是一个矩阵，显示为棋盘，元素是棋子，具有显示棋子的功能

public:
    const int BOARDSIZE = 14;
    ChessPieces **pBoard;       // 棋盘

    ChessBoard()
    {
        pBoard = new ChessPieces*[BOARDSIZE];
        for (int i = 0; i < BOARDSIZE; i++)
        {
            pBoard[i] = new ChessPieces[BOARDSIZE];
        }
    }

    ~ChessBoard()
    {
        for (int i = 0; i < BOARDSIZE; i++)
        {
            delete [] pBoard[i];
        }
        delete [] pBoard;
    }

    ChessBoard& operator = (const ChessBoard &board)
    {
        pBoard = board.pBoard;
        return *this;
    }

    void init()
    {
        for (int i = 0; i < BOARDSIZE; i++)
        {
            for (int j = 0; j < BOARDSIZE; j++)
            {
                pBoard[i][j].init();
            }
        }
    }

    int getBoardSize(void)
    {
        return BOARDSIZE;
    }

    void showBoard()
    {
        // // 特殊字符：┼ ┽ ┾┿╀╁╂╃╄╅╆╇╈╉╊╋  〇○●
        // system("cls");
        for (int i = 0; i < BOARDSIZE; i++)
        {
            for (int j = 0; j < BOARDSIZE; j++)
            {
                if (pBoard[i][j].getColor() == BLANK)
                {
                 //   cout << "+";
                }
                else if (pBoard[i][j].getColor() == BLACK)
                {

                }
                else
                {

                }
            }
            //cout << "\n";
        }
    }
};

enum status{COMPUTER, MAN};

class Player
{
private:
    status identity;   // 玩家身份

public :
    void init(int identity)
    {
        this->identity = (status)identity;
    }

    void play(ChessBoard cb)
    {
        if (identity == COMPUTER)
        {
            computerPlay(cb);
        }
        else
        {
            manPlay(cb);
        }
    }

    // 如此就可以实现玩家在棋盘上操作了！
    void computerPlay(ChessBoard cb)
    {
        //TODO
    }

    void manPlay(ChessBoard cb)
    {
        // TODO
    }

};


#endif // __BOARDANDPIECES__

