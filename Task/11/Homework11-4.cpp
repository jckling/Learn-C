#include<stdio.h>
#include<string.h>

void ING(char x[]);

int main()
{
	char a[5][20];
	int i, j;
	for (i = 0; i < 5; i++)
		gets_s(a[i]);
	for (i = 0; i < 5; i++)
	{
		if (strlen(a[i]) > 3)
		{
			for (j = 0; a[i][j] != '\0'; j++)
			{
				if (a[i][j] == 'i')
				{
					if (a[i][j + 1] == 'n')
					{
						if (a[i][j + 2] == 'g')
							printf("%s\n", a[i]);
					}
				}


			}
				
		}

	}
	return 0;
}
//strcmp(a[i], "ing")