#pragma once
#ifndef _MONSTER_H
#define _MONSTER_H

#include "Header.h"

#define M_Height     90
#define M_Width      100
#define M_Sub        0
#define M_Life       2.4
#define M_Hurt       0.25
#define M_Move       3
#define M_Multi      1.2
#define M_Pic        7

HBITMAP Lmonsterbmp[M_Pic + 1];
HBITMAP Rmonsterbmp[M_Pic + 1];

// 野怪初始化
void M_Create(AllType *m);

// 动画加载
void M_Load(HWND hwnd);

// 动画绘制
void M_Paint(HDC hdc, HDC hdcmem, int i);


#endif // !_MONSTER_H