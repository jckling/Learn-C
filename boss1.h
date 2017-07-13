#pragma once
#ifndef _BOSS1_H
#define _BOSS1_H

#include "Header.h"

#define B1_Height     150
#define B1_Width      120
#define B1_Sub        60
#define B1_Life       9
#define B1_Hurt       0.3
#define B1_Move       4
#define B1_Multi      1
#define B1_Pic        11

HBITMAP Lboss1bmp[B1_Pic + 1];
HBITMAP Rboss1bmp[B1_Pic + 1];

// 跳跳驴初始化
void B1_Create(AllType *b);

// 动画加载
void B1_Load(HWND hwnd);

// 动画绘制
void BOSS1_Paint(HDC hdc, HDC hdcmem, int i);


#endif // !_BOSS1_H