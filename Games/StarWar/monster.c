#include "monster.h"

// 野怪初始化
void M_Create(AllType *m) {

	m->x = Width;
	m->y = rand() % (Height - Border - M_Height) + Border;

	m->height = M_Height;
	m->width = M_Width;
	m->sub = M_Sub;

	m->name = MONSTER;
	m->type = NORMAL;
	if (rand() % 10 < 5)
		m->type = FAST;
	m->d = LEFT;

	m->step = M_Move;
	m->multi = M_Multi;
	
	m->HP = M_Life;
	m->hurt = M_Hurt;

	m->behit = FALSE;	
}

// 动画加载
void M_Load(HWND hwnd) {

	int i;
	TCHAR fileName[30] = { "" };

	for (i = 0; i <= M_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\M\\L\\%d.bmp", i);
		Lmonsterbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 199, 177, LR_LOADFROMFILE);
	}

	for (i = 0; i <= M_Pic; i++) {
		wsprintf(fileName, ".\\FIGHT\\M\\R\\%d.bmp", i);
		Rmonsterbmp[i] = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 198, 176, LR_LOADFROMFILE);
	}
}

// 动画绘制
void M_Paint(HDC hdc, HDC hdcmem, int i) {

	SetStretchBltMode(hdc, COLORONCOLOR);

	int *num = ListGetAt(Army_PicNum, i);
	Monster *m = ListGetAt(Army, i);

	if (*num > M_Pic)
		*num = 0;

	if (m->d == LEFT) {
		SelectObject(hdcmem, Lmonsterbmp[(*num)]);
		TransparentBlt(hdc, m->x, m->y, M_Width, M_Height, hdcmem, 0, 0, 199, 177, COLOR_Mark);
	}
	else {
		SelectObject(hdcmem, Rmonsterbmp[(*num)]);
		TransparentBlt(hdc, m->x, m->y, M_Width, M_Height, hdcmem, 0, 0, 198, 176, COLOR_Mark);
	}

	(*num)++;
}