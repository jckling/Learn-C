#include <stdio.h>
void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos);
int main()
{
	int a, b, c, d;
	int n=10, num[10], *pMaxPos=&a, *pMinPos=&b, *pMax=&c, *pMin=&d;
	int i;
	for(i=0;i<n;i++)
	scanf("%d", &num[i]);	
	FindMaxMin(num, n, pMax, pMaxPos, pMin, pMinPos);
	printf("Max = %d , Position = %d, Min = %d, Position = %d\n", *pMax, *pMaxPos, *pMin, *pMinPos);
	return 0;
}

void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos)
{
	int i;
	*pMax = *pMin = num[0];
	*pMaxPos = *pMinPos = num[0];
	for (i = 1; i < n; i++)
	{
		if (num[i] > *pMax)
		{
			*pMax=num[i];
			*pMaxPos = i;
		}
		if (num[i] < *pMin)
		{
			*pMin = num[i];
			*pMinPos = i;
		}
	}
}