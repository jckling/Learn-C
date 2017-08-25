#include<stdio.h>
int main()
{
	int n;
	char *p[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	scanf("%d", &n);
	if (n < 1 || n>12)
		printf("Illegal month");
	else
		printf("%s", p[n-1]);
	return 0;
}