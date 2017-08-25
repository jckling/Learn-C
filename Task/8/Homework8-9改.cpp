#include<stdio.h>
#include<string.h>
int main()
{
	char a[6][80], b[80];
	int  i, j;
	for (i = 0; i < 6; i++)
		scanf("%s", a[i]);
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[j][0]>a[j+1][0])
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