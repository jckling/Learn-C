#include <stdio.h>
#include <math.h>

int main() {
	double y;
	int x, m;

	for (y = 1; y >= -1; y -= 0.1) {
		m = (int)(acos(y) * 10);  // 计算y对应弧度m，乘以10放大图形

		// 打印左侧*号
		for (x = 0; x < m; x++) {
			printf(" ");
		}
		printf("*");

		// 打印右侧*号
		for (; x < 62 - m; x++) {
			printf(" ");
		}
		printf("*\n");
	}

	return 0;
}