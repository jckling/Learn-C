#include<stdio.h>
int Count(char str[]);
int main()
{
	char str[1024];
	gets_s(str);
	printf("%d", Count(str));
	return 0;
}
int Count(char str[])
{
	int sum, flag;
	int i;
	sum = flag = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			sum++;
		}
	}
	return sum;
}