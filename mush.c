#include "mush.h"

// 蘑菇初始化
void MR_Create(AllType *mr) {

	mr->x = Width;
	mr->y = rand() % (Height - Border - MR_Height) + Border;

	mr->height = MR_Height;
	mr->width = MR_Width;
	mr->sub = MR_Sub;

	mr->type = NORMAL;
	mr->name = MUSH;
	mr->d = LEFT;
	if (rand() % 10 < 5)
		mr->type = FAST;
	else if (rand() % 10 < 2) {
		mr->type = FALL;
		mr->y = Border;
		mr->d = DOWN;
		mr->x = rand() % (Width / 4) + 100;
	}	

	mr->HP = MR_Life;
	mr->hurt = MR_Hurt;
	
	mr->step = MR_Move;
	mr->multi = MR_Multi;
	
	mr->behit = FALSE;	
}

// 动画加载
void MR_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= MR_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\MR\\%d.bmp", i);
		mushbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 149, 228, LR_LOADFROMFILE);
	}
}

// 动画绘制
void MR_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Mush *mr = ListGetAt(Army, i);

	if (*num > MR_Pic)
		*num = 0;

	SelectObject(hdcmem, mushbmp[(*num)]);
	TransparentBlt(hdc, mr->x, mr->y, MR_Width, MR_Height, hdcmem, 0, 0, 149, 228, COLOR_Mark);
	
	(*num)++;
}
