#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include "zombie.h"
#include "pig.h"
#include "boss1.h"
#include "monster.h"
#include "mush.h"
#include "boss.h"

typedef struct
{
	Direction d;
	int x, y;
	double HP;
	double hurt;
	double fire;
}Player;

#define BITMAP_FILE_LIFE        "D:\\Study\\编程\\Project\\Project\\FIGHT\\INFO\\life.bmp"
#define BITMAP_FILE_BOSSLIFE    "D:\\Study\\编程\\Project\\Project\\FIGHT\\INFO\\blife.bmp"
#define BITMAP_FILE_FIRE        "D:\\Study\\编程\\Project\\Project\\FIGHT\\INFO\\fire.bmp"

#define Player_Height      90
#define Player_Width       60
#define P_Move             6
#define StartLife          12
#define InitHurt           0.8
#define InitFire           5
#define x_start            0
#define y_start            400
#define AttackDistance     37
#define BigDistance        30
#define Big_Width          120
#define Big_Height         90

#define Stand              13
#define Move               11
#define Attack             7
#define Big                5

HBITMAP Lstandbmp[Stand + 1];
HBITMAP Rstandbmp[Stand + 1];
HBITMAP Lmovebmp[Move + 1];
HBITMAP Rmovebmp[Move + 1];
HBITMAP Lattackbmp[Attack + 1];
HBITMAP Rattackbmp[Attack + 1];
HBITMAP Lbigbmp[Big + 1];
HBITMAP Rbigbmp[Big + 1];
HBITMAP hbmpLife;
HBITMAP hbmpBosslife;
HBITMAP hbmpFire;

// 玩家
Player player;
int stand;
int move;
int attack;
int big;
int bigx, bigy;
Direction bigd;
BOOL attackresponse;
BOOL bigstart;

// 初始化玩家
void Player_Inite();

// 站立(左) 载入、绘制
void StandL_Load(HWND hwnd);
void StandL_Paint(HDC hdc, HDC hdcmem);

// 站立(右) 载入、绘制
void StandR_Load(HWND hwnd);
void StandR_Paint(HDC hdc, HDC hdcmem);

// 移动(左) 载入、绘制
void MoveL_Load(HWND hwnd);
void MoveL_Paint(HDC hdc, HDC hdcmem);

// 移动(右) 载入、绘制
void MoveR_Load(HWND hwnd);
void MoveR_Paint(HDC hdc, HDC hdcmem);

// 攻击(左) 载入、绘制
void AttackL_Load(HWND hwnd);

// 攻击(右) 载入、绘制
void AttackR_Load(HWND hwnd);

// 大招(左) 载入、绘制
void BigL_Load(HWND hwnd);
void BigL_Paint(HDC hdc, HDC hdcmem);

// 大招(右) 载入、绘制
void BigR_Load(HWND hwnd);
void BigR_Paint(HDC hdc, HDC hdcmem);

// 载入图片
void LoadPlayer(HWND hwnd);
void LoadArmy(HWND hwnd);

// 载入信息
void LoadInfo(HWND hwnd);

// 显示玩家和BOSS的信息
void PaintInfo(HDC hdc, HDC hdcmem);

// 绘制敌人
void PaintArmy(HDC hdc, HDC hdcmem);

// 攻击绘图
void AttackPaint(HWND hwnd);

// 玩家移动
void PlayerMove(Direction d);

// 玩家是否死亡
BOOL IfDead();

#endif // !_PLAYER_H