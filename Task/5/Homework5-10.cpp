#include<stdio.h>
#include<math.h>
int Prime(int);
int Turn(int);
int main()
{
	int i, j, counter=0;
	for (i = 100; i < 1000; i++)
	{
		j = Turn(i);
		if (Prime(i) && Prime(j))
		{
			if (i <= j)
			{
				printf("%d,%d\n", i, j);
				counter++;
			}
		}
	}
	printf("count=%d", counter);
	return 0;
}

int Prime(int x)
{	
		int i;
		int flag;
		double n;
		flag = 1;
		n = sqrt(x);
		for (i = 2; i <= n; i++)
		{
			if (x%i == 0)
			{
				flag = 0;
				break;
			}
		}
		return flag;	
}

int Turn(int x)
{
	int a, b, c;
	a = x / 100;
	b = (x - a * 100) / 10;
	c = x % 10;
	return c * 100 + b * 10 + a;
}