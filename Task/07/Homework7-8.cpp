#include<stdio.h>
int main()
{
	int a[10], b[10], i, j, k, flag;
	i = j = 0;
	do
	{
		scanf("%d", &a[i]);
		i++;
	} while (a[i - 1] > 0);
	do
	{
		scanf("%d", &b[j]);
		j++;
	} while (b[j - 1] > 0);
	if (i != j)
		printf("n");
	else
	{
		k = i - 1;
		for (i = 0; i < k; i++)
		{
			flag = 0;
			for (j = 0; j < k; j++)
			{
				if (a[i] == b[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				break;
		}
		if (flag)
			printf("y");
		else
			printf("n");
	}
	return 0;
}