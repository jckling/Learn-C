#include<stdio.h>
#include<string.h>
int main()
{
	char a[4][100], *p;
	int i, counter = 0;
	for (i = 0; i < 4; i++)
		gets_s(a[i]);
	for (i = 0; i < 4; i++)
	{
		if(strtok(a[i], " "));
		{
			counter++;
			while (strtok(NULL, " "))
				counter++;
		}
	}
	printf("%d", counter);
	return 0;
}