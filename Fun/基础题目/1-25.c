#include <stdio.h>
#include <math.h>

int JudgeTriangle(int a, int b, int c);

int main() {
	int a, b, c;
	int judge;

	printf("请输入三边的边长（正整数）：");
	scanf("%d%d%d", &a, &b, &c);

	judge = JudgeTriangle(a, b, c);
	switch (judge) {
	case -1:
		printf("不能构成三角形！\n");
		break;
	case 0:
		printf("一般三角形\n");
		break;
	case 1:
		printf("直角三角形\n");
		break;
	case 2:
		printf("等腰三角形\n");
		break;
	case 3:
		printf("等边三角形\n");
		break;
	}

	return 0;
}

int JudgeTriangle(int a, int b, int c){
	int judge;

	if ((fabs(a - b) < c) && (fabs(a + b) > c)) {
		if ((a*a + b*b == c*c) || (b*b + c*c == a*a) || (a*a + c*c == b*b)) {
			judge = 1;
		}
		else if (a != b && b != c && a != c) {
			judge = 0;
		}
		else if (a == b || b == c || a == c) {
			if (a == b && b == c && a == c) {
				judge = 3;
			}
			else {
				judge = 2;
			}
		}
	}
	else {
		judge = -1;
	}

	return judge;
}