#include <iostream>
#include <time.h>
#include "Console.h"
using namespace std;

#define DOT_RAN 79
#define MAX 100
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TREN 1
#define TUONG_DUOI 13
#define TUONG_TRAI 3
#define TUONG_PHAI 53

struct ToaDo
{
    int x, y, x0, y0;
};

void KhoiTaoRan();
ToaDo DiChuyen(int huong);
void HienThiRan(ToaDo x);
void BatSuKien(int& huong);
void VeTuong();
bool KtraThua();
void XuLyThua();
ToaDo HienThiMoi();
bool KtraDaAnMoi(ToaDo moi);
void ThemDot();
ToaDo snake[MAX];
bool endGame;
int SoDot = 3;//so luong phan tu than ran
int diem = 0;

void main()
{
    clrscr();
    KhoiTaoRan();
    //Game loop 
    int x = 0, y = 0;
    srand(time(NULL));
    int r = (rand() % 4);
    int huong;
    switch (r)
    {
    case 0:
        huong = PHAI;
        break;
    case 1:
        huong = TRAI;
        break;
    case 2:
        huong = LEN;
        break;
    case 3:
        huong = XUONG;
    default:
        huong = PHAI;
        break;
    }
    
    VeTuong();
    ToaDo moi = HienThiMoi();
    while (1)
    {
        ToaDo DotCuoiCu = DiChuyen(huong);
        HienThiRan(DotCuoiCu);
        BatSuKien(huong);
        if (KtraDaAnMoi(moi) == true)
        {
            moi = HienThiMoi();
            ThemDot();
            diem++;
            gotoXY(TUONG_PHAI + 3, TUONG_TREN);
            cout << "Diem: " << diem;
        }
        if (KtraThua() == true)
            break;
        Sleep(300);
    }
    XuLyThua();
}

void KhoiTaoRan()
{
    snake[0].x = TUONG_TRAI + 9;
    snake[1].x = TUONG_TRAI + 8;
    snake[2].x = TUONG_TRAI + 7;
    snake[0].y = snake[1].y = snake[2].y = TUONG_TREN + 5;
}

void HienThiRan(ToaDo DotCuoiCu)
{
    for (int i = 0; i < SoDot; i++)
    {
        gotoXY(snake[i].x, snake[i].y);
        cout << (char)DOT_RAN;
    }
    gotoXY(DotCuoiCu.x, DotCuoiCu.y);
    cout << " ";
}

ToaDo DiChuyen(int huong)
{
    ToaDo DotCuoiCu = snake[SoDot - 1];
    for (int i = SoDot - 1; i >= 1; i--)
    {
        snake[i] = snake[i - 1];
    }
    switch (huong)
    {
    case LEN:
        snake[0].y--;
        break;
    case XUONG:
        snake[0].y++;
        break;
    case TRAI:
        snake[0].x--;
        break;
    case PHAI:
        snake[0].x++;
        break;
    }
    return DotCuoiCu;
}

void BatSuKien(int& huong)
{
    int key = inputKey();
    if (key == KEY_UP)
    {
        huong = LEN;
    }
    else if (key == KEY_DOWN)
    {
        huong = XUONG;
    }
    else if (key == KEY_LEFT)
    {
        huong = TRAI;
    }
    else if (key == KEY_RIGHT)
    {
        huong = PHAI;
    }
}

void VeTuong()
{
    for (int x = TUONG_TRAI; x <= TUONG_PHAI; x++)
    {
        gotoXY(x, TUONG_TREN);
        cout << (char)220;
    }
    for (int y = TUONG_TREN + 1; y <= TUONG_DUOI; y++)
    {
        gotoXY(TUONG_TRAI, y);
        cout << (char)221;

    }
    for (int x = TUONG_TRAI; x <= TUONG_PHAI; x++)
    {
        gotoXY(x, TUONG_DUOI);
        cout << (char)223;
    }
    for (int y = TUONG_TREN + 1; y <= TUONG_DUOI - 1; y++)
    {
        gotoXY(TUONG_PHAI, y);
        cout << (char)222;
    }
}

bool KtraThua()
{
    if ((snake[0].y == TUONG_TREN) || (snake[0].y == TUONG_DUOI))
        return true;
    if ((snake[0].x == TUONG_TRAI) || (snake[0].x == TUONG_PHAI))
        return true;
    for (int i = 0; i < SoDot; i++)
    {
        if (i != 0 && snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }

}

void XuLyThua()
{
    Sleep(500);
    clrscr();
    cout << "GAME OVER" << endl;
    cout << "Diem: " << diem + 3 << endl;
}

ToaDo HienThiMoi()
{
    srand(time(NULL));
    int x = TUONG_TRAI + 1 + rand() % (TUONG_PHAI - TUONG_TRAI - 1);
    int y = TUONG_TREN + 1 + rand() % (TUONG_DUOI - TUONG_TREN - 1);
    gotoXY(x, y);
    cout << "*";
    return ToaDo{ x,y };
}

bool KtraDaAnMoi(ToaDo moi)
{
    if (snake[0].x == moi.x && snake[0].y == moi.y)
    {
        return true;
    }
    else return false;
}

void ThemDot()
{
    snake[SoDot] = snake[SoDot - 1];
    SoDot++;
}
