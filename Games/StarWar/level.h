#pragma once
#ifndef _LEVEL_H
#define _LEVEL_H
#include "operation.h"

#define level1_1  4
#define level1_2  6

#define level2_1  4
#define level2_2  6
#define level2_3  9

#define level4_1  5
#define level4_2  8

#define level5_1  5
#define level5_2  8
#define level5_3  11

BOOL level1;
BOOL level2;
BOOL level3;
BOOL level4;
BOOL level5;
BOOL level6;

BOOL wave1;
BOOL wave2;
BOOL wave3;

extern BOOL next;

int first;
int second;
int third;
int counter;

// 怪物出现间隔距离
int distance;

// 关卡设置
void CreateArmy_level1();
void CreateArmy_level2();
void CreateArmy_level3();

void CreateArmy_level4();
void CreateArmy_level5();
void CreateArmy_level6();


#endif // !_LEVEL_H