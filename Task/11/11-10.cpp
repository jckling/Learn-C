#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char delimiters[] = " \n\".,;:!?)(";  //散文的分隔符
	char buf[100];  //输入缓冲数组，每次将一行文本输入此变量中
	char *p = NULL, *q = NULL, *temp;
	int i = 0, j, k, flag, *c = NULL;
	while (1)
	{
		memset(buf, '\0', 100);
		gets_s(buf);
		if (buf[0] == '\0')
			break;
		i += strlen(buf);
		p = (char *)realloc(p, i * sizeof(char));
		for (j = 0; buf[j] != '\0'; j++)
			p[i - strlen(buf) + j] = buf[j];
		p[i - strlen(buf) + j] = '\0';
	}
	for (i = 0; p[i] != '\0'; i++)
		p[i] = tolower(p[i]);
	printf("%s", p);

	flag = i = 0;
	j = 1;
	temp = strtok(p, delimiters);
	i += strlen(temp);
	q = (char *)realloc(q, i * sizeof(char));
	q[0] = *temp;
	c = (int *)realloc(c, j * sizeof(int));
	c[0] = 1;
	while (temp = strtok(NULL, delimiters))
	{
		for (k = 0; k < j; k++)
		{
			if (*temp == q[k])
				c[k]++;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			i += strlen(temp);
			q = (char *)realloc(q, i * sizeof(char));
			j++;
			c = (int *)realloc(c, j * sizeof(int));
			c[j - 1] = 1;
		}
	}
	c[j] = 0;
	for (i = 0; c[i] != 0; i++)
	{
		printf(" %-13s %3d", q[i], c[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	return 0;
}