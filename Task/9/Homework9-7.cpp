#include<stdio.h>
int word(char c);
int find(char *p);
int main()
{
	char str[80];
	int i;
	gets_s(str);
	printf("word=");
	for (i = find(str); word(str[i]); i++)
		printf("%c", str[i]);
}
int word(char c)
{
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return 1;
	return 0;
}
int find(char *p)
{
	int i, k, count, max;
	int flag, position;
	i = k = flag = count = max = 0;
	do
	{
		if (word(p[i]))
		{
			count++;
			if (flag == 0)
			{
				flag = 1;
				k = i;
			}
		}
		else
		{
			if (count >= max)
			{
				max = count;
				position = k;
			}
			flag = 0;
			count = 0;
		}
		i++;
	} while (p[i - 1] != '\0');
	return position;
}