#include "boss1.h"

// 跳跳驴初始化
void B1_Create(AllType *b) {

	b->x = Width;
	b->y = rand() % (Height - Border - B1_Height) + Border;
	
	b->height = B1_Height;
	b->width = B1_Width;
	b->sub = B1_Sub;
	
	b->name = BOSS1;
	b->type = NORMAL;
	b->d = LEFT;
	
	b->HP = B1_Life;
	b->hurt = B1_Hurt;

	b->step = B1_Move;
	b->multi = B1_Multi;

	b->behit = FALSE;
}

// 动画加载
void B1_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= B1_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\B1\\L\\%d.bmp", i);
		Lboss1bmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 317, 341, LR_LOADFROMFILE);
	}

	for (i = 0; i <= B1_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\B1\\R\\%d.bmp", i);
		Rboss1bmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 317, 340, LR_LOADFROMFILE);
	}
}

// 动画绘制
void BOSS1_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Boss *b = ListGetAt(Army, i);

	if (*num > B1_Pic)
		*num = 0;

	if (b->d == LEFT) {
		SelectObject(hdcmem, Lboss1bmp[(*num)]);
		TransparentBlt(hdc, b->x, b->y, B1_Width, B1_Height, hdcmem, 0, 0, 317, 341, BOSS1COLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Rboss1bmp[(*num)]);
		TransparentBlt(hdc, b->x, b->y, B1_Width, B1_Height, hdcmem, 0, 0, 317, 340, BOSS1COLOR_Mark);
	}

	(*num)++;
}
