#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Prime(int x);
void Pri(int x);
int main()
{
	int a;
	scanf("%d", &a);
	if (a <= 4)
		Pri(4);
	else
		Pri(a);

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
void Pri(int x)
{
	int i, j;
	j = 0;
	for (i = 2; i <= x; i++)
	{
		if (Prime(i))
		{
			printf("%8lu", i);
			j++;
			if (j % 5 == 0)
				printf("\n");
		}
	}
}




