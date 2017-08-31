#include<stdio.h>
#include<string.h>

void printstring(char *p, int n, int m);

int main()
{
	int a, b;
	char str[80];
	gets_s(str);
	do
	{
		scanf("%d %d", &a, &b);
	} while (a <= 0 || b <= 0 || (a + b) > strlen(str));
	printstring(str, a, b);
	return 0;
}

void printstring(char *p, int n, int m)
{
	int i;
	for (i = n; i < n + m; i++)
		printf("%c", p[i]);
}