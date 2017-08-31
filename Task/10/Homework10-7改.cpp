#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void p(int i);
int s(int j);

int main()
{
	int i;
	scanf("%d", &i);
	if (i < 4)
		p(4);
	else
		p(i);
}

void p(int i)
{
	int *p, n, j;
	p = (int *)malloc(sizeof(int) * i);
	for (j = 2, n = 0; n < i; j++)
	{
		if (s(j))
		{
			p[n] = j;
			n++;
		}
	}
	for (j = 0; j < i; j++)
	{
		printf("%8lu", p[j]);
		if ((j + 1) % 5 == 0)
			printf("\n");
	}
}

int s(int j)
{
	int i;
	if (j == 2)
		return 1;
	for (i = 2; i <= sqrt(j); i++)
	{
		if (j % i == 0)
			return 0;
	}
	return 1;
}