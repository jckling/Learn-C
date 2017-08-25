#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);

	if (a < b)
	{
		if (b < c)
		{
			a = a;
			b = b;
			c = c;
		}

		else
		{
			if (a < c)
			{
				d = b;
				b = c;
				c = d;
			}
			else
			{
				d = a;
				a = c;
				c = b;
				b = d;
			}
		}
	}
	else
	{
		if (c < b)
		{
			d = a;
			a = c;
			c = d;
		}
		else
		{
			if (a < c)
			{
				d = a;
				a = b;
				b = d;

			}
			else
			{
				d = a;
				a = b;
				b = c;
				c = d;
			}
		}
	}

	printf("small to big: %d %d %d",a,b,c);
	return 0;


}