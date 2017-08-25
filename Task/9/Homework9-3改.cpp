#include <stdio.h>
int main()
{
	int*pmax, *pmin;
	int data[10], temp, i, n;
	// printf("enter n:");
	scanf("%d", &n);
	// printf("enter %d data:",n);
	for (i = 0; i<n; i++)
		scanf("%d", &data[i]);
	printf("orgin:");
	for (i = 0; i<n; i++)
		printf("%4d", data[i]);
	printf("\n");
	pmax = pmin = data;
	for (i = 1; i < n; i++)
	{
		if (*pmax < data[i])
			pmax = &data[i];
		if (*pmin > data[i])
			pmin = &data[i];
	}
	printf("max=%d\n min=%d\n", *pmax, *pmin);
	if (*pmax != data[0])
	{
		temp = data[0];
		data[0] = *pmax;
		*pmax = data[0];
	}
	if (*pmin != data[n-1])
	{
		temp = data[n-1];
		data[n-1] = *pmin;
		*pmin = temp;
	}






	printf("sorted:");
	for (i = 0; i<n; i++)
		printf("%4d", data[i]);
	printf("\n");

}