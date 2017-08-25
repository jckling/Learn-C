#ifndef _TETIRS_H
#define _TETIRS_H

#include <Windows.h>

// 定义表示俄罗斯方块的结构体Tetris
// 每个俄罗斯方块有四个小方块，
// 所以这个结构体记录4组位置信息，
// 比如，(x[0],y[0])就是第一个方块的信息
typedef struct
{
	int x[4];  // 列
	int y[4];  // 行
} Tetris;

// 每个大的俄罗斯方块中的小方块数
extern int N;

// 游戏是否结束
extern BOOL GameOver;

//可选的俄罗斯方块
Tetris option[5];
// 游戏场景中移动的俄罗斯方块
Tetris tetris;

// 游戏场景能容纳方块的行和列
#define COL 15
#define ROW 20  

// 记录场景中的方块的数组, 0表示无方块，1表示有方块
extern int blocks[][15];

// 计时器ID
#define TIMER_ID 12340
// 判断游戏是否达到升级条件
#define IS_SPEEDUP(s) (s % dwOneLevelScores) == 0


// 计时器到时间隔
DWORD dwTimerElapse;
// 每提高一级，计时器时钟周期缩短的比例
DOUBLE dbLevelSpeedupRatio;
// 此变量表示多少个积分上升一个级别
DWORD dwOneLevelScores;

// 保存计分，初始为0
extern int score;
// 保存级别，初始为0
extern int level;


int GetScore();
int GetLevel();
void InitTetris();
void MoveDown(Tetris* t);
BOOL TryMoveDown(Tetris* t);
BOOL MergeBlock(Tetris* t);
void MoveRight(Tetris* t);
BOOL TryMoveRight(Tetris* t);
void OnKeyDownRight();
void MoveLeft(Tetris* t);
BOOL TryMoveLeft(Tetris* t);
void OnKeyDownLeft();
void MoveDownFast(Tetris* t);
void OnKeyDownDown();
void IfClearRow();
void Update();

#endif // !TETIRS_H