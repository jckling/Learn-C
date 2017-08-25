#include<stdio.h>
int main()
{
	int a[20][20], i, j;
	int n, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 0; i < n; i++)
		sum += a[i][i];
	for (i = 0, j = n - 1; i < n; i++, j--)
		sum += a[i][j];
	if (n % 2 != 0)
		sum -= a[(n - 1) / 2][(n - 1) / 2];
	printf("%d", sum);
	return 0;
}