#include<stdio.h>
void MaxCommonFactor(int, int);
int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	MaxCommonFactor(a, b);

	return 0;
}
void MaxCommonFactor(int x, int y)
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
				if(r != 0)
				min = r;
			}
		}
	} while (r != 0);

		printf("%d", min);
}