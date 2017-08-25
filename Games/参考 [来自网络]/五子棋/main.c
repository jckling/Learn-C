#include <windows.h>
#pragma comment(lib,"Msimg32.lib")
#pragma comment(lib,"winmm.lib") // 导入声音的链接库  

#define WINDOW_WIDTH    540
#define WINDOW_HEIGHT   560
#define WINDOW_TITLE    "五子棋"

int map[15][15];
int NowPlayer;		// 当前棋手（黑或白）

int g_nx;	// 当前鼠标坐标
int g_ny;

int g_mx;	// 当前鼠标坐标对应map的位置
int g_my;

HDC g_hdc = NULL, g_mdc = NULL, g_tdc = NULL; // 设备DC 
HBITMAP g_hmap = NULL;	   // 棋盘句柄
HBITMAP g_hch = NULL;	   // 黑棋句柄
HBITMAP g_hch2 = NULL;	   // 白棋句柄

// 函数声明
LONG CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);
VOID Game_Paint(HWND hwnd);
BOOL Game_CleanUp(HWND hwnd);
VOID MouseMove(LPARAM lParam);
int WinOrNot(int x, int y);

// 程序入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	WNDCLASSEX wndClass = { 0 }; // 定义窗口类
	wndClass.cbSize = sizeof(WNDCLASSEX); // 窗口类字节大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW; // 窗口样式
	wndClass.lpfnWndProc = WndProc; // 窗口过程函数指针
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance; // 窗口句柄
	wndClass.hIcon = LoadImage(NULL, "icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE); // 加载窗口图标
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);// 加载窗口光标
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 灰色刷子刷屏幕
	wndClass.lpszClassName = "Five";// 窗口类名称
	wndClass.lpszMenuName = NULL;// 下拉菜单

	if (!RegisterClassEx(&wndClass))// 注册窗体
		return -1;

	// 创建窗体
	HWND hwnd = CreateWindow("Five", WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH,
		WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	// 窗口移动
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, 1);

	// 窗口显示
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 游戏资源初始化
	if (!Game_Init(hwnd)){
		MessageBox(hwnd, "资源初始化失败", "提示", 0);
		return FALSE;
	}

	// 消息循环
	MSG msg = { 0 };
	while (msg.message != WM_QUIT){
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	UnregisterClass("Five", wndClass.hInstance);
	return 0;
}

// 回调函数
LONG CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	//PAINTSTRUCT paintStruct;

	switch (message){
	case WM_TIMER:						// 定时器消息
		Game_Paint(hwnd);                // 调用Game_Paint（）函数进行窗口绘图
		break;

		//case WM_PAINT:
		//	g_hdc=BeginPaint( hwnd,&paintStruct);
		//	Game_Paint( hwnd);
		//	EndPaint(hwnd,&paintStruct);
		//	ValidateRect(hwnd,NULL);  //刷新界面
		//	break;

	case WM_KEYDOWN:
		switch (wParam){
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		default:
			MessageBox(NULL, "ESC键退出程序", "提示", 0);
			break;
		}
		break;

	case WM_LBUTTONDOWN:	// 鼠标左键按下
		if (NowPlayer == 1){
			if (map[g_mx][g_my] == 0){
				map[g_mx][g_my] = 1;
				WinOrNot(g_mx, g_my);
				PlaySound(L"MC.wav", NULL, SND_FILENAME | SND_ASYNC);
				NowPlayer = 2;
			}
			else
				PlaySound(L"Close.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (NowPlayer == 2){
			if (map[g_mx][g_my] == 0){
				map[g_mx][g_my] = 2;
				WinOrNot(g_mx, g_my);
				PlaySound(L"MC.wav", NULL, SND_FILENAME | SND_ASYNC);
				NowPlayer = 1;
			}
			else
				PlaySound(L"Close.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		break;
	case WM_MOUSEMOVE:		// 鼠标移动
		MouseMove(lParam);		// 获取当前对应的map坐标
		break;
	case WM_DESTROY:
		Game_CleanUp(hwnd);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

// 游戏初始化
BOOL Game_Init(HWND hwnd){
	HBITMAP bmp;// 创建位图对象

	g_hdc = GetDC(hwnd);
	g_hmap = (HBITMAP)LoadImage(NULL, "棋盘.bmp", IMAGE_BITMAP, 535, 535, LR_LOADFROMFILE);  // 22,22为棋盘第一个点
	g_hch = (HBITMAP)LoadImage(NULL, "黑棋.bmp", IMAGE_BITMAP, 32, 32, LR_LOADFROMFILE);
	g_hch2 = (HBITMAP)LoadImage(NULL, "白棋.bmp", IMAGE_BITMAP, 32, 32, LR_LOADFROMFILE);
	g_mdc = CreateCompatibleDC(g_hdc);
	g_tdc = CreateCompatibleDC(g_hdc);
	bmp = CreateCompatibleBitmap(g_hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(g_mdc, bmp);

	// 初始化棋盘
	for (int x = 0; x <= 14; x++){
		for (int y = 0; y <= 14; y++){
			map[x][y] = 0;
		}
	}
	SetTimer(hwnd, 1, 15, NULL); // 90毫秒发送一个消息
	NowPlayer = 1;
	Game_Paint(hwnd);
	//ReleaseDC(hwnd,g_hdc);

	return TRUE;
}

// 游戏绘制与刷新
VOID Game_Paint(HWND hwnd){
	// 画棋盘
	SelectObject(g_tdc, g_hmap);
	BitBlt(g_mdc, 0, 0, 535, 535, g_tdc, 0, 0, SRCCOPY);

	// 1为黑棋，2为白棋
	for (int x = 0; x <= 14; ++x){
		for (int y = 0; y <= 14; ++y){
			if (map[x][y] == 1){
				SelectObject(g_tdc, g_hch);
				TransparentBlt(g_mdc, x * 35 + 22 - 16, y * 35 + 22 - 16, 32, 32, g_tdc, 0, 0, 32, 32, RGB(255, 255, 255));
			}
			else if (map[x][y] == 2){
				SelectObject(g_tdc, g_hch2);
				TransparentBlt(g_mdc, x * 35 + 22 - 16, y * 35 + 22 - 16, 32, 32, g_tdc, 0, 0, 32, 32, RGB(255, 255, 255));
			}
		}
	}


	// 在当前光标位置画个黑棋，随着鼠标的移动而改变
	if (NowPlayer == 1){
		SelectObject(g_tdc, g_hch);
		TransparentBlt(g_mdc, g_mx * 35 + 22 - 16, g_my * 35 + 22 - 16, 32, 32, g_tdc, 0, 0, 32, 32, RGB(255, 255, 255));
	}
	else if (NowPlayer == 2){
		SelectObject(g_tdc, g_hch2);
		TransparentBlt(g_mdc, g_mx * 35 + 22 - 16, g_my * 35 + 22 - 16, 32, 32, g_tdc, 0, 0, 32, 32, RGB(255, 255, 255));
	}
	BitBlt(g_hdc, 0, 0, 540, 560, g_mdc, 0, 0, SRCCOPY);
}
BOOL Game_CleanUp(HWND hwnd){
	KillTimer(hwnd, 1);   // 删除所建立的定时器  
	DeleteObject(g_hmap);
	DeleteObject(g_hch);
	DeleteObject(g_hch2);
	DeleteDC(g_mdc);
	DeleteDC(g_hdc);
	ReleaseDC(hwnd, g_hdc);

	return TRUE;
}

// 鼠标移动 计算光标在棋盘上的位置
VOID MouseMove(LPARAM lParam){
	g_nx = LOWORD(lParam);
	g_ny = HIWORD(lParam);
	for (int x = 0; x <= 14; ++x){
		for (int y = 0; y <= 14; ++y){
			if (g_nx >= x * 35 + 22 - 16 && g_nx <= x * 35 + 22 + 16 && g_ny >= y * 35 + 22 - 16 && g_ny <= y * 35 + 22 + 16){
				g_mx = x;
				g_my = y;
			}
		}
	}
}

// 判断输赢
int WinOrNot(int x, int y){
	int tx = 0, ty = 0;
	int playernum;
	int i;
	int cnum = 0;

	playernum = map[x][y];

	//一三象限检测
	for (i = 1; i <= 4; i++){
		//第一象限
		if (x + i <= 14 && y - i >= 0 && map[x + i][y - i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break第一象限", "提示",0);
	}

	for (i = 1; i <= 4; i++){
		//第三象限
		if (x - i >= 0 && y + i <= 14 && map[x - i][y + i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break第三象限", "提示",0);
	}
	if (cnum == 4){
		cnum = 0;
		if (playernum == 1){
			MessageBox(NULL, "黑棋赢了", "提示", 0);
			//初始化棋盘
			for (tx = 0; tx <= 14; tx++){
				for (ty = 0; ty <= 14; ty++){
					map[tx][ty] = 0;
				}
			}
			NowPlayer = 1;
		}
		else{
			MessageBox(NULL, "白棋赢了", "提示", 0);
			//初始化棋盘
			for (tx = 0; tx <= 14; tx++){
				for (ty = 0; ty <= 14; ty++){
					map[tx][ty] = 0;
				}
			}
			NowPlayer = 1;
		}
		return 0;
	}
	else
		cnum = 0;

	//二四象限判断
	for (i = 1; i <= 4; i++){
		//第四象限
		if (x - i >= 0 && y - i >= 0 && map[x - i][y - i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break第四象限", "提示",0);
	}

	for (i = 1; i <= 4; i++){
		//第二象限
		if (x + i <= 14 && y + i <= 14 && map[x + i][y + i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break第二象限", "提示",0);
	}
	if (cnum == 4){
		cnum = 0;
		if (playernum == 1)
			MessageBox(NULL, "黑棋赢了", "提示", 0);
		else
			MessageBox(NULL, "白棋赢了", "提示", 0);
		//MessageBox(NULL, "赢在二四象限", "提示",0);
		return 0;
	}
	else
		cnum = 0;

	//垂直判断
	for (i = 1; i <= 4; i++){
		//向上
		if (y - i >= 0 && map[x][y - i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break上", "提示",0);
	}

	for (i = 1; i <= 4; i++){
		//向下
		if (y + i <= 14 && map[x][y + i] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break下", "提示",0);
	}
	if (cnum == 4){
		cnum = 0;
		if (playernum == 1)
			MessageBox(NULL, "黑棋赢了", "提示", 0);
		else
			MessageBox(NULL, "白棋赢了", "提示", 0);
		//MessageBox(NULL, "赢在垂直判断", "提示",0);
		return 0;
	}
	else
		cnum = 0;


	// 水平判断
	for (i = 1; i <= 4; i++){
		// 向左
		if (x - i >= 0 && map[x - i][y] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break左", "提示", 0);
	}

	for (i = 1; i <= 4; i++){
		// 向右
		if (x + i <= 14 && map[x + i][y] == playernum){
			cnum++;
		}
		else
			break;
		//MessageBox(NULL, "看看是否break右", "提示", 0);
	}
	if (cnum == 4){
		cnum = 0;
		if (playernum == 1)
			MessageBox(NULL, "黑棋赢了", "提示", 0);
		else
			MessageBox(NULL, "白棋赢了", "提示", 0);
		//MessageBox(NULL, "赢在水平判断", "提示", 0);
		return 0;
	}
	else
		cnum = 0;
}