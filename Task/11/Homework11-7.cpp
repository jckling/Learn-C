#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[2][50];
	char c;
	int counter[26] = { 0 };
	int i, j;
	char *p;

	for(i=0;i<2;i++)
	gets(a[i]);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; a[i][j] != '\0'; j++)
		{
			if (a[i][j] >= 'A'&&a[i][j] <= 'Z')
				a[i][j] = a[i][j] - 'A' + 'a';
		}
	}//全转化为小写

	i = 0;
	for (c = 'a'; c <= 'z'; c++)
	{
		if (strchr(a[0], c) != 0)
		{
			p = strchr(a[0], c);
			counter[i]++;
		}
		while (strchr(p + 1, c) != 0)
		{
			p = strchr(p + 1, c);
			counter[i]++;
		}
		if (strchr(a[1], c) != 0)
		{
			p = strchr(a[1], c);
			counter[i]++;
		}
		while (strchr(p + 1, c) != 0)
		{
			p = strchr(p + 1, c);
			counter[i]++;
		}
		printf("[%c,%d times] ", c, counter[i]);
		i++;
		p = a[0];
	}
	return 0;
}