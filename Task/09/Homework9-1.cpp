#include<stdio.h>

int sort_three(int *a, int *b, int *c);

int main()
{
  int a, b, c;
  scanf("%d,%d,%d", &a, &b, &c);
  printf("origin:%d,%d,%d\n", a, b, c);
  sort_three(&a, &b, &c);
  printf("sort:%d,%d,%d\n", a, b, c);
}
int sort_three(int *a, int *b, int *c)
{
	int p;
	if(*a > *b)
	{
		if (*b > *c)
		{
			p = *a;
			*a = *c;
			*c = p;
		}
	    else
	    {
			if (*a > *c)
			{
				p = *a;
				*a = *b;
				*b = *c;
				*c = p;
			}
			else
			{
				p = *a;
				*a = *b;
				*b = p;
			}
	     }
	}
	else
	{
		if (*a > *c)
		{
			p = *a;
			*a = *c;
			*c = *b;
			*b = p;
		}
		else
		{
			if (*b > *c)
			{
				p = *b;
				*b = *c;
				*c = p;
			}
		}
	}
	return *a, *b, *c;
}