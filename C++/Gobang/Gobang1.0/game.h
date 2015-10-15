/*******************************************************
    游戏的基类

        第一步抽象：所有游戏的共性

        裁判：定义规则，判决胜负
        玩家：玩游戏者，一般最少一个，多为2个及以上
        界面：给出游戏的当前状态
        初始状态：游戏开始的时候，玩家所处的状态
        主菜单：游戏的菜单界面

        工具：游戏的辅助工具

********************************************************/

#ifndef __GAME__
#define __GAME__

class Game
{
public:
    // Game();
    // ~Game();
    virtual int referee() = 0;
    virtual void player() = 0;
    virtual void show() = 0;
    virtual void initial() = 0;
    virtual void menu() = 0;
};

#endif // __GAME__
