#include <string.h>
#include <stdio.h>

int CountSubstr(char *s1, char *s2);

int main()
{
	char s1[100], s2[100];
	scanf("%s", s1);  
	scanf("%s", s2);
	printf("%d", CountSubstr(s1, s2));
}

int CountSubstr(char *s1, char *s2)
{
	int sum = 0, i, j;
	int length = strlen(s2), L = strlen(s1);
	for (i = 0; i < L - length + 1; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (s1[j + i] != s2[j])
				break;
		}
		if (j == length)
			sum++;
	}
	return sum;
}