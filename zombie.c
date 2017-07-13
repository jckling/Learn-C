#include "zombie.h"

// 僵尸初始化
void Z_Create(AllType *z) {

	z->x = Width;
	z->y = rand() % (Height - Border - Z_Height) + Border;

	z->height = Z_Height;
	z->width = Z_Width;	
	z->sub = Z_Sub;

	z->name = ZOMBIE;
	z->type = NORMAL;
	z->d = LEFT;

	z->HP = Z_Life;
	z->hurt = Z_Hurt;
	
	z->step = Z_Move;
	z->multi = Z_Multi;

	z->behit = FALSE;
}

// 动画加载
void Z_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };
	for (i = 0; i <= Z_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\Z\\L\\%d.bmp", i);
		Lzombiebmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 133, 180, LR_LOADFROMFILE);
	}

	for (i = 0; i <= Z_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\Z\\R\\%d.bmp", i);
		Rzombiebmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 133, 180, LR_LOADFROMFILE);
	}
}

// 动画绘制
void Z_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Zombie *z = ListGetAt(Army, i);

	if (*num > Z_Pic)
		*num = 0;

	if (z->d == LEFT) {
		SelectObject(hdcmem, Lzombiebmp[(*num)]);
		TransparentBlt(hdc, z->x, z->y, Z_Width, Z_Height, hdcmem, 0, 0, 133, 180, COLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Rzombiebmp[(*num)]);
		TransparentBlt(hdc, z->x, z->y, Z_Width, Z_Height, hdcmem, 0, 0, 133, 180, COLOR_Mark);
	}
	
	(*num)++;
}