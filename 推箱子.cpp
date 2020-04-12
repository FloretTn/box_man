#include <iostream>
#include <Windows.h>
#include <string>
#include <graphics.h>
#include <conio.h>

using namespace std;

#define  WIDTH  850  
#define  HEIGHT 700

#define  PIXEL  61

#define  LINE   9
#define  COLINE 12

#define  SKE_X  60
#define  SKE_Y  80

//热键控制
#define P_UP   'w'  //上
#define P_DOWN 's'  //下
#define P_LEFT 'a'  //左
#define P_RIGHT 'd'//右
#define P_break 'q' //退出

IMAGE images[6];

enum games_prop {
    WALL,      //墙
    FLOOR,     //地板
    BOX_DES,   //箱子目的地
    BOX,       //箱子
    MAN,       //人

};

enum _control {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

//游戏地图
int map[LINE][COLINE] = {
   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
   { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
   { 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
   { 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
   { 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 0 },
   { 0, 1, 1, 1, 0, 3, 1, 1, 1, 1, 1, 0 },
   { 0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
   { 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

struct _frame {
    int x;
    int y;
};

struct _frame man; //小人在二维数组中的位置

void games_control(enum _control direct) {

    struct _frame next_pos = man;
    struct _frame next2_pos = man;

    switch (direct) {
    case UP:
        next_pos.x--;
        next2_pos.x -= 2;
        break;
    case DOWN:
        next_pos.x++;
        next2_pos.x += 2;
        break;
    case LEFT:
        next_pos.y--;
        next2_pos.y -= 2;
        break;
    case RIGHT:
        next_pos.y++;
        next2_pos.y += 2;
        break;
    
    }

    if(isVaild)
     
}

int main(void) {
    IMAGE bg_img;

    //游戏背景
    initgraph(WIDTH, HEIGHT);
    loadimage(&bg_img, _T("bg.bmp"), WIDTH, HEIGHT, true);
    putimage(0, 0, &bg_img);

    //加载游戏道具
    loadimage(&images[WALL],   _T("wall.bmp"), PIXEL, PIXEL, true);
    loadimage(&images[FLOOR], _T("floor.bmp"), PIXEL, PIXEL, true);
    loadimage(&images[BOX_DES], _T("des.bmp"), PIXEL, PIXEL, true);
    loadimage(&images[BOX],     _T("box.bmp"), PIXEL, PIXEL, true);
    loadimage(&images[MAN],     _T("man.bmp"), PIXEL, PIXEL, true);

    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLINE; j++) {
            putimage(SKE_X + j * PIXEL, SKE_Y+i * PIXEL, &images[map[i][j]]);
        }
    }

    bool quit = false;

    do {

        if (_kbhit()) {
            char ch = _getch();

            if (ch == P_UP) {
                games_control(UP);
            }
            else if(ch==P_DOWN){
                games_control(DOWN);
            }
            else if (ch == P_LEFT) {
                games_control(LEFT);
            
            }
            else if (ch == P_RIGHT) {
                games_control(RIGHT);
            
            }
            else if (ch == P_break) {
                quit = true;
            }
        }
        Sleep(100);
    
    } while (quit == false);

    system("pause");
    return 0;
}