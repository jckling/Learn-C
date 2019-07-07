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
	int count = 0, n1, n2, i, j;
	n1 = strlen(s1);
	n2 = strlen(s2);
	char *c1 = s1, *c2 = s2, *t1 = s1;
	for (i = 0; i < n1; i++)
	{
		if (*c1 == *c2) 
		{
			for (j = 0; *c1++ == *c2++; j++);
			if (j == n2) count++;
		}
		c2 = s2;
		c1 = ++t1;
	}
	return count;
}