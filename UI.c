#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <mmsystem.h>
#include "level.h"

// 句柄
HINSTANCE hinst;
 
// 左右键计数
int pressleft = 0;
int pressright = 0;

// 游戏状态
typedef enum {
	STARTMENU,
	GAMELOOP,
	GAMEOVER
}GAMESTATE;

// 菜单选项
typedef  enum{
	START,
	EXIT
}GAMEMENU;

GAMESTATE GameState = STARTMENU;
#define    MenuCount  2 // 菜单项数
int MenuSelect = 0;

// LOGO、菜单图片、结束图片
HBITMAP    hbmpMenu;
HBITMAP    hbmpMenuRun[12];
int        MenuRunNum = 0;
HBITMAP    hbmpSelect;
HBITMAP    hbmpBlack;
HBITMAP    hbmpBegin;
HBITMAP    hbmpEnd;
HBITMAP    hbmpOption;
HBITMAP    hbmpPass;

// 开场LOGO
BLENDFUNCTION bf;
int bTrans;
BOOL anima = TRUE;
BOOL flag = FALSE;
BOOL a = FALSE;
BOOL b = FALSE;

// 开始动画
void BeginAnima(hwnd) {

	HDC hdc, hdcmem;
	HDC test;
	HBITMAP hbmMem, hbmMem2;
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

	// ======== LOGO
	SelectObject(hdcmem, hbmpBegin);
	GetObject(hbmpBegin, sizeof(BITMAP), &bmp);
	TransparentBlt(test, (Width-450)/2, (Height-460)/2, 450, 450, hdcmem, 0, 0, 1440, 1462, COLOR_Mark);

	// ========输出黑色透明背景
	SelectObject(hdcmem, hbmpBlack);
	GetObject(hbmpBlack, sizeof(BITMAP), &bmp);
	AlphaBlend(test, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, bf);//绘制指定透明度的位图  

	// ======== 一次性输出到窗口
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, test, 0, 0, SRCCOPY);

	DeleteObject(test);
	DeleteObject(hbmMem2);
	DeleteObject(hbmMem);
	DeleteObject(hdcmem);
	ReleaseDC(hwnd, hdc);
}
void Anima(hwnd) {

	if (!a && anima && bf.SourceConstantAlpha > 0) {
		bTrans -= 5;
		bf.SourceConstantAlpha = bTrans;
		InvalidateRect(hwnd, NULL, TRUE);
	}
	else if (!b && anima && bf.SourceConstantAlpha < 255) {
		a = TRUE;
		bTrans += 5;
		bf.SourceConstantAlpha = bTrans;
		InvalidateRect(hwnd, NULL, FALSE);
		if (bTrans >= 234) {
			bTrans = 0;
			bf.SourceConstantAlpha = bTrans;
			b = TRUE;
			anima = FALSE;
		}
	}
}

// 菜单
void LoadSurface(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= Stand; i++) {
		wsprintf(fileName, ".\\FIGHT\\SURFACE\\%d.bmp", i);
		hbmpMenuRun[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 480, 250, LR_LOADFROMFILE);
	}

	hbmpSelect = LoadImage(NULL, ".\\FIGHT\\LOGO\\select.bmp", IMAGE_BITMAP, 400, 400, LR_LOADFROMFILE);
	hbmpMenu= LoadImage(NULL, ".\\FIGHT\\BK\\BK7.bmp", IMAGE_BITMAP, 1280, 680, LR_LOADFROMFILE);
	hbmpBlack= LoadImage(NULL, ".\\FIGHT\\BK\\black.bmp", IMAGE_BITMAP, 1247, 718, LR_LOADFROMFILE);
	hbmpBegin= LoadImage(NULL, ".\\FIGHT\\LOGO\\begin1.bmp", IMAGE_BITMAP, 1440, 1462, LR_LOADFROMFILE);
	hbmpEnd = LoadImage(NULL, ".\\FIGHT\\LOGO\\over.bmp", IMAGE_BITMAP, 1440, 1543, LR_LOADFROMFILE);
	hbmpOption = LoadImage(NULL, ".\\FIGHT\\LOGO\\option.bmp", IMAGE_BITMAP, 1160, 926, LR_LOADFROMFILE);
	hbmpPass= LoadImage(NULL, ".\\FIGHT\\LOGO\\pass.bmp", IMAGE_BITMAP, 1299, 1063, LR_LOADFROMFILE);
}
void MenuRunPaint(HDC hdc, HDC hdcmem) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	if (MenuRunNum > 11)
		MenuRunNum = 0;

	// 绘制菜单动画
	SelectObject(hdcmem, hbmpMenuRun[MenuRunNum]);
	TransparentBlt(hdc, 800, 500, 240, 125, hdcmem, 0, 0, 480, 250, COLOR_Mark);
	MenuRunNum++;

	// 绘制选择图标
	SelectObject(hdcmem, hbmpSelect);
	TransparentBlt(hdc, 453 + (MenuSelect == EXIT ? 15 : 0), 518 + (MenuSelect == EXIT ? 59 : 0), 50, 50, hdcmem, 0, 0, 400, 400, COLOR_Mark);
}
void MenuPaint(HWND hwnd) {

	HDC hdc, hdcmem;
	HDC test;
	HBITMAP hbmMem, hbmMem2;
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

	// 绘制背景
	SelectObject(hdcmem, hbmpMenu);
	GetObject(hbmpMenu, sizeof(BITMAP), &bmp);
	StretchBlt(test,rect.left, rect.top,rect.right - rect.left, rect.bottom - rect.top,
		hdcmem,0, 0,bmp.bmWidth, bmp.bmHeight,SRCCOPY);

	// 绘制标题和选项
	SelectObject(hdcmem, hbmpOption);
	TransparentBlt(test, 300, 50, 600, 600, hdcmem, 0, 0, 1160, 926, COLOR_Mark);

	// 绘制动画和选择图标
	MenuRunPaint(test, hdcmem);

	// 绘制黑色透明背景
	SelectObject(hdcmem, hbmpBlack);
	GetObject(hbmpBlack, sizeof(BITMAP), &bmp);
	AlphaBlend(test, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, bf); // 绘制指定透明度的位图  

	// 一次性绘制到目标窗口
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, test, 0, 0, SRCCOPY);

	DeleteObject(test);
	DeleteObject(hbmMem2);
	DeleteObject(hbmMem);
	DeleteObject(hdcmem);
	ReleaseDC(hwnd, hdc);
}

// 背景音乐 
void PlayBGM() {

	if (level1 && !level2) {
		mciSendString("close SOUND1", 0, 0, 0);
		mciSendString("open BLACKNAIL.wav alias SOUND2", NULL, 0, NULL);
		mciSendString("play SOUND2", 0, 0, 0);
	}
	else if (level2 && !level3) {
		mciSendString("close SOUND2", 0, 0, 0);
		mciSendString("open IAM.wav alias SOUND3", NULL, 0, NULL);
		mciSendString("play SOUND3", 0, 0, 0);
	}
	else if (level3 && !level4) {
		mciSendString("close SOUND3", 0, 0, 0);
		mciSendString("open ROMANESQUE.wav alias SOUND4", NULL, 0, NULL);
		mciSendString("play SOUND4", 0, 0, 0);
	}
	else if (level4 && !level5) {
		mciSendString("close SOUND4", 0, 0, 0);
		mciSendString("open COMPLEX.wav alias SOUND5", NULL, 0, NULL);
		mciSendString("play SOUND5", 0, 0, 0);
	}
	else if (level5 && !level6) {
		mciSendString("close SOUND5", 0, 0, 0);
		mciSendString("open BLACKNAIL.wav alias SOUND6", NULL, 0, NULL);
		mciSendString("play SOUND6", 0, 0, 0);
	}
}
void StopBGM() {

	if (!level1)
		mciSendString("close SOUND1", 0, 0, 0);
	else if (level1 && !level2)
		mciSendString("close SOUND2", 0, 0, 0);
	else if (level2 && !level3)
		mciSendString("close SOUND3", 0, 0, 0);
	else if (level3 && !level4)
		mciSendString("close SOUND4", 0, 0, 0);
	else if (level4 && !level5)
		mciSendString("close SOUND5", 0, 0, 0);
	else if (level5 && !level6)
		mciSendString("close SOUND6", 0, 0, 0);
}

// 创建背景，加载场景
void BackgroundLoad(HWND hwnd) {

	if (hbmpBackground == NULL)
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK1, IMAGE_BITMAP, 1024, 768, LR_LOADFROMFILE);
	if (level1) {
		DeleteObject(hbmpBackground);
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK2, IMAGE_BITMAP, 757, 427, LR_LOADFROMFILE);
	}
	if (level2) {
		DeleteObject(hbmpBackground);
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK3, IMAGE_BITMAP, 1024, 615, LR_LOADFROMFILE);
	}
	if (level3) {
		DeleteObject(hbmpBackground);
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK4, IMAGE_BITMAP, 1200, 600, LR_LOADFROMFILE);
	}
	if (level4) {
		DeleteObject(hbmpBackground);
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK5, IMAGE_BITMAP, 755, 366, LR_LOADFROMFILE);
	}
	if (level5) {
		DeleteObject(hbmpBackground);
		hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK6, IMAGE_BITMAP, 1299, 621, LR_LOADFROMFILE);
	}

	if (hbmpBackground == NULL) {
		MessageBox(hwnd, "bmp file not find", "ERROR!", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
}

// 载入图像
void LoadBmp(HWND hwnd) {

	BackgroundLoad(hwnd);
	LoadInfo(hwnd);
	LoadPlayer(hwnd);
	LoadArmy(hwnd);
}

// 游戏绘制
void GamePaint(hwnd) {

	HDC hdc, hdcmem;
	HDC test;
	HBITMAP hbmMem, hbmMem2;
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

	// 绘制背景
	SelectObject(hdcmem, hbmpBackground);
	GetObject(hbmpBackground, sizeof(BITMAP), &bmp);
	StretchBlt(test, rect.left, rect.top, rect.right - rect.left,
		rect.bottom - rect.top, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	// 输出游戏信息
	PaintInfo(test, hdcmem);

	// 绘制敌人
	PaintArmy(test, hdcmem);

	// 绘制玩家
	if (player.d == RIGHT) {
		if (pressright > 1)
			MoveR_Paint(test, hdcmem);
		else
			StandR_Paint(test, hdcmem);
	}
	else {
		if (pressleft > 1)
			MoveL_Paint(test, hdcmem);
		else
			StandL_Paint(test, hdcmem);
	}

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

	// 绘制黑色透明背景
	SelectObject(hdcmem, hbmpBlack);
	GetObject(hbmpBlack, sizeof(BITMAP), &bmp);
	AlphaBlend(test, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, bf); // 绘制指定透明度的位图  

	 // 一次性绘制到目标窗口
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, test, 0, 0, SRCCOPY);

	DeleteObject(test);
	DeleteObject(hbmMem2);
	DeleteObject(hbmMem);
	DeleteObject(hdcmem);
	ReleaseDC(hwnd, hdc);
}

// 绘制动画、转场过渡
void Paint(HWND hwnd) {

	if (anima)
		BeginAnima(hwnd);
	else {
		if (!flag)
			MenuPaint(hwnd);
		else
			GamePaint(hwnd);
	}
}
void Change(HWND hwnd) {

	if (bTrans <= 234 && !flag) {
		bTrans += 18;
		bf.SourceConstantAlpha = bTrans;
		InvalidateRect(hwnd, NULL, FALSE);
	}
	else {
		flag = TRUE;
		if (next && bTrans <= 234) {
			bTrans += 18;
			bf.SourceConstantAlpha = bTrans;
			InvalidateRect(hwnd, NULL, FALSE);
		}
		else {
			if (TRUE == next) {
				BackgroundLoad(hwnd);
				attackresponse = FALSE;
				next = FALSE;
				Sleep(50);
				PlayBGM();
			}
			if (bf.SourceConstantAlpha > 0) {
				bTrans -= 18;
				bf.SourceConstantAlpha = bTrans;
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}
	}
}

// 玩家放大招
void BigFire() {

	if (5 <= player.fire) {
		bigstart = TRUE;
		bigx = player.x + P_Width;
		bigy = player.y + 15;
		bigd = player.d;
		player.fire = 0;
		big = 0;
	}
}

// 判断游戏是否结束
void OverPaint(HWND hwnd) {

	if (IfDead()) {

		Sleep(555);
		StopBGM();

		HDC hdc, hdcmem;
		HBITMAP hbmMem;
		RECT rect;
		BITMAP bmp;

		GetClientRect(hwnd, &rect); // 把客户区的大小写进Rect结构中
		hdc = GetDC(hwnd);
		hdcmem = CreateCompatibleDC(hdc);
		hbmMem = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
		SelectObject(hdcmem, hbmMem);

		FillRect(hdcmem, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		// 绘制背景
		SelectObject(hdcmem, hbmpBlack);
		GetObject(hbmpBlack, sizeof(BITMAP), &bmp);
		TransparentBlt(hdc, 0, 0, Width, Height, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, COLOR_Mark);

		// 绘制结束LOGO
		SelectObject(hdcmem, hbmpEnd);
		GetObject(hbmpEnd, sizeof(BITMAP), &bmp);
		TransparentBlt(hdc, (Width - 450) / 2, (Height - 450) / 2,
			450, 450, hdcmem, 0, 0, 1440, 1543, COLOR_Mark);

		DeleteObject(hbmMem);
		DeleteObject(hdcmem);
		ReleaseDC(hwnd, hdc);

		PlaySound("seeya.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		destorylist();
		Sleep(1500);
		GameState = GAMEOVER;
	}
}

// 判断游戏是否通关
void PassGame(HWND hwnd) {
	if (TRUE == level6) {

		Sleep(666);
		StopBGM();

		HDC hdc, hdcmem;
		HBITMAP hbmMem;
		RECT rect;
		BITMAP bmp;

		GetClientRect(hwnd, &rect); //把客户区的大小写进Rect结构中
		hdc = GetDC(hwnd);
		hdcmem = CreateCompatibleDC(hdc);
		hbmMem = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);
		SelectObject(hdcmem, hbmMem);

		FillRect(hdcmem, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		// 绘制背景
		SelectObject(hdcmem, hbmpBlack);
		GetObject(hbmpBlack, sizeof(BITMAP), &bmp);
		TransparentBlt(hdc, 0, 0, Width, Height, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, COLOR_Mark);

		// 绘制通关LOGO
		SelectObject(hdcmem, hbmpPass);
		GetObject(hbmpPass, sizeof(BITMAP), &bmp);
		TransparentBlt(hdc, (Width - 720) / 2, (Height - 600) / 2,
			720, 600, hdcmem, 0, 0, 1299, 1063, COLOR_Mark);

		DeleteObject(hbmMem);
		DeleteObject(hdcmem);
		ReleaseDC(hwnd, hdc);

		PlaySound("applause.wav", NULL, SND_FILENAME | SND_ASYNC );
		destorylist();
		Sleep(3333);
		GameState = GAMEOVER;
	}
}

// 游戏进程
void OnTimer(HWND hwnd){

	if (!level1)
		CreateArmy_level1();
	else if (!level2) 
		CreateArmy_level2();
	else if (!level3)
		CreateArmy_level3();
	else if (!level4)
		CreateArmy_level4();
	else if (!level5)
		CreateArmy_level5();
	else if (!level6)
		CreateArmy_level6();

	if (ArmyNum() > 0) {
		MoveArmy();
		ArmyAttack();
	}
}

// 游戏暂停（声音暂停）
//void GamePause(HWND hwnd) {
//
//	if (STARTMENU == GameState) {
//		KillTimer(hwnd, MENU);
//		mciSendString("pause MEM", 0, 0, 0);
//	}
//	else if (GAMELOOP == GameState)
//		KillTimer(hwnd, GAME);
//
//	if (!level1)
//		mciSendString("pause SOUND1", 0, 0, 0);
//	else if (level1 && !level2)
//		mciSendString("pause SOUND2", 0, 0, 0);
//	else if (level2 && !level3)
//		mciSendString("pause SOUND3", 0, 0, 0);
//	else if (level3 && !level4)
//		mciSendString("pause SOUND4", 0, 0, 0);
//	else if (level4 && !level5)
//		mciSendString("pause SOUND5", 0, 0, 0);
//	else if (level5 && !level6)
//		mciSendString("pause SOUND6", 0, 0, 0);
//}

//// 继续游戏（开始声音）
//void GameRe(HWND hwnd) {
//	if (STARTMENU == GameState) {
//		SetTimer(hwnd, MENU, 40, NULL);
//		mciSendString("play MEM", 0, 0, 0);
//	}
//	else if (GAMELOOP == GameState)
//		SetTimer(hwnd, GAME, 60, NULL);
//
//	if (!level1)
//		mciSendString("play SOUND1", 0, 0, 0);
//	else if (level1 && !level2)
//		mciSendString("play SOUND2", 0, 0, 0);
//	else if (level2 && !level3)
//		mciSendString("play SOUND3", 0, 0, 0);
//	else if (level3 && !level4)
//		mciSendString("play SOUND4", 0, 0, 0);
//	else if (level4 && !level5)
//		mciSendString("play SOUND5", 0, 0, 0);
//	else if (level5 && !level6)
//		mciSendString("play SOUND6", 0, 0, 0);
//}

// 响应键盘
void OnKeyDown(DWORD vk){

	if (GameState == STARTMENU) {
		switch (vk) {
		case VK_UP:
			MenuSelect--;
			if (MenuSelect < 0)
				MenuSelect++;
			break;
		case VK_DOWN:
			MenuSelect++;
			if (MenuSelect > MenuCount)
				MenuSelect--;
			break;
		case VK_RETURN:
			mciSendString("open menuhit.wav alias HIT", NULL, 0, NULL);
			mciSendString("play HIT", 0, 0, 0);
			if (MenuSelect == START) {
				GameState = GAMELOOP;
				mciSendString("close MEM", 0, 0, 0);
				mciSendString("open GALAXY.wav alias SOUND1", NULL, 0, NULL);
				mciSendString("play SOUND1", 0, 0, 0);
			}
			else if (MenuSelect == EXIT) {
				GameState = GAMEOVER;
				Sleep(222);
			}
			break;
		}
	}
	else if (GameState == GAMELOOP) {
		switch (vk) {
		case VK_LEFT:
			PlayerMove(LEFT);
			pressleft++;
			break;
		case VK_RIGHT:
			PlayerMove(RIGHT);
			pressright++;
			break;
		case VK_UP:
			PlayerMove(UP);
			if (player.d == RIGHT)
				pressright++;
			else
				pressleft++;
			break;
		case VK_DOWN:
			PlayerMove(DOWN);
			if (player.d == RIGHT)
				pressright++;
			else
				pressleft++;
			break;
		case VK_SPACE:
			BigFire();
			break;
		case 0x58:
			attackresponse = TRUE;
			PlaySound("6055.wav", NULL, SND_FILENAME | SND_ASYNC);
			/*mciSendString("close BIU", 0, 0, 0);
			mciSendString("open 6055.wav alias BIU", NULL, 0, NULL);
			mciSendString("play BIU", 0, 0, 0);*/
			break;
		}
	}
}

// 游戏初始化
void CreateGame(HWND hwnd) {

	// 设置随机数种子，需要使用随机数生成怪物坐标
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft); // 获取系统时间
	srand(ft.dwLowDateTime);

	// 初始化和载入图像工作
	Player_Inite();
	init();
	LoadBmp(hwnd);
	LoadSurface(hwnd);

	// 设置菜单计时器
	SetTimer(hwnd, MENU, 47, NULL);

	// 透明度设置
	bTrans = 255;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = bTrans;

	// 菜单BGM
	mciSendString("open MKAlieZ1.wav alias MEM", NULL, 0, NULL);
	mciSendString("play MEM", 0, 0, 0);
}

// 回调函数
LONG CALLBACK MainWndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_CREATE:
		CreateGame(hwnd);
		break;
	case WM_PAINT:
		Paint(hwnd);
		break;
	case WM_KEYDOWN:
		if (!anima)
			OnKeyDown(wParam);
		break;
	case WM_KEYUP:
		pressleft = 0;
		pressright = 0;
		break;
	case WM_TIMER:
		Anima(hwnd);
		if (!anima) {
			switch (wParam) {
			case MENU:
				if (GameState == STARTMENU)
					MenuPaint(hwnd);
				else if (GameState==GAMELOOP){
					KillTimer(hwnd, MENU);
					SetTimer(hwnd, GAME, 60, NULL);
				}
				else if (GameState == GAMEOVER) {
					KillTimer(hwnd, MENU);
					destorylist();
					ExitProcess(0);
				}
				break;
			}
			if (GameState == GAMELOOP){
				Change(hwnd);
				if (bTrans <= 0) {
					OnTimer(hwnd);
					switch (wParam) {
					case GAME:
						if (attackresponse == FALSE && (!level1 || !level2 || !level3 || !level4 || !level5 || !level6))
							GamePaint(hwnd);
						else if(!level1 || !level2 || !level3 || !level4 || !level5 || !level6)
							AttackPaint(hwnd);
						if (TRUE == bigstart)
							BigAttack();
						if (attack == Attack / 2)
							AttackArmy();
						else if (attack == Attack)
							attackresponse = FALSE;
						break;
					default:
						break;
					}
					OverPaint(hwnd);
					PassGame(hwnd);
				}
			}
			if (GameState == GAMEOVER) {
				KillTimer(hwnd, MENU);
				KillTimer(hwnd, GAME);
				ExitProcess(0);
			}
		}
		break;
	case WM_KILLFOCUS:
		if (GameState == GAMELOOP) 
			KillTimer(hwnd, GAME);
		// GamePause(hwnd);
		break;
	case WM_SETFOCUS:
		if (GameState == GAMELOOP) 
			SetTimer(hwnd, GAME, 60, NULL);		
		// GameRe(hwnd);
		break;
	case WM_DESTROY:
		ExitProcess(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// 程序入口
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	int fGotMessage;

	hinst = hinstance;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hinstance;
	wc.hIcon =LoadImage(NULL, ".\\FIGHT\\LOGO\\ff.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wc.hCursor = LoadImage(NULL, ".\\FIGHT\\CUR\\Droid.NormalSelect.cur", IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE); //本地加载自定义icon图标
	wc.hbrBackground = NULL;
	wc.lpszMenuName = "MainMenu";
	wc.lpszClassName = "MainWClass";

	if (!RegisterClass(&wc)){
		MessageBox(NULL, "创建窗口class失败", "错误！", MB_ICONERROR | MB_OK);
		return -1;
	}

	hwnd = CreateWindow(
		"MainWClass",
		"STAR WARS",
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME,
		CW_USEDEFAULT,			// 窗口水平位置
		CW_USEDEFAULT,		    // 窗口垂直位置
		Width,			        // 窗口宽度
		Height,			        // 窗口高度
		(HWND)NULL,
		(HMENU)NULL,
		hinstance,				// 应用程序实例句柄
		(LPVOID)NULL);

	if (!hwnd){
		MessageBox(NULL, "创建窗口失败", "错误！", MB_ICONERROR | MB_OK);
		return -1;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && fGotMessage != -1){
		TranslateMessage(&msg); // 将虚拟键消息转换为字符消息
		DispatchMessage(&msg); // 消息被分发到回调函数
	}

	return msg.wParam;
}