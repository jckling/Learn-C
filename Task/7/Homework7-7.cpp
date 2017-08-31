#include<stdio.h>
int main()
{
	int a[20];
	int i, k;
	int flag;

	for(i = 0; i < 20; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < 20; i++)
	{
		flag = 1;
		for (k = i - 1; k >= 0; k--)
		{
			if (a[k] == a[i])
				flag = 0;
		}
		if(flag)
		printf("%d ", a[i]);
	}
	return 0;
}
