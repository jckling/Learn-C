#include "boss.h"

// 大白鸡初始化
void B_Create(AllType *b) {

	b->x = Width;
	b->y = rand() % (Height - Border - B_Height) + Border;

	b->height = B_Height;
	b->width = B_Width;
	b->sub = B_Sub;

	b->name = BOSS;
	b->type = NORMAL;
	b->d = LEFT;

	b->HP = B_Life;
	b->hurt = B_Hurt;

	b->step = B_Move;
	b->multi = B_Multi;

	b->behit = FALSE;
}

// 动画加载
void B_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= B_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\B\\L\\%d.bmp", i);
		Lbossbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 343, 331, LR_LOADFROMFILE);
	}

	for (i = 0; i <= B_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\B\\R\\%d.bmp", i);
		Rbossbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 342, 330, LR_LOADFROMFILE);
	}
}

// 动画绘制
void BOSS_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Boss *b = ListGetAt(Army, i);

	if (*num > B_Pic)
		*num = 0;

	if (b->d == LEFT) {
		SelectObject(hdcmem, Lbossbmp[(*num)]);
		TransparentBlt(hdc, b->x, b->y, B_Width, B_Height, hdcmem, 0, 0, 343, 331, BOSSCOLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Rbossbmp[(*num)]);
		TransparentBlt(hdc, b->x, b->y, B_Width, B_Height, hdcmem, 0, 0, 342, 330, BOSSCOLOR_Mark);
	}

	(*num)++;
}