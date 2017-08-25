#include<stdio.h>
#include<string.h>
void Compare(char a[][80]);
int main()
{
	char str[6][80];
	int i;
	for (i = 0; i < 6; i++)
		scanf("%s", str[i]);
	Compare(str);
	return 0;
}
void Compare(char a[][80])
{
	int i, j;
	char b[80] = { 0 };
	for (i = 0; i < 6 - 1; i++)
	{
		for (j = 0; j < 6 - 1 - i; j++)
		{
			if (strcmp(a[j], a[j + 1]) > 0)
			{
				strcpy(b, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], b);
			}
		}
	}
	for (i = 0; i < 6; i++)
		printf("%s\n", a[i]);
}