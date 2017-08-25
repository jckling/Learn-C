#include<stdio.h>//aabb，是一个整数的平方————>7744
#include<math.h>
int main()
{
	int a, m, x;
	double n;
	for (a = 1; a <= 9; a++)
	{
		for (m = 0; m <= 9; m++)
		{
			x = 1100 * a + 11 * m;
			n = sqrt(x);
			if (n == int(n))
				printf("%d\n", x);
		}
	}
	return 0;
}