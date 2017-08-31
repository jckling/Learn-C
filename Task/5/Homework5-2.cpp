#include<stdio.h>
void multiple(int, int);
int main()
{
	int a, b, i;
	for (i = 1; i <= 3; i++)
	{
		scanf("%d%d", &a, &b);
		multiple(a, b);
	}
return 0;
}

void multiple(int x, int y)
{
	if(y % x == 0)
		printf("%d is a multiple of %d\n", y, x);
	else
	    printf("%d is not a multiple of %d\n", y, x);
}