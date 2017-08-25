#include<stdio.h>
int main()
{
	char Turn[10];
	char c;
	int i=0;
	do
	{
		scanf("%c", &c);
		if (c != '.')
		{
			Turn[i] = c;
			i++;
		}
	} while (c != '.'&&i!=10);

	for (i--; i >= 0; i--)
		printf("%c", Turn[i]);
	return 0;
}