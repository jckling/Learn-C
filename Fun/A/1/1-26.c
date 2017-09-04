#include <stdio.h>
#include <windows.h>

int main() {
	int i, j;

	SetConsoleOutputCP(437);  // 显示大于127的ASCII码

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				printf("%c", 219);
			}
			else {
				printf("  ");  //  两个空格
			}
		}
		printf("\n");
	}

	return 0;
}