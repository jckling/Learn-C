#include <stdio.h>
#include <windows.h>

int main() {
	int i, j;

	SetConsoleOutputCP(437);  // ��ʾ����127��ASCII��

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				printf("%c", 219);
			}
			else {
				printf("  ");  //  �����ո�
			}
		}
		printf("\n");
	}

	return 0;
}