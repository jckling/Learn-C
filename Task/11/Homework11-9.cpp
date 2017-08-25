#include<stdio.h>
#include<string.h>
int main()
{
	char a[10][100] = { 0 }, b[1000] = { 0 };
	char *p[50];
	int i, j, k, l;
	i = j = k = l = 0;
	gets_s(a[i]);
	if (a[0][0] == '\0')
		printf("No words found.\n");
	else
	{
		i = 1;
		do
		{
			gets_s(a[i]);
			i++;
		} while (a[i - 1][0] != '\0'&&a[i][0] == '\0');
	}
	for (j = 0; j < i; j++)
	{
		for (k = 0; a[j][k] != '\0'; k++)
		{
			b[l] = a[j][k];
			l++;
		}
		if (a[j][k] == '\0'&&a[j][k - 1]>='a'&&a[j][k - 1]<='z')
		{
			b[l] =' ';
			l++;
		}
	}
	b[l] = '\0';
	if (a[0][0] != '\0')
	{
		p[0] = strtok(b, "\n \".,;:!?)(");
		i = 1;
		while (p[i] = strtok(NULL, "\n \".,;:!?)("))
			i++;
		for (j=0,k = 0; k < i; k++)
		{
			printf("%-18s", p[k]);
			j++;
			if (j % 5 == 0)
				printf("\n");
		}
		printf("\n%u words found.\n", i);
	}
	return 0;
}