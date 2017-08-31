#include<stdio.h>
#include<string.h>

int main()
{
	char a[8][1000], b[4096], *p;
	int i , j, count;
	i = j = count = 0;
	do
	{
		memset(a[i], '\0', 1000);
		gets_s(a[i]);
		if (a[i][0] == '\0')
			break;
		i++;
	} while (1);
	if (i == 0)
		printf("No words found.\n");
	else
	{
		for (; j < i; j++)
		{
			p = strtok(a[j], "\n \".,;:!?)(");
			printf("%-18s", p);
			count++;
			while (p = strtok(NULL, "\n \".,;:!?)("))
			{
				printf("%-18s", p);
				count++;
				if (count % 5 == 0)
					printf("\n");
			}
		}
		printf("\n%u words found.\n", count);
	}
}