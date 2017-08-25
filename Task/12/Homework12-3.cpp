#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char c[10];
	int i, j;
	struct vote
	{
		char name[10];
		int sum;
	}vote[3] = { {"li",0},{"zhang",0},{"wang",0} };
	for (i = 0; i < 10; i++)
	{
		gets_s(c);
		for (j = 0; c[j] != '\0'; j++)
			c[j] = tolower(c[j]);
	}//转化为小写
		for (j = 0; j < 3; j++)
		{
			if (strcmp(vote[j].name,c) == 0)
				vote[j].sum++;
		}
	}
	for (i = 0; i < 3; i++)
		printf("%s:%d\n", vote[i].name, vote[i].sum);
	return 0;
}