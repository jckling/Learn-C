#include <stdio.h>
void  method(int m, int n, int *a);
int main()
{
	int a[10];
	int i, m, n;

	for (i = 0; i<10; i++)
		scanf("%d", &a[i]);
	scanf("%d %d", &m, &n);

	method(m, n, a);

	for (i = 0; i<10; i++)
		printf("%d ", a[i]);
}
void  method(int m, int n, int *a)
{
	int temp;
	int i, j;
	i = m - 1;
	j = m + n - 2;
	for (; i != j; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}