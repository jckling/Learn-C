#include<stdio.h>
int main()
{
	int i, j, k, flag;
	char c[80];
	scanf("%s", c);
	for (i = 0; c[i] != '\0'; i++);
	if (i % 2 == 0)
	{
		flag = 1;
		for (j = 0, k = i - 1; j < i / 2; j++, k--)
		{
			if (c[j] != c[k])
			{
				flag = 0;
				printf("no");
				break;
			}
		}
		if (flag)
			printf("yes");
	}
	else
	{
		flag = 1;
		for (j = 0, k = i - 1; j < (i - 1) / 2; j++, k--)
		{
			if (c[j] != c[k])
			{
				flag = 0;
				printf("no");
				break;
			}
		}
		if (flag)
			printf("yes");
	}
}