#include<stdio.h>
int MaxCommonFactor(int, int);
int main()
{
	int a, b;
	int x;
	scanf("%d,%d", &a, &b);
	x=a*b/MaxCommonFactor(a, b);
	printf("%d", x);
	return 0;
}
int MaxCommonFactor(int x, int y)
{
	int r;
	int min, max;
	if (x > y)
	{
		max = x;
		min = y;
	}
	else
	{
		max = y;
		min = x;
	}

	do
	{
		r = max % min;
		{
			if (r > min)
			{
				max = r;
				min = min;
			}
			else
			{
				max = min;
				if(r!=0)
				min = r;
			}
		}
	} while (r != 0);

	return min;
}