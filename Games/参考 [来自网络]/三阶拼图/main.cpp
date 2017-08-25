#include <windows.h>
#include  <time.h>  // 使用获取系统时间time函数需要包含的头文件
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")  // 导入声音的链接库  

#define WINDOW_WIDTH    1000
#define WINDOW_HEIGHT   550
#define WINDOW_TITLE    "三阶拼图"

int g_nx;	// 当前鼠标坐标
int g_ny;
int map[3][3]={0};

HDC g_hdc = NULL, g_mdc = NULL, g_tdc = NULL;
HBITMAP g_hmap = NULL;  // 要拼的图片
HBITMAP g_hbgp = NULL;  // 背景图片

// 函数声明
LONG CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Game_Init(HWND hwnd);
VOID Game_Paint( HWND hwnd);
BOOL Game_CleanUp(HWND hwnd);
VOID LoadMap();
int Game_MouseDown();

// 入口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	WNDCLASSEX wndClass={ 0 }; // 定义窗口类
	wndClass.cbSize = sizeof(WNDCLASSEX); // 窗口类字节大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW; // 窗口样式
	wndClass.lpfnWndProc = WndProc; // 窗口过程函数指针
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance; // 窗口句柄
	wndClass.hIcon = (HICON)::LoadImage(NULL, "icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE); // 加载窗口图标
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);// 加载窗口光标
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 灰色刷子刷屏幕
	wndClass.lpszClassName = "Ping";// 窗口类名称
	wndClass.lpszMenuName = NULL;// 下拉菜单

	if (!RegisterClassEx(&wndClass))// 注册窗体
		return -1;

	// 创建窗体
	HWND hwnd = CreateWindow("Ping", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
    
	// 窗口移动
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	
	// 窗口显示
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);
	
	//游戏资源初始化
	if (!Game_Init(hwnd)){
		MessageBox(hwnd, "资源初始化失败", "提示", 0);
		return FALSE;
	}

	//消息循环
	MSG msg={0};
	while(msg.message != WM_QUIT){
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Game_Paint(hwnd);
	}

	UnregisterClass("Ping", wndClass.hInstance);
	return 0;
}

// 回调函数
LONG CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message){
	case WM_DESTROY:
		Game_CleanUp(hwnd);
		PostQuitMessage(0);
		break;
	case WM_MOUSEMOVE:
		g_nx=LOWORD(lParam);
		g_ny=HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:
		Game_MouseDown();
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

// 游戏初始化
BOOL Game_Init(HWND hwnd){
	LoadMap();
	HBITMAP bmp; // 创建位图对象
	g_hdc=GetDC(hwnd);

	g_hmap = (HBITMAP)LoadImage(NULL, "1.bmp", IMAGE_BITMAP, 480, 480, LR_LOADFROMFILE);  
	g_hbgp = (HBITMAP)LoadImage(NULL, "2.bmp", IMAGE_BITMAP, WINDOW_WIDTH, WINDOW_HEIGHT, LR_LOADFROMFILE);
	g_mdc = CreateCompatibleDC(g_hdc);
	g_tdc = CreateCompatibleDC(g_hdc);
	bmp = CreateCompatibleBitmap(g_hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(g_mdc,bmp);
	
	return TRUE;
}

// 游戏更新
VOID Game_Paint( HWND hwnd)
{
	int x, y;

	SelectObject(g_tdc, g_hbgp);//画背景
	BitBlt(g_mdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_tdc, 0, 0, SRCCOPY);

	for (x = 0; x < 3; x++){
		for (y=0;y<3;y++){		
			if (map[x][y] != 9 && map[x][y] % 3 != 0){
				SelectObject(g_tdc, g_hmap);
				BitBlt(g_mdc, x * 160, y * 160, 160, 160, g_tdc, (map[x][y] % 3 - 1) * 160, map[x][y] / 3 * 160, SRCCOPY);
			}
			else if (map[x][y] != 9 && map[x][y] % 3 == 0){
				SelectObject(g_tdc,g_hmap);
				BitBlt(g_mdc,x*160,y*160,160,160,g_tdc,2*160,(map[x][y]/3-1)*160,SRCCOPY);
			}
		}
	}
	/*for (x=0;x<3;x++)
	{
		for (y=0;y<3;y++)
		{
			if (g_nx<160*x && g_nx>160*(x+1) && g_ny>160*y && g_ny<160*(y+1));
		}
	}
	*/

	SelectObject(g_tdc, g_hmap);  // 画对照图片
	BitBlt(g_mdc, 520, 0, 480, 480, g_tdc, 0, 0, SRCCOPY);
	BitBlt(g_hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_mdc, 0, 0, SRCCOPY);  // 全部贴图
}
BOOL Game_CleanUp(HWND hwnd){
	DeleteObject(g_hmap);
	DeleteObject(g_tdc);
	DeleteDC(g_mdc);
	DeleteDC(g_hdc);
	ReleaseDC(hwnd, g_hdc);

	return TRUE;
}

// 加载图像
VOID LoadMap(){
	/*
	随机算法：
		1.找到9
		2.随机9的上下左右四个方向
	*/
	int x, y, i, k;
	i = 0;

	for (x = 0; x < 3; x++){
		for (y = 0; y < 3; y++){
			map[x][y] = y * 3 + x + 1;
		}
	}

	srand((unsigned)time(NULL));

	//随机按90次
	for (k = 0; k < 90; k++){
		for (x = 0; x < 3; x++) {
			for (y = 0; y < 3; y++) {
				if (map[x][y] == 9) {
					do {
						i = rand() % 4 + 1;
						switch (i) {
						case 1:
							if (y - 1 >= 0) {
								map[x][y] = map[x][y - 1];
								map[x][y - 1] = 9;
								i = 1;
							}
							break;
						case 2:
							if (y + 1 <= 2) {
								map[x][y] = map[x][y + 1];
								map[x][y + 1] = 9;
								i = 1;
							}
							break;
						case 3:
							if (x - 1 >= 0) {
								map[x][y] = map[x - 1][y];
								map[x - 1][y] = 9;
								i = 1;
							}
							break;
						case 4:
							if (x + 1 <= 2) {
								map[x][y] = map[x + 1][y];
								map[x + 1][y] = 9;
								i = 1;
							}
							break;
						}
						if (i == 1)
							break;
					} while (1);
				}
			}
		}
	}
}

// 响应鼠标，移动拼图
int Game_MouseDown(){
	int x, y;

	for (x = 0; x < 3; x++){
		for (y = 0; y < 3; y++){
			if (g_nx > x * 160 && g_nx < (x + 1) * 160){
				if (g_ny > y * 160 && g_ny < (y + 1) * 160){
						if (map[x][y - 1] == 9){
							if (y - 1 >= 0){
								map[x][y - 1] = map[x][y];
								map[x][y] = 9;
								PlaySound("Close.wav", NULL, SND_FILENAME | SND_ASYNC);
								return 0;
							}
						}
						if(map[x][y + 1] == 9){
							if (y + 1 <= 2){
								map[x][y + 1] = map[x][y];
								map[x][y] = 9;
								PlaySound("Close.wav", NULL, SND_FILENAME | SND_ASYNC);
								return 0;
							}
						}
						if (map[x - 1][y] == 9){
							if (x - 1 >= 0){
								map[x - 1][y] = map[x][y];
								map[x][y] = 9;
								PlaySound("Close.wav", NULL, SND_FILENAME | SND_ASYNC);
								return 0;
							}
						}
						if (map[x + 1][y] == 9){
							if (x + 1 <= 2){
								map[x + 1][y] = map[x][y];
								map[x][y] = 9;
								PlaySound("Close.wav", NULL, SND_FILENAME | SND_ASYNC);
								return 0;
							}
						}
				}
			}
		}
	}
}