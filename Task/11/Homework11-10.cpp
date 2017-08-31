#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char delimiters[] = " \n\".,;:!?)(";  //散文的分隔符
	char buf[100];  //输入缓冲数组，每次将一行文本输入此变量中
	int i, j, k, flag, m, n, sc;
	char *p = NULL;
	int *count = (int*)malloc(1000 * sizeof(int));;
	char *temp = NULL;
	char **pStr = (char**)malloc(1000 * sizeof(char*));;

	k = j = sc = 0;

	do
	{
		gets_s(buf);
		sc++;
		if ((buf[0] == '\n' || buf[0] == '\0') && sc == 1)
		{
			printf("No words found. Ending program.\n");
			break;
		}
		if (buf[0] == '\n' || buf[0] == '\0')
			break;
		else
		{
			k += strlen(buf);
			temp = (char*)realloc(p, (k + 1) * sizeof(char));
			p = temp;
			temp = NULL;
			j = 0;
			for (i = k - strlen(buf); buf[j] != '\0'; i++)
			{
				p[i] = buf[j];
				j++;
			}
			p[i] = '\0';
			memset(buf, '\0', 100);
		}
	} while (1);

	if (sc != 1)
	{
		for (k = 0; k < i + 1; k++)
		{
			if (p[k] >= 'A' && p[k] <= 'Z')
				p[k] = p[k] - 'A' + 'a';
		}
		pStr[0] = strtok(p, delimiters);
		count[0] = 1;
		i = 1;
		while (pStr[i] = strtok(NULL, delimiters))
		{
			flag = 1;
			for (k = 0; k < i; k++)
			{
				if (strcmp(pStr[k], pStr[i]) == 0)
				{
					count[k]++;
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				count[i] = 1;
				i++;
			}
		}

		for (k = 0; k < i; k++)
		{
			printf(" %-13s %3d", pStr[k], count[k]);
			if ((k + 1) % 4 == 0)
				printf("\n");
		}
	}
	return 0;
}