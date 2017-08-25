#include<stdio.h>
int f(int i);
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d", f(i));
}
int f(int i)
{
	if (i == 1 || i == 2 || i == 3)
		return 1;
	else
		return f(i - 1) + f(i - 2) + f(i - 3);
}