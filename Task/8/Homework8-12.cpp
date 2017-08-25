#include<stdio.h>
#include<string.h>
#include<cctype>
#include<ctype.h>
int main()
{
	char a[2][100], b[100], c[100];
	int i, j, n,m, flag;
	flag = n = m = j = 0;
	gets_s(a[0]);
	gets_s(a[1]);

	for (i = 0; a[0][i] != '\0'; i++)
	{
		if (isalpha(a[0][i]))
		{
			b[n] = tolower(a[0][i]);
			n++;
		}
	}
	b[n] = '\0';

	for (i = 0; a[1][i] != '\0'; i++)
	{
		if (isalpha(a[1][i]))
		{
			c[m] = tolower(a[1][i]);
			m++;
		}
	}
	c[m] = '\0';

	if (m == n)
	{
		for (i = 0; i < n; i++)
		{
			flag = 0;
			for (j = 0; j < n; j++)
			{
				if (b[i] == c[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				break;
		}
	}
	if (flag == 1)
		printf("y");
	else
		printf("n");
	return 0;
}