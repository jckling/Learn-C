#pragma once
#include "Header.h"
int RealHeight[15] = { 215,214,224,224,188,187,228,180,180,177,176,127,128,331,330 };
int RealWidth[15] = { 147,147,152,151,275,275,149,133,133,199,198,128,128,343,342 };
int DesignHeight[6] = { 90,70,110 };
int DesignWidth[6] = { 60,70,75 };
int RealPicNumber[8] = { 14,12,8,10,6,8,7,9 };
int PicNum[8] = { 13,11,7,9,5,7,6,8 };
int Number[4]; //四种小怪
int MoveStep[6]; //移动步长
char Path[15][30] = { { ".\\FIGHT\\STAND\\L\\%d.bmp" },{ ".\\FIGHT\\STAND\\R\\%d.bmp" },
{ ".\\FIGHT\\MOVE\\L\\%d.bmp" },{ ".\\FIGHT\\MOVE\\R\\%d.bmp" },{ ".\\FIGHT\\ATTACK\\L\\%d.bmp" },
{ ".\\FIGHT\\ATTACK\\R\\%d.bmp" },{ ".\\FIGHT\\MR\\%d.bmp" },{ ".\\FIGHT\\Z\\L\\%d.bmp" },
{ ".\\FIGHT\\Z\\R\\%d.bmp" },{ ".\\FIGHT\\M\\L\\%d.bmp" },{ ".\\FIGHT\\M\\R\\%d.bmp" },
{ ".\\FIGHT\\P\\L\\%d.bmp" },{ ".\\FIGHT\\P\\R\\%d.bmp" },{ ".\\FIGHT\\B\\L\\%d.bmp" },
{ ".\\FIGHT\\B\\R\\%d.bmp" } };