#include<stdio.h>

int main()
{
	int x, sum, de;
	int i;
	scanf("%d", &x);
	sum = de = x;
	do
	{
		sum += de / 5;
		de = de % 5 + de / 5;
	} while (de >= 5);

	printf("%d %d", sum, de);
}