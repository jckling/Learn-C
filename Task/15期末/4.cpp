#include<stdio.h>
#include<math.h>
int p(int x);
void q(int b[10], int x);
int main()
{
	int a[10], b[10], i, j, flag = 0, count = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0,j=0; i < 10; i++)
	{
		if (p(a[i])==0)
		{
			b[j] = a[i];
			j++;
			flag = 1;
			count++;
		}
	}
	if (flag)
		q(b,count);
	else
		printf("No");
	return 0;

}
int p(int x)
{
	int i, flag=1;
	if (x == 2)
		return flag = 1;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void q(int b[10],int x)
{
	int i,j ,temp;
	for (i = 0; i<x; i++)
	{
		for (j = 0; j < x - i-1; j++)
		{
			if (b[j] > b[j+1])
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	for (i = 0; i<x; i++)
		printf("%d ", b[i]);

}