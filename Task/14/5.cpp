#include<stdio.h>
#include<string.h>

void addSpace(char *p);

int main()
{
	char str[80];
	gets_s(str);
	addSpace(str);
	puts(str);
	return 0;
}

void addSpace(char *p)
{
	char a[80];
	int i, j;
	for (i = 0, j = 0; i < strlen(p); i++)
	{
		a[j] = p[i];
		a[j + 1] = ' ';
		j += 2;
	}
	a[j - 1] = '\0';
	p = strcpy(p, a);
}