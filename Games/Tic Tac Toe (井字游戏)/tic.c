#include "tic.h"

// 井字棋盘
char map[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// 判断是否有一方获胜
BOOL IfWin() {
	BOOL flag;
	BOOL tie;
	int i, j;

	flag = 0; // 获胜标志
	tie = 1;  // 是否下完

	// 判断获胜（麻烦型）
	if (map[0][0] == map[0][1] && map[0][1] == map[0][2])
		flag = 1;
	if (map[1][0] == map[1][1] && map[1][1] == map[1][2])
		flag = 1;
	if (map[2][0] == map[2][1] && map[2][1] == map[2][2])
		flag = 1;
	if (map[0][0] == map[1][0] && map[1][0] == map[2][0])
		flag = 1;
	if (map[0][1] == map[1][1] && map[1][1] == map[2][1])
		flag = 1;
	if (map[0][2] == map[1][2] && map[1][2] == map[2][2])
		flag = 1;
	if (map[0][0] == map[1][1] && map[1][1] == map[2][2])
		flag = 1;
	if (map[0][2] == map[1][1] && map[1][1] == map[2][0])
		flag = 1;

	// 判断是否下完
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (map[i][j] != 'o' && map[i][j] != 'x')
				tie = 0;
		}
	}

	// 平局
	if (tie && !flag){
		MessageBox(NULL, "A draw!", "Ohh", MB_OK);
		ExitProcess(0);
	}

	return flag;
}

// 玩家走一步
BOOL SetStep(int i){
	if (map[(i - 1) / 3][(i - 1) % 3] == 'x' || map[(i - 1) / 3][(i - 1) % 3] == 'o')
		return 0;
	else{
		map[(i - 1) / 3][(i - 1) % 3] = 'x';
		return 1;
	}
}

// 电脑走一步
void AI(HWND hwnd){
	int a, b;
	if (IfWin()){
		MessageBox(NULL, "You Win!", "Congratulations!", MB_OK);
		ExitProcess(0);
	}
	else {
		while (1){
			a = rand() % 3;
			b = rand() % 3;
			if (map[a][b] != 'o' && map[a][b] != 'x'){
				map[a][b] = 'o';
				if (IfWin()){
					GamePaint(hwnd);
					MessageBox(NULL, "You Lose!", "Ahhh", MB_OK);
					ExitProcess(0);
				}
				break;
			}
		}
		GamePaint(hwnd);
	}
}

// 响应键盘
BOOL OnKeyDown(DWORD vk){
	BOOL flag = 0;
	switch (vk) {
	case VK_NUMPAD1:
	case 49:
		flag = SetStep(1);
		break;
	case VK_NUMPAD2:
	case 50:
		flag = SetStep(2);
		break;
	case VK_NUMPAD3:
	case 51:
		flag = SetStep(3);
		break;
	case VK_NUMPAD4:
	case 52:
		flag = SetStep(4);
		break;
	case VK_NUMPAD5:
	case 53:
		flag = SetStep(5);
		break;
	case VK_NUMPAD6:
	case 54:
		flag = SetStep(6);
		break;
	case VK_NUMPAD7:
	case 55:
		flag = SetStep(7);
		break;
	case VK_NUMPAD8:
	case 56:
		flag = SetStep(8);
		break;
	case VK_NUMPAD9:
	case 57:
		flag = SetStep(9);
		break;
	default:
		break;
	}
	if (flag)
		return 1;
	return 0;
}