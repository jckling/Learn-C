#include "tic.h"

// 数字的位置坐标
int numx[3] = { 80, 275, 465 };
int numy[3] = { 80, 275, 475 };
// X/O 的位置坐标
int x[3] = { 60,250,455 };
int y[3] = { 50,265,465 };

// 文本颜色
#define COLOR_TEXT RGB(255,255,255)

// 背景图片，X/O 图片
#define BITMAP_FILE_BK		"ttt.bmp"
#define BITMAP_FILE_X		"x.bmp"
#define BITMAP_FILE_O		"o.bmp"

// 绘图用
HINSTANCE hinst;
HBITMAP hbmpBackground;
HBITMAP X;
HBITMAP O;

// 创建背景
LONG BackgroundCreate(HWND hwnd){
	FILETIME ft;

	GetSystemTimeAsFileTime(&ft); // 获取系统时间
	srand(ft.dwLowDateTime);

	X = LoadImage(NULL, BITMAP_FILE_X, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	O = LoadImage(NULL, BITMAP_FILE_O, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	hbmpBackground = LoadImage(NULL, BITMAP_FILE_BK, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (hbmpBackground == NULL || X == NULL || O == NULL){
		MessageBox(hwnd, "bmp file not find", "ERROR!", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	return 0;
}
LONG BackgroundPaint(HWND hwnd){
	HDC hdc, hdcMem;
	RECT rect;
	BITMAP bmp;

	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rect);

	hdcMem = CreateCompatibleDC(hdc);

	SelectObject(hdcMem, hbmpBackground);

	GetObject(hbmpBackground, sizeof(BITMAP), &bmp);

	StretchBlt(hdc,rect.left, rect.top,rect.right - rect.left, rect.bottom - rect.top,hdcMem,
		0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	DeleteObject(hdcMem);
	DeleteDC(hdcMem);
	ReleaseDC(hwnd, hdc);
	DeleteDC(hdc);
	return 0;
}

// 绘制游戏
LONG GamePaint(HWND hwnd){
	HDC hdc, hdcmem;
	RECT rect;
	int i, j;

	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rect);

	hdcmem = CreateCompatibleDC(hdc);

	SelectObject(hdcmem, hbmpBackground);

	SetBkMode(hdcmem, TRANSPARENT); // 设置文本输出区域背景透明

	HFONT hFont = CreateFont(80, 80, 0, 0, FW_DONTCARE, 0, 0, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, "Cursive", NULL);

	HFONT hOldFont;
	if (hOldFont = (HFONT)SelectObject(hdcmem, hFont)){
		CHAR str[1024];
		SetTextColor(hdcmem, COLOR_TEXT);
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (map[i][j] != 'o' && map[i][j] != 'x'){
					wsprintf(str, "%c", map[i][j]);
					TextOut(hdcmem, numx[j], numy[i], str, 1);
				}
			}
		}
	}

	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hdcmem, 0, 0, SRCCOPY);
	
	DeleteObject(hdcmem);
	DeleteObject(hFont);
	ReleaseDC(hwnd, hdc);
	XOPaint(hwnd);
}
LONG XOPaint(HWND hwnd) {
	HDC hdc, hdcmem;
	BITMAP bmp;
	int i, j;

	hdc = GetDC(hwnd);

	hdcmem = CreateCompatibleDC(hdc);

	SelectObject(hdcmem, hbmpBackground);

	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (map[i][j] == 'x'){
				SelectObject(hdcmem, X);
				GetObject(X, sizeof(BITMAP), &bmp);
				StretchBlt(hdc, x[j], y[i], 125, 125, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
			}
			else if (map[i][j] == 'o'){
				SelectObject(hdcmem, O);
				GetObject(O, sizeof(BITMAP), &bmp);
				StretchBlt(hdc, x[j], y[i], 125, 125, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
			}
		}
	}

	DeleteObject(hdcmem);
	ReleaseDC(hwnd, hdc);
}

// 回调函数
LONG CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg){
	case WM_CREATE:
		//MessageBox(NULL, "Hello!", "Welcome", 0);
		BackgroundCreate(hwnd);
		break;
	case WM_PAINT:
		BackgroundPaint(hwnd);
		GamePaint(hwnd);
		break;
	case WM_KEYDOWN:
		if (OnKeyDown(wParam)) {
			GamePaint(hwnd);
			AI(hwnd);
		}
		break;
	case WM_DESTROY:
		ExitProcess(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// 入口
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow){

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
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = "MainMenu";
	wc.lpszClassName = "MainWClass";
	if (!RegisterClass(&wc)){
		MessageBox(NULL, "创建窗口class失败", "错误！", MB_ICONERROR | MB_OK);
		return -1;
	}

	hwnd = CreateWindow(
		"MainWClass",			// 窗口类名，必须是已经注册了的窗口类
		"Tic Tac Toe",		// title-bar string 
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME,	// 窗口的style，这个表示为top-level window 
		CW_USEDEFAULT,			// 窗口水平位置default horizontal POINT 
		CW_USEDEFAULT,			// 窗口垂直位置default vertical POINT 
		670,			// 窗口宽度 default width 
		670,			// 窗口高度 default height 
		(HWND)NULL,				// 父窗口句柄 no owner window 
		(HMENU)NULL,			// 窗口菜单的句柄 use class menu 
		hinstance,				// 应用程序实例句柄 handle to application instance 
		(LPVOID)NULL);			// 指向附加数据的指针 no window-creation data 
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