#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c;
	double x, y, z;
	int flag = 1;

	scanf("%lf,%lf,%lf", &a, &b, &c);

	if ((a - b) < c && (a + b) > c)
	{
		if (fabs(a - b) < 1e-4 || fabs(b - c) < 1e-4 || fabs(a - c) < 1e-4)
		{
			x = fabs((a * a) - (b * b) - (c * c));
			y = fabs((b * b) - (a * a) - (c * c));
			z = fabs((c * c) - (a * a) - (b * b));
			if (x < 1e-4 || y < 1e-4 || z < 1e-4)
			{
				printf("等腰直角三角形");
				flag = 0;
			}
			else
			{
				printf("等腰三角形");
				flag = 0;
			}
		}
		else
		{
			if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
			{
				printf("直角三角形");
				flag = 0;
			}
		}
		if (flag == 1)
			printf("一般三角形");
	}
	else
		printf("不是三角形");

	return 0;

}