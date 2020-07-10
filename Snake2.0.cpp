#include <iostream>
#include <time.h>
#include "Console.h"
using namespace std;

#define DOT_RAN 254
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
    int x,y;
};

void KhoiTaoRan();
ToaDo DiChuyen(int huong);
void HienThiRan(ToaDo x);
void BatSuKien(int &huong);
void VeTuong();
bool KtraThua();
void XuLyThua();
ToaDo HienThiMoi();
bool KtraDaAnMoi(ToaDo moi);
void ThemDot();
ToaDo ran[MAX];
int SoDot = 3;//so luong phan tu than ran

void main()
{
    clrscr();
    KhoiTaoRan();
    //Game loop 
    int x = 0, y = 0;
    int huong = PHAI;
    int diem = 0;
    VeTuong();
    ToaDo moi = HienThiMoi();
    while (1)
    {
        ToaDo DotCuoiCu = DiChuyen(huong);
        HienThiRan(DotCuoiCu);
        BatSuKien(huong);
        if (KtraDaAnMoi (moi) == true)
        {
            moi = HienThiMoi();
            ThemDot();
            diem++;
            gotoXY(TUONG_PHAI + 3,TUONG_TREN);
            cout<< "Diem: "<<diem;
        }
        if (KtraThua() == true)
            break;
        Sleep(200);
    }
    XuLyThua();
}

void KhoiTaoRan()
{
    ran[0].x = TUONG_TRAI + 3;
    ran[1].x = TUONG_TRAI + 2;
    ran[2].x = TUONG_TRAI + 1;
    ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 1;
}

void HienThiRan(ToaDo DotCuoiCu)
{
    for (int i = 0; i < SoDot; i++)
    {
        gotoXY(ran[i].x, ran[i].y);
        cout << (char)DOT_RAN;
    }
    gotoXY(DotCuoiCu.x, DotCuoiCu.y);
    cout<<" ";
}

ToaDo DiChuyen(int huong)
{    ToaDo DotCuoiCu = ran[SoDot - 1];
    for (int i = SoDot - 1; i >= 1; i--)
    {
        ran[i] = ran[i - 1];
    }
    switch (huong)
    {
    case LEN:
        ran[0].y--;
        break;
    case XUONG:
        ran[0].y++;
        break;
    case TRAI:
        ran[0].x--;
        break;
    case PHAI:
        ran[0].x++;
        break;
    }
    return DotCuoiCu;
}

void BatSuKien(int &huong)
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
    gotoXY(x,TUONG_TREN);
    cout<< (char)220;
    }
   for (int y = TUONG_TREN + 1; y <=TUONG_DUOI; y++)
   {  gotoXY(TUONG_TRAI,y);
      cout<< (char)221;

   }
   for (int x = TUONG_TRAI; x <= TUONG_PHAI; x++)
   {   gotoXY(x,TUONG_DUOI);
       cout<< (char)223;
   }
   for (int y = TUONG_TREN + 1; y <= TUONG_DUOI - 1; y++)
   {
       gotoXY(TUONG_PHAI,y);
       cout << (char)222;
   }
}

bool KtraThua()
{  if ( (ran[0].y == TUONG_TREN)||(ran[0].y == TUONG_DUOI) )
        return true;
    if ( (ran[0].x == TUONG_TRAI) || (ran[0].x == TUONG_PHAI) )
        return true;
}

void XuLyThua()
{
    Sleep(500);
    clrscr();
    cout << "GAME OVER";
}

ToaDo HienThiMoi()
{
    srand(time(NULL));
    int x = TUONG_TRAI + 1 + rand() % (TUONG_PHAI - TUONG_TRAI - 1);
    int y = TUONG_TREN + 1 + rand() % (TUONG_DUOI - TUONG_TREN - 1);
    gotoXY(x,y);
    cout << "*";
    return ToaDo{x,y};
}

bool KtraDaAnMoi( ToaDo moi)
{
    if (ran[0].x == moi.x && ran[0].y == moi.y)
    {
        return true;
    }
    else return false;
}

void ThemDot()
{
    ran[SoDot] = ran[SoDot - 1];
    SoDot++;
}

