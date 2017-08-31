#include<stdio.h>
#include<math.h>
#include <stdlib.h>

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
	int i, flag = 1;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
void Pri(int x)
{
	int *shu = NULL;
	shu = (int*)malloc(x * sizeof(int));
	int i, j;
	j = 0;
	i = 2;
	while(j < x)
	{
		if (Prime(i))
		{
			printf("%8lu", i);
			i++;
			j++;
			if (j % 5 == 0)
				printf("\n");
		}
		else
			i++;
	}
	free(shu);
}




