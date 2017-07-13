#pragma once
#ifndef _PIG_H
#define _PIG_H

#include "Header.h"

#define P_Height     80
#define P_Width      80
#define P_Sub        -20
#define P_Life       1.6
#define P_Hurt       0.22
#define P_Move       3
#define P_Multi      1
#define P_Pic        3

HBITMAP Lpigbmp[P_Pic + 1];
HBITMAP Rpigbmp[P_Pic + 1];

// 野猪初始化
void P_Create(AllType *p);

// 动画加载
void P_Load(HWND hwnd);

// 动画绘制
void P_Paint(HDC hdc, HDC hdcmem, int i);


#endif // !_PIG_H