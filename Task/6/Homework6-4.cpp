#include<stdio.h>
#include<math.h>
int M(int, int);
int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	printf("%d", M(a, b));
	return 0;
}
int M(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;
	else if (x > 0)
		return M(x - 1, y) + y;
	else if (y > 0)
		return M(x, y - 1) + x;
}