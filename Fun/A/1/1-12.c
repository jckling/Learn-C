#include <stdio.h>

int main() {
	char myarray[8];
	int i;

	printf("请输入数组的初始值：");
	for (i = 0; i < 8; i++) {
		scanf("%c", &myarray[i]);
	}

	printf("您输入的数组元素为：");
	for (i = 0; i < 8; i++) {
		printf("%3c", myarray[i]);
	}
	printf("\n");

	int num = sizeof(myarray) / sizeof(char);
	printf("数组元素个数为：%d\n", num);

	for (i = 0; i < num / 2; i++) {
		char temp;
		temp = myarray[i];
		myarray[i] = myarray[num - i - 1];
		myarray[num - i - 1] = temp;
	}

	printf("数组倒置后的数组元素为：");
	for (i = 0; i < 8; i++) {
		printf("%3c", myarray[i]);
	}
	printf("\n");

	return 0;
}