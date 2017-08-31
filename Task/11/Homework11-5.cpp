#include<stdio.h>
#include<string.h>

int main()
{
	char a[3][200];
	char x[20];
	char *searchPtr;
	int counter = 0, i, j;

	for (i = 0; i < 3; i++)
		gets_s(a[i]);
	scanf("%s", &x);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
		{
			if (a[i][j] >= 'A' && a[i][j] <= 'Z')
				a[i][j] = a[i][j] - 'A' + 'a';
		}
	}//全部转化为小写
	for (i = 0; x[i] != '\0'; i++)
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] = x[i] - 'A' + 'a';
	}//同上
	for (i = 0; i < 3; i++)
	{
		if (strstr(a[i], x) != 0)
		{
			searchPtr = strstr(a[i], x);
			counter++;
		}
		while (strstr(searchPtr + 1, x) != 0)
		{
			searchPtr = strstr(searchPtr + 1, x);
			counter++;
		}
	}
	printf("%d", counter);
	return 0;
}