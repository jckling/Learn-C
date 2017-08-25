#include "Tetirs.h"

//初始化变量
int score = 0;
int level = 0;
BOOL GameOver = 0;
int N = 4;
int blocks[20][15];

void Inite()
{
	int i, j;

	// 设置随机数种子
	// 需要使用随机数生成食物的位置等
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft); // 获取系统时间
	srand(ft.dwLowDateTime);

	// 初始化游戏界面
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			blocks[i][j] = 0;
	}

	// "I"形的俄罗斯方块
	for (i = 0; i < N; ++i)
	{
		option[0].x[i] = 1;
		option[0].y[i] = -i;
	}

	// "L"形的俄罗斯方块
	option[1] = option[0];
	option[1].x[N - 1] = 2;
	option[1].y[N - 1] = 0;

	// "田"形的俄罗斯方块
	option[2] = option[0];
	option[2].x[N - 1] = 2;
	option[2].x[N - 2] = 2;
	option[2].y[N - 1] = -1;
	option[2].y[N - 2] = 0;

	// "凸"形的俄罗斯方块
	option[3] = option[1];
	option[3].x[1] = 2;
	option[3].x[2] = 2;
	option[3].x[N - 1] = 3;
	option[3].y[1] = 0;
	option[3].y[2] = -1;

	// "Z"形的俄罗斯方块
	option[4] = option[3];
	option[4].y[0] = -1;
}

// 返回积分
int GetScore() { return score; }

// 返回level
int GetLevel() { return level; }

// 对tetris进行初始化，
void InitTetris()
{
	// 随机建立一个俄罗斯方块
	int i = rand() % 5;
	tetris = option[i];
}
// 将tetris向下移动
void MoveDown(Tetris* t)
{
	// 逐个访问tetris中的小方块
	for (int i = 0; i < N; ++i)
	{
		// 将每个方块的x坐标加1，实现移动
		t->y[i] += 1;
	}
}

// 判断是否可以继续向下移动俄罗斯方块
BOOL TryMoveDown(Tetris* t)
{
	// 定义一个临时的俄罗斯方块
	Tetris tmp = *t;
	// 向下移动临时俄罗斯方块
	MoveDown(&tmp);
	// 判断移动后的方块是否超出边界
	// 以及遇到了场景中的其他方块
	for (int i = 0; i < N; ++i)
	{
		// 移动后的新位置
		int row = tmp.y[i];
		int col = tmp.x[i];
		if (row >= ROW) // 是否超出下边界
		{
			return 0;
		}
		// 判断是否遇到场景中的方块
		// 首先判断移动后的位置是否在场景内部
		if (row >= 0 && row < ROW
			&& col >= 0 && col < COL
			// 然后判断这个位置是否已经有方块
			&& blocks[row][col])
		{
			// 如果已经有方块，移动不成功
			return 0;
		}
	}

	// 可以向下移动
	return 1;
}

// 将移动到底部的俄罗斯方块合并到场景的方块中
BOOL MergeBlock(Tetris* t)
{
	for (int i = 0; i < N; ++i)
	{
		// 方块如果超过场景，则无法合并
		if (t->y[i] < 0)
		{
			return 0;
		}
		// 将场景中对应的位置设置为1，
		// 即将方块合并到了场景中
		blocks[t->y[i]][t->x[i]] = 1;
	}
	// 返回合并成功
	return 1;
}

// 向右移动
void MoveRight(Tetris* t)
{
	for (int i = 0; i < N; ++i)
	{
		t->x[i] += 1;
	}
}
// 碰撞检测，判断是否可以向右移动
BOOL TryMoveRight(Tetris* t)
{
	Tetris tmp = *t;
	MoveRight(&tmp);

	for (int i = 0; i < N; ++i)
	{
		if (tmp.x[i] >= COL || blocks[tmp.y[i]][tmp.x[i]])
		{
			return 0;
		}
	}

	return 1;
}
// 处理向右按键按下消息
void OnKeyDownRight()
{
	// 判断是否可以向右移动
	if (TryMoveRight(&tetris))
	{
		// 如果可以，向右移动
		MoveRight(&tetris);
	}
}

// 向左移动
void MoveLeft(Tetris* t)
{
	for (int i = 0; i < N; ++i)
	{
		t->x[i] -= 1;
	}
}
// 碰撞检测，判断是否可以向左移动
BOOL TryMoveLeft(Tetris* t)
{
	Tetris tmp = *t;
	MoveLeft(&tmp);

	for (int i = 0; i < N; ++i)
	{
		if (tmp.x[i] < 0 || blocks[tmp.y[i]][tmp.x[i]])
		{
			return 0;
		}
	}

	return 1;
}
// 处理向左按键按下消息
void OnKeyDownLeft()
{
	if (TryMoveLeft(&tetris))
	{
		MoveLeft(&tetris);
	}
}

// 向下加速移动
void MoveDownFast(Tetris* t)
{
	for (int i = 0; i < N; ++i)
	{
		t->y[i] += 1;
	}
}
void OnKeyDownDown()
{
	if (TryMoveDown(&tetris))
	{
		MoveDownFast(&tetris);
	}
}

// 旋转
void OnKeyDownUp()
{

}

//刷新分数
void IfClearRow()
{
	int i, j;
	BOOL flag;
	// 从上往下消除
	for (i = 0; i < ROW; i++)
	{
		flag = 1;
		for (j = 0; j < COL; j++)
		{
			if (blocks[i][j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			Update(i);
			score += 10;
			if (score >= 100)
				level++;
		}
	}
}

void Update(int i)
{
	int j;
	for (; i > 0; i--)
	{
		for (j = 0; j < COL; j++)
			blocks[i][j] = blocks[i - 1][j];
	}
}