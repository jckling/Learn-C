#include<stdio.h>
#include<string.h>
int main()
{
	char str[1024];
	gets_s(str);
	int i, count, inword = 0;
	for (i = 0,count=0; str[i] != '\0'; i++)
	{
		if (inword == 0 && str[i] != ' ')
			count++;
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.')
			inword = 0;
		else
			inword = 1;
	}
	printf("%d", count);
}