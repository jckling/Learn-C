#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char a[2][100], *p, b[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int i, j, k, c[26] = { 0 };
	for (i = 0; i < 2; i++)
		gets_s(a[i]);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
			a[i][j] = tolower(a[i][j]);
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
		{
			for (k = 0; k < 26; k++)
			{
				if (b[k] == a[i][j])
				{
					c[k]++;
					break;
				}
			}
		}
	}
	for (i = 0; i < 26; i++)
		printf("[%c,%d times] ", b[i], c[i]);
	return 0;
}