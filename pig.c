#include "pig.h"

// 野猪初始化
void P_Create(AllType *p) {

	p->x = Width;
	p->y = rand() % (Height - Border - P_Height) + Border;

	p->height = P_Height;
	p->width = P_Width;
	p->sub = P_Sub;

	p->HP = P_Life;
	p->hurt = P_Hurt;

	p->name = PIG;
	p->type = FAST;
	p->d = LEFT;

	p->step = P_Move;
	p->multi = P_Multi;

	p->behit = FALSE;
}

// 动画加载
void P_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= P_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\P\\L\\%d.bmp", i);
		Lpigbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 128, 127, LR_LOADFROMFILE);
	}
	for (i = 0; i <= P_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\P\\R\\%d.bmp", i);
		Rpigbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 128, 128, LR_LOADFROMFILE);
	}
}

// 动画绘制
void P_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Pig *p = ListGetAt(Army, i);

	if (*num > P_Pic)
		*num = 0;

	if (p->d == LEFT) {
		SelectObject(hdcmem, Lpigbmp[(*num)]);
		TransparentBlt(hdc, p->x, p->y, P_Width, P_Height, hdcmem, 0, 0, 128, 127, COLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Rpigbmp[(*num)]);
		TransparentBlt(hdc, p->x, p->y, P_Width, P_Height, hdcmem, 0, 0, 128, 128, COLOR_Mark);
	}

	(*num)++;
}