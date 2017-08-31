#include<stdio.h>
#include<stdlib.h>

int main()
{
	double *p, sum = 0;
	int q = 0, in = 6;
	int i;
	char c = 'y';
	p = (double *)malloc(sizeof(double) * 6);
	do
	{
		if (q == 0)
		{
			for (q; q < 6; q++)
				scanf("%lf", &p[q]);
		}
		else
		{
			i = q;
			q += in;
			p = (double *)realloc(p, sizeof(double) * q);
			for (; i < q; i++)
				scanf("%lf", &p[i]);
		}
		getchar();
		scanf("%c", &c);
	} while (c == 'y');
	for (i = 0; i < q; i++)
	{
		sum += p[i];
		printf("%10.1lf", p[i]);
		if ((i + 1) % 6 == 0)
		{
			printf("%10.1lf", sum / 6);
			printf("\n");
			sum = 0;
		}
	}
}