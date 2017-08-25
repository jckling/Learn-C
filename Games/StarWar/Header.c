#include "Header.h"

HBITMAP hbmpBackground = NULL;

// 初始化怪物存储
void init() {
	Army = ListCreate(0);
	Army_PicNum = ListCreate(0);
}

// 销毁怪物存储
void destorylist() {
	ListClearAndFree(Army);
	ListClearAndFree(Army_PicNum);
}

// 返回怪物数量
int ArmyNum() {
	return ListSize(Army);
}