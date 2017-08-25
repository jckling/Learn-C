#include <stdio.h>
void sort_three(int*x, int*y, int*z)
{
	int t;
	if (*x>*y) { t = *x; *x = *y; *y = t; }
	if (*x>*z) { t = *x; *x = *z; *z = t; }
	if (*y>*z) { t = *y; *y = *z; *z = t; }
}

int main()
{
	int a, b, c;
	scanf("%d,%d,%d", &a, &b, &c);
	printf("origin:%d,%d,%d\n", a, b, c);
	sort_three(&a, &b, &c);
	printf("sort:%d,%d,%d\n", a, b, c);
}

