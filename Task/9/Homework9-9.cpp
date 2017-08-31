#include <stdio.h>
#include<string.h>
int strcompare(char *p1, char *p2);
int main()
{
	char str1[80], str2[80];
	gets_s(str1);
	gets_s(str2);
	printf("%d", strcompare(str1, str2));
	return 0;
}
int strcompare(char *p1, char *p2)
{
	int k, i;
	k = strcmp(p1, p2);
	if (k == 0)
		return k;
	else if (k > 0)
	{
		for (i = 0; p1[i] != '\0'&&p2[i] != '\0'; i++)
		{
			if (p1[i] != p2[i])
			{
				k = p1[i] - p2[i];
				if (k < 0)
					k = -k;
				break;
			}
		}

	}
	else if (k < 0)
	{
		for (i = 0; p1[i] != '\0'&&p2[i] != '\0'; i++)
		{
			if (p1[i] != p2[i])
			{
				k = p1[i] - p2[i];
				if (k > 0)
					k = -k;
				break;
			}
		}
	}
	return k;
}