#include<stdio.h>

struct time sub(struct time t1, struct time t2);

struct time
{
	int s;
	int m;
	int h;
};

int main()
{
	struct time t1, t2;
	struct time result;
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	result = sub(t1, t2);
	printf("Time between %.2d:%.2d:%.2d and %.2d:%.2d:%.2d is %.2d:%.2d:%.2d\n", t1.h, t1.m, t1.s, t2.h, t2.m, t2.s, result.h, result.m, result.s);
}

struct time sub(struct time t1, struct time t2)
{
	struct time time;
	time.s = t2.s - t1.s;
	if (time.s < 0)
	{
		time.s += 60;
		t2.m--;
	}
	time.m = t2.m - t1.m;
	if (time.m < 0)
	{
		time.m += 60;
		t2.h--;
	}
	time.h = t2.h - t1.h;
	if (time.h < 0)
		time.h += 24;
	return time;
}