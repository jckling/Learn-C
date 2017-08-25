#include<stdio.h>
#include<math.h>
int Prime(int);
int main()
{
	int a,b,c;
	do
	{
		scanf("%d", &a);
	} while (a < 6 || a % 2 != 0);
	for (b = 3; b <= a / 2; b+=2)
	{
		c = a - b;
		if (b < c)
		{
			if (Prime(b) == 1 && Prime(c) == 1)
				printf("%d=%d+%d\n", a, b, c);
		}
	}
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