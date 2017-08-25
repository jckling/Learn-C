#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char a[3][80], b[80], *p;
	int i, j, count = 0;

	for (i = 0; i < 3; i++)
		gets_s(a[i]);
	gets_s(b);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
			a[i][j] = tolower(a[i][j]);
	}
	for (i = 0; b[i] != '\0'; i++)
		b[i] = tolower(b[i]);

	for (i = 0; i < 3; i++)
	{
		p = a[i];
		while (p = strstr(p, b))
		{
			p++;
			count++;
		}
	}
	printf("%d", count);
}