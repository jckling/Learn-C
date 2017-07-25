#pragma once
#ifndef _Header_H
#define _Header_H

#include <Windows.h>
#include "LinkList.h"

// 方向
typedef enum{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}Direction;

// 怪物移动类型
typedef enum {
	NORMAL,
	FAST,
	FALL
}Type;

// 怪物类型
typedef enum {
	BOSS, 
	MONSTER, 
	MUSH, 
	PIG, 
	ZOMBIE,
	BOSS1
}Name;

// 怪物
typedef struct{
	int x, y;
	double HP;
	double hurt;
	int step;
	int sub;
	int width;
	int height;
	double multi;
	Direction d;
	Type type;
	Name name;
	BOOL behit;
}Boss, Monster, Mush, Pig, Zombie, AllType;

// 场景图像
#define BITMAP_FILE_BK1 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\1.bmp"
#define BITMAP_FILE_BK2 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\2.bmp"
#define BITMAP_FILE_BK3 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\3.bmp"
#define BITMAP_FILE_BK4 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\4.bmp"
#define BITMAP_FILE_BK5 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\5.bmp"
#define BITMAP_FILE_BK6 "D:\\Study\\编程\\Project\\Project\\FIGHT\\BK\\6.bmp"

// 移动上界
#define Border 222

// 计时器
#define GAME 1
#define MENU 2 

// 背景图像
HBITMAP hbmpBackground;

// 窗口大小
#define Height    720
#define Width     1280

// 过滤颜色
#define COLOR_Mark         RGB(204, 204, 255)
#define BOSSCOLOR_Mark     RGB(105, 206, 236)
#define BOSS1COLOR_Mark    RGB(47, 176, 207)

// 怪物（链表）
PLIST Army;
PLIST Army_PicNum;

// 初始化怪物存储
void init();

// 销毁怪物存储
void destorylist();

// 返回怪物数量
int ArmyNum();


#endif // !_Header_H