#include<stdio.h>
void T(int);
int main()
{
	int j;
	for (j = 0; j <= 100; j++)
		T(j);
	return 0;
}
void T(int a)
{
	int i, k;
	i = 0;
	k = 0;
	while (k <= 13)
	{
		if (a == i)
			printf("%d is triangular.\n", a);
		k++;
		i += k;
	}
}