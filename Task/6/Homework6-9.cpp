#include<stdio.h>
void M(int, int);
int main()
{
	int a, b;
	scanf("%d/%d", &a, &b);
	M(a, b);
	return 0;

}
void M(int a, int b)
{
	int c;
	int x, y;
	if (b%a == 0)
		printf("1/%d", b / a);
	else
	{
		if (a == 1)
			printf("1/%d", b);
		else
		{
			c = b / a + 1;
			printf("1/%d+", c);
			x = a*c - b;
			y = c*b;
			if (x > 1)
			{
				if (y % x == 0)
				{
					y = (c*b) / (a*c - b);
					x = 1;
				}
				return M(x, y);
			}
			else
			{
				c = (c*b) / (a*c - b);
				printf("1/%d", c);
			}
		}
	}
}