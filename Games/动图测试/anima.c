#include <windows.h>

HINSTANCE hinst;
HBITMAP hbmpBackground;

// 动画测试
HBITMAP man[8];
HWND hwndBackground;
HDC mdc, hdc;
int num;

void AnimaPaint(HDC hdc){
	if (num >= 8)
		num = 0;

	SelectObject(mdc, man[num]);
	BitBlt(hdc, 0, 0, 172, 264, mdc, 0, 0, SRCCOPY);
	num++;
}

void Move(HWND hwnd){	
	hdc = GetDC(hwnd);
	mdc = CreateCompatibleDC(hdc);

	TCHAR fileName[20] = { "" };
	for (int i = 1; i < 9; i++){
		wsprintf(fileName, "%d.bmp", i);
		man[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 172, 264, LR_LOADFROMFILE);
	}
	num = 0;
	SetTimer(hwnd, 1, 35, NULL);

	AnimaPaint(hdc);
}


// 回调函数
LONG CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch (msg){
	case WM_CREATE:
		break;
	case WM_PAINT:
		Move(hwnd);
		break;
	case WM_KEYDOWN:
		break;
	case WM_DESTROY:
		ExitProcess(0);
		break;
	case WM_TIMER:
		AnimaPaint(hdc);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// 入口
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

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
		"Test",		// title-bar string 
		WS_OVERLAPPEDWINDOW,	// 窗口的style，这个表示为top-level window 
		CW_USEDEFAULT,			// 窗口水平位置default horizontal POINT 
		CW_USEDEFAULT,			// 窗口垂直位置default vertical POINT 
		CW_USEDEFAULT,			// 窗口宽度 default width 
		CW_USEDEFAULT,			// 窗口高度 default height 
		(HWND)NULL,				// 父窗口句柄 no owner window 
		(HMENU)NULL,			// 窗口菜单的句柄 use class menu 
		hinstance,				// 应用程序实例句柄 handle to application instance 
		(LPVOID)NULL);			// 指向附加数据的指针 no window-creation data 

	if (!hwnd){
		MessageBox(NULL, "创建窗口失败", "错误！", MB_ICONERROR | MB_OK);
		return -1;
	}

	hbmpBackground = hwnd;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && fGotMessage != -1){
		TranslateMessage(&msg); // 将虚拟键消息转换为字符消息
		DispatchMessage(&msg); // 消息被分发到回调函数
	}
	return msg.wParam;
}