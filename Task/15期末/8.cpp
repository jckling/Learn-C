#include<stdlib.h>
#include<stdio.h>
void P(int x, int y);
void find(int **a, int y);
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	P(x, y);
}
void P(int x, int y)
{
	int i, j, k;
	int **a;
	int **p;
	p = (int **)malloc(sizeof(int*)*x);
	a = (int **)malloc(sizeof(int*)*y);
	for (i = 0; i < x; i++)
		*(p + i) = (int*)malloc(sizeof(int)*y);
	for (i = 0; i < y; i++)
		*(a + i) = (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < 10; j++)
			a[i][j] = 0;
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			scanf("%d", &p[i][j]);
		}
	}
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (p[j][i] == k)
					a[i][k]++;
			}
		}
	}
	find(a, y);
	free(p);
}
void find(int **a, int y)
{
	int i, j, k, flag;
	for (i = 0; i < y; i++)
	{
		k = 0;
		flag = 0;
		for (j = 0; j < 10; j++)
		{
			if (a[i][j] > k)
			{
				k = a[i][j];
				flag = j;
			}
		}
		printf("%d ", flag);
	}
}