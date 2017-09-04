#include <stdio.h>

int main() {
	int a, b, c;  // 代表三位新郎，1、2、3代表三位新娘

	for (a = 1; a <= 3; a++) {
		for (b = 1; b <= 3; b++) {
			for (c = 1; c <= 3; c++) {
				if (a != 1 && c != 3 && c != 1 && a != b && b != c && a != c) {
					printf("%c将嫁给A\n", 'X' + a - 1);
					printf("%c将嫁给B\n", 'X' + b - 1);
					printf("%c将嫁给C\n", 'X' + c - 1);
				}
			}
		}
	}

	return 0;
}