#include<stdio.h>
#include<string.h>
int main()
{
	char str[81];
	int i, j, n;
	gets_s(str);
	n = strlen(str);
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		if (str[i] != str[j])
			break;
	}
	if (i >= j)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}