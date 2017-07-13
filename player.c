#include "player.h"

BOOL attackresponse = FALSE;
BOOL bigstart = FALSE;

// 初始化玩家
void Player_Inite() {

	player.x = x_start;
	player.y = y_start;
	player.d = RIGHT;

	player.HP = StartLife;
	player.hurt = InitHurt;
	player.fire = InitFire;
}

// 站立(左) 载入、绘制
void StandL_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Stand; i++) {
		wsprintf(fileName, ".\\FIGHT\\STAND\\L\\%d.bmp", i);
		Lstandbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 147, 215, LR_LOADFROMFILE);
	}

	stand = 0;
}
void StandL_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (stand > Stand)
		stand = 0;

	SelectObject(hdcmem, Lstandbmp[stand]);
	TransparentBlt(hdc, player.x, player.y, Player_Width, Player_Height, hdcmem, 0, 0, 147, 215, COLOR_Mark);
	
	stand++;
}

// 站立(右) 载入、绘制
void StandR_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Stand; i++) {
		wsprintf(fileName, ".\\FIGHT\\STAND\\R\\%d.bmp", i);
		Rstandbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 147, 214, LR_LOADFROMFILE);
	}
}
void StandR_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (stand > Stand)
		stand = 0;

	SelectObject(hdcmem, Rstandbmp[stand]);
	TransparentBlt(hdc, player.x, player.y, Player_Width, Player_Height, hdcmem, 0, 0, 147, 214, COLOR_Mark);
	
	move++;
}

// 移动(左) 载入、绘制
void MoveL_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Move; i++) {
		wsprintf(fileName, ".\\FIGHT\\MOVE\\L\\%d.bmp", i);
		Lmovebmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 152, 224, LR_LOADFROMFILE);
	}

	move = 0;
}
void MoveL_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (move > Move)
		move = 0;

	SelectObject(hdcmem, Lmovebmp[move]);
	TransparentBlt(hdc, player.x, player.y, Player_Width, Player_Height, hdcmem, 0, 0, 152, 224, COLOR_Mark);
	
	move++;
}

// 移动(右) 载入、绘制
void MoveR_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Move; i++) {
		wsprintf(fileName, ".\\FIGHT\\MOVE\\R\\%d.bmp", i);
		Rmovebmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 151, 224, LR_LOADFROMFILE);
	}
}
void MoveR_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (move >= Move)
		move = 0;

	SelectObject(hdcmem, Rmovebmp[move]);
	TransparentBlt(hdc, player.x, player.y, Player_Width, Player_Height, hdcmem, 0, 0, 151, 224, COLOR_Mark);
	
	move++;
}

// 攻击(左) 载入、绘制
void AttackL_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };
	for (i = 0; i <= Attack; i++) {
		wsprintf(fileName, ".\\FIGHT\\ATTACK\\L\\%d.bmp", i);
		Lattackbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 275, 188, LR_LOADFROMFILE);
	}
	
	attack = 0;
}

// 攻击(右) 载入、绘制
void AttackR_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };
	for (i = 0; i <= Attack; i++){
		wsprintf(fileName, ".\\FIGHT\\ATTACK\\R\\%d.bmp", i);
		Rattackbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 275, 187, LR_LOADFROMFILE);
	}
}

// 大招(左) 载入、绘制
void BigL_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Big; i++) {
		wsprintf(fileName, ".\\FIGHT\\BIG\\L\\%d.bmp", i);
		Lbigbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 127, 93, LR_LOADFROMFILE);
	}
	
	big = 0;
}
void BigL_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (big > Big)
		big = 0;

	SelectObject(hdcmem, Lbigbmp[big]);
	TransparentBlt(hdc, bigx, bigy, Big_Width, Big_Height, hdcmem, 0, 0, 127, 93, RGB(255, 255, 255));
	
	big++;
}

// 大招(右) 载入、绘制
void BigR_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };
	for (i = 0; i <= Big; i++){
		wsprintf(fileName, ".\\FIGHT\\BIG\\R\\%d.bmp", i);
		Rbigbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 127, 93, LR_LOADFROMFILE);
	}
}
void BigR_Paint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (big > Big)
		big = 0;

	SelectObject(hdcmem, Rbigbmp[big]);
	TransparentBlt(hdc, bigx, bigy, Big_Width, Big_Height, hdcmem, 0, 0, 127, 93, RGB(255, 255, 255));
	
	big++;
}

// 载入图片
void LoadPlayer(HWND hwnd) {

	StandL_Load(hwnd);
	StandR_Load(hwnd);

	MoveL_Load(hwnd);
	MoveR_Load(hwnd);

	AttackL_Load(hwnd);
	AttackR_Load(hwnd);

	BigL_Load(hwnd);
	BigR_Load(hwnd);
}
void LoadArmy(HWND hwnd) {
	
	Z_Load(hwnd);
	P_Load(hwnd);
	B1_Load(hwnd);

	M_Load(hwnd);
	MR_Load(hwnd);
	B_Load(hwnd);	
}

// 载入信息
void LoadInfo(HWND hwnd) {

	hbmpLife = LoadImage(NULL, BITMAP_FILE_LIFE, IMAGE_BITMAP, 134, 117, LR_LOADFROMFILE);
	hbmpBosslife = LoadImage(NULL, BITMAP_FILE_BOSSLIFE, IMAGE_BITMAP, 134, 117, LR_LOADFROMFILE);
	hbmpFire = LoadImage(NULL, BITMAP_FILE_FIRE, IMAGE_BITMAP, 344, 471, LR_LOADFROMFILE);
}

// 显示玩家和BOSS的信息
void PaintInfo(HDC hdc, HDC hdcmem) {

	int i, j, k;
	AllType *a;

	SetStretchBltMode(hdc, COLORONCOLOR);

	SelectObject(hdcmem, hbmpLife);

	for (i = 0; i < (int)player.HP; i++) {
		j = i > 5 ? i - 6 : i;
		TransparentBlt(hdc, 4 + j * 30, i > 5 ? 33 : 4, 24, 24, hdcmem, 0, 0, 134, 117, COLOR_Mark);
	}

	for (k = 0; k < (int)player.fire; k++) {
		SelectObject(hdcmem, hbmpFire);
		TransparentBlt(hdc, 4 + k * 30, i >= 7 ? 60 : 33, 24, 24, hdcmem, 0, 0, 344, 471, COLOR_Mark);
	}

	a = ListGetAt(Army, 0);
	if (NULL != a && (BOSS == a->name || BOSS1 == a->name)) {
		SelectObject(hdcmem, hbmpBosslife);
		for (i = 0; i < (int)a->HP; i++) {
			j = i > 5 ? i - 6 : i;
			TransparentBlt(hdc, 1237 - j * 30, i > 5 ? 33 : 4, 24, 24, hdcmem, 0, 0, 134, 117, COLOR_Mark);
		}
	}
}

// 绘制敌人
void PaintArmy(HDC hdc, HDC hdcmem) {

	int i;
	AllType *a;

	for (i = 0; i < ArmyNum(); i++) {
		a = ListGetAt(Army, i);
		switch (a->name) {
		case BOSS:
			BOSS_Paint(hdc, hdcmem, i);
			break;
		case BOSS1:
			BOSS1_Paint(hdc, hdcmem, i);
			break;
		case MONSTER:
			M_Paint(hdc, hdcmem, i);
			break;
		case MUSH:
			MR_Paint(hdc, hdcmem, i);
			break;
		case PIG:
			P_Paint(hdc, hdcmem, i);
			break;
		case ZOMBIE:
			Z_Paint(hdc, hdcmem, i);
			break;
		}
	}

}

// 攻击绘图
void AttackPaint(HWND hwnd) {

	HDC hdc, hdcmem;
	HDC test;
	HBITMAP hbmMem, hbmMem2;
	HFONT hFont, hOldFont;
	RECT rect;
	BITMAP bmp;

	GetClientRect(hwnd, &rect); //把客户区的大小写进Rect结构中
	hdc = GetDC(hwnd);

	hdcmem = CreateCompatibleDC(hdc);
	hbmMem = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hdcmem, hbmMem);

	test = CreateCompatibleDC(hdc);
	hbmMem2 = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(test, hbmMem2);

	// ========输出背景
	SelectObject(hdcmem, hbmpBackground);
	GetObject(hbmpBackground, sizeof(BITMAP), &bmp);
	StretchBlt(test, rect.left, rect.top, rect.right - rect.left,
		rect.bottom - rect.top, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	// =====画动作
	SetStretchBltMode(hdc, COLORONCOLOR);
	SetStretchBltMode(hdcmem, COLORONCOLOR);

	if (attack >= Attack)
		attack = 0;
	if (player.d == RIGHT) {
		SelectObject(hdcmem, Rattackbmp[attack]);
		TransparentBlt(test, player.x, player.y + 1, 2 * Player_Width + 11, Player_Height, hdcmem, 0, 0, 275, 187, COLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Lattackbmp[attack]);
		TransparentBlt(test, player.x - 71, player.y + 1, 2 * Player_Width + 11, Player_Height, hdcmem, 0, 0, 275, 188, COLOR_Mark);
	}
	attack++;

	// ========输出敌人
	PaintArmy(test, hdcmem);

	// 绘制大招
	if (TRUE == bigstart) {
		if (RIGHT == bigd) {
			BigR_Paint(test, hdcmem);
			bigx += 2 * P_Move;
		}
		else {
			BigL_Paint(test, hdcmem);
			bigx -= 2 * P_Move;
		}
	}
	if (bigx > Width || bigx < 0) {
		bigstart = FALSE;
		Clearbehit();
	}

	// =======输出游戏信息
	PaintInfo(test, hdcmem);

	// 一次性绘制到目标窗口
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, test, 0, 0, SRCCOPY);

	DeleteObject(test);
	DeleteObject(hbmMem2);
	DeleteObject(hbmMem);
	DeleteObject(hdcmem);
	ReleaseDC(hwnd, hdc);
}

// 玩家移动
void PlayerMove(Direction d){

	switch (d) {
	case DOWN:
		if (player.y + P_Move + Player_Height < Height)
			player.y += P_Move;
		break;
	case UP:
		if (player.y - P_Move > Border)
			player.y -= P_Move;
		break;
	case LEFT:
		if (player.x - P_Move > 0) {
			player.x -= P_Move;
			player.d = LEFT;
		}
		break;
	case RIGHT:
		if (player.x + P_Move < Width - Player_Width) {
			player.x += P_Move;
			player.d = RIGHT;
		}
		break;
	}
}

// 玩家是否死亡
BOOL IfDead() {

	if (player.HP <= 0)
		return TRUE;
	return FALSE;
}