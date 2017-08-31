#include<stdio.h>

typedef struct CLOCK
{
	int h,m,s;
};

void update(CLOCK  *t);
void display(CLOCK  *t);
void Delay(void);

int main()
{
	int i;
	CLOCK time;
	time.h = time.m = time.s = 0;
	for (i = 0; i < 10000000; i++)
	{
		update(&time);
		display(&time);
		Delay();
	}
	return 0;
}
void update(CLOCK  *t)
{
	(*t).s++;
	if ((*t).s == 60)
	{
		(*t).s = 0;
		(*t).m++;
	}
	if ((*t).m == 60)
	{
		(*t).m = 0;
		(*t).h++;
	}
}
void Delay(void)
{	
	long t;
	for (t = 0; t < 500000000; t++)
	{              /*循环体为空语句的循环，起延时作用*/
	}
}
void display(CLOCK  *t)
{
	printf("%02d:%02d:%02d\r", (*t).h, (*t).m, (*t).s);
}

