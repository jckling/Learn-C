#include "Tetirs.h"

#define COLOR_TEXT		RGB(255,255,255)


HWND hWnd = NULL; // 游戏窗口句柄
HPEN hPen = NULL; // 用于绘制场景的画笔
// 用于绘制方块的画刷
HBRUSH hBrush = NULL;
HBRUSH hWhiteBrush = NULL;
HBRUSH hBlackBrush = NULL;
// 窗口的宽和高
#define W 600
#define H 500
// 场景的原点（左上角）位置
#define oX 25
#define oY 25

// 定义游戏场景的宽和高
#define sW 300
#define sH 400
// 方块（正方形）的边长(Length of Side)
#define L 20

// 游戏工作线程函数，实现不断将方块向下移动的功能
DWORD WINAPI Run(LPVOID lpPrarm)
{
	while (!GameOver)
	{
		Sleep(500 - 100 * level);
		if (TryMoveDown(&tetris))
		{
			// 向下移动方块
			MoveDown(&tetris);
			// 刷新屏幕，在新的位置绘制俄罗斯方块
			InvalidateRect(hWnd, NULL, TRUE);
		}
		else
		{
			if (MergeBlock(&tetris))
			{
				InitTetris();
				// 判断是否合并一整行并积分
				IfClearRow();
			}
			else
			{
				GameOver = 1;
			}

		}
	}

	return 0;
}

// 对绘制所需的画笔画刷进行初始化
void InitDrawing()
{
	// 创建填充色实心画笔
	hPen = CreatePen(PS_SOLID, 3, RGB(0, 245, 255));
	// 创建填充色画刷
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	// 创建黑色背景画刷
	hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
}

// 清理绘图用到的工具
void CleanDrawing()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteObject(hBlackBrush);
}

// 显示游戏信息
BOOL DrawInfo(HDC hDC)
{
	HFONT hFont, hOldFont;
	hFont = CreateFont(40, 0, 0, 0, FW_DONTCARE, 0, 0, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Cursive"));
	if (hOldFont = (HFONT)SelectObject(hDC, hFont))
	{
		SetTextColor(hDC, COLOR_TEXT);
		SetBkMode(hDC, TRANSPARENT); // 设置文本输出区域背景透明
		CHAR str1[1024];
		wsprintf(str1, "Sorce %d", GetScore());
		TextOut(hDC, sW+70, 150, str1, lstrlen(str1));
		CHAR str2[1024];
		wsprintf(str2, "Level %d", GetLevel());
		TextOut(hDC, sW+70, 220, str2, lstrlen(str2));
		// 输出完成，将原来的字体对象放回DC中
		SelectObject(hDC, hOldFont);
	}
	return 1;
}

// 绘制场景，也就是绘制一个矩形框
// 表示游戏范围
BOOL DrawScene(HDC hDC)
{
	// 定义五个点，用线连接这些点，
	// 围成一个矩形
	POINT pntArray[5];

	// 第一个点和最后一个点在同一位置
	pntArray[0].x = pntArray[4].x = oX;
	pntArray[0].y = pntArray[4].y = oY;

	pntArray[1].x = sW + oX;
	pntArray[1].y = oY;

	pntArray[2].x = sW + oX;
	pntArray[2].y = sH + oY;

	pntArray[3].x = oX;
	pntArray[3].y = sH + oY;

	HPEN hOldPen = SelectObject(hDC, hPen);

	// 绘制表示游戏场景的矩形
	Polyline(hDC, pntArray, 5);

	// 重新选中原来的画笔
	SelectObject(hDC, hOldPen);
	
	return 1;
}

// 在指定的位置（row,col）绘制一个方块
void DrawBlockRect(HDC hDC, const int row, const int col)
{
	// 定义表示方块范围的矩形
	RECT rc;
	rc.left = col*L + oX; // 原点的起始坐标加上偏移的距离
	rc.right = (col + 1)*L + oX;
	rc.top = row*L + oY;
	rc.bottom = (row + 1)*L + oY;

	// 用白色画刷刷出背景
	FillRect(hDC, &rc, hWhiteBrush);

	// 缩小矩形一个像素
	rc.left += 1;
	rc.right -= 1;
	rc.top += 1;
	rc.bottom -= 1;

	// 用填充画刷在白色背景上刷出矩形
	// 看起来就像矩形有了白色描边
	FillRect(hDC, &rc, hBrush);
}

// 绘制场景中的方块
void DrawBlock(HDC hDC)
{
	// 遍历整个方块数组
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			// 如果有方块，则绘制方块
			if (blocks[i][j])
			{
				// 在（i,j）位置绘制方块
				DrawBlockRect(hDC, i, j);
			}
		}
	}
}
// 绘制移动的tetris
void DrawTetris(HDC hDC)
{
	// 要绘制一个大的俄罗斯方块
	// 只需要这个绘制其中的小方块
	for (int i = 0; i < N; ++i)
	{
		DrawBlockRect(hDC,
			tetris.y[i], // 行
			tetris.x[i]); // 列
	}
}

// 绘制函数，响应WM_PAINT消息
// 负责整个窗口的绘制
void GamePaint()
{
	PAINTSTRUCT ps;

	// 为窗口绘图进行准备工作，
	// 将和绘图有关的信息填充到一个PAINTSTRUCT结构中
	HDC hDC = BeginPaint(hWnd, &ps);

	// 显示游戏信息
	DrawInfo(hDC);
	// 绘制场景
	DrawScene(hDC);
	// 绘制场景中的方块
	DrawBlock(hDC);
	// 绘制移动的俄罗斯方块
	DrawTetris(hDC);

	// 标记指定窗口的绘画过程结束
	EndPaint(hWnd, &ps);
}

// 根据不同的按键消息，调用相应函数进行处理
void OnKeyDown(WPARAM key)
{
	switch (key)
	{
	case VK_RIGHT:  // 向右方向键
		OnKeyDownRight();
		break;
	case VK_LEFT:  // 向左方向键
		OnKeyDownLeft();
		break;
	case VK_DOWN:  // 向下方向键
		OnKeyDownDown();
		break;
	case VK_UP:
		break;
	case VK_SPACE:
		break;
	default:
		break;
	}
}

// 窗口消息处理函数
// 为各种消息指定响应函数，完成消息的处理
LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT: // 绘制
		GamePaint();
		break;
	case WM_KEYDOWN:  
		OnKeyDown(wParam);
		GamePaint();
		break;
	case WM_DESTROY: // 关闭窗口，游戏结束
		GameOver = 1;
		ExitProcess(0);
		break;
	default:
		break;
	};

	// 采用默认的窗口消息处理
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// 注册窗口类
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	// 设置窗口属性
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	// 窗口风格
	wc.style = CS_HREDRAW | CS_VREDRAW;
	// 窗口消息处理函数，将函数指针赋值给这个数据
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	// 关联的程序实例，由主函数WinMain()传递而来
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // 鼠标样式
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);// 背景刷
	wc.lpszMenuName = NULL;
	// 窗口类的名字，在创建窗口的时候，将根据这个名字
	// 找到对应的窗口类
	wc.lpszClassName = "Tetirs Game";
	wc.hIconSm = NULL;

	// 注册窗口类
	return RegisterClassEx(&wc);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// 创建一个新的游戏窗口(Windows)
	// 并将返回的窗口句柄保存在window变量
	hWnd = CreateWindow(
		"Tetirs Game", // 注册窗口类时使用的名字
		"Tetirs Game", // 窗口标题栏中显示的标题
				  // 指定创建窗口的风格
		WS_OVERLAPPEDWINDOW,
		// 制定窗口的初始位置
		CW_USEDEFAULT, CW_USEDEFAULT,
		W, H, // 窗口的宽和高
		NULL, // 无父窗口
		NULL, // 无菜单
		hInstance, // 与窗口关联的程序实例句柄
		NULL); // 无附加创建参数

			   // 判断窗口创建是否成功
	if (!hWnd)
	{
		// 窗口创建失败，消息框提示，并退出
		MessageBox(NULL, "创建窗口失败", "错误！", MB_ICONERROR | MB_OK);
		return -1;
	}

	// 如果创建窗口成功则显示窗口
	ShowWindow(hWnd, nCmdShow);
	// 更新（绘制）窗口
	UpdateWindow(hWnd);

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 初始化游戏窗口和俄罗斯方块
	Inite();

	// 注册窗口类
	MyRegisterClass(hInstance);

	// 初始化应用程序，创建并显示窗口
	if (!InitInstance(hInstance, nCmdShow)) return 0;

	// 定义一个方块
	InitTetris();
	InitDrawing();

	// 创建单独的游戏线程
	HANDLE hRun = CreateThread(NULL, 0, Run, NULL, 0, NULL);

	// 消息循环，在整个游戏进行期间都持续
	while (!GameOver)
	{
		MSG msg;
		// 检查窗口的消息队列是否存在新消息
		// 如果存在，则将其取出存到msg结构体变量
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// 将虚拟键消息转换为字符消息
			TranslateMessage(&msg);
			// 将消息分发给消息处理函数
			DispatchMessage(&msg);
		}
	}

	// 消息循环结束，意味着程序结束。执行清理工作
	CleanDrawing();

	return 0;
}