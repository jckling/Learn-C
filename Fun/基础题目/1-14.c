#include <stdio.h>

int main() {
	int myArray[8];
	int i, j, delete_num;

	printf("请输入8个整型元素到数组中：\n");
	for (i = 0; i < 8; i++) {
		scanf("%d", &myArray[i]);
	}

	printf("请输入要删除的元素：\n");
	scanf("%d", &delete_num);

	for (i = 0; i < 8; i++) {
		if (myArray[i] == delete_num) {
			if (i == 7) {
				myArray[i] = 0;
			}
			else {
				for (j = i; j < 8 - 1; j++) {
					myArray[j] = myArray[j + 1];
				}
				myArray[j] = 0;
			}
			break;
		}
	}

	if (i == 8) {
		printf("没有找到该元素\n");
	}

	printf("当前数组内元素有：\n");
	for (i = 0; i < 8 - 1; i++) {
		printf("%6d", myArray[i]);
	}
	printf("\n");

	return 0;
}