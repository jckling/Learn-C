#pragma once
#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include "Header.h"

#define Z_Height     110
#define Z_Width      75
#define Z_Sub        20
#define Z_Life       2.4
#define Z_Hurt       0.15
#define Z_Move       2
#define Z_Multi      1
#define Z_Pic        5

HBITMAP Lzombiebmp[Z_Pic + 1];
HBITMAP Rzombiebmp[Z_Pic + 1];

// 僵尸初始化
void Z_Create(AllType *z);

// 动画加载
void Z_Load(HWND hwnd);

// 动画绘制
void Z_Paint(HDC hdc, HDC hdcmem, int i);


#endif // !_ZOMBIE_H