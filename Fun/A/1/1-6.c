#include <stdio.h>

int main() {
	int year = 0;

	printf("��������ݣ�");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		printf("%d ������\n", year);
	}
	else {
		printf("%d ��������\n", year);
	}

	return 0;
}