#include <stdio.h>

void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos);

int main()
{
	int num[10], n, pMax, pMaxPos, pMin, pMinPos;
	for (n = 0; n < 10; n++)
		scanf("%d", &num[n]);
	FindMaxMin(num, n, &pMax, &pMaxPos, &pMin, &pMinPos);
}

void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos)
{
	int i;
	*pMinPos = *pMaxPos = 0;
	*pMax = *pMin = num[0];
	for (i = 0; i < n; i++)
	{
		if (num[i] > *pMax)
		{
			*pMax = num[i];
			*pMaxPos = i;
		}
		if (num[i] < *pMin)
		{
			*pMin = num[i];
			*pMinPos = i;
		}
	}
	printf("Max = %d , Position = %d, Min = %d, Position = %d\n", *pMax, *pMaxPos, *pMin, *pMinPos);
}