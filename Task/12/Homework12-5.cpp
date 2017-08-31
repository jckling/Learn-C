#include<stdio.h>
#include<math.h>

void sub(struct shijian *pst);

struct shijian
{
	int h;
	int m;
	int s;
};

int main()
{
	struct shijian b[2];
	int i;
	for (i = 0; i < 2; i++)
		scanf("%d %d %d", &b[i].h, &b[i].m, &b[i].s);
	sub(b);
	return 0;
}

void sub(struct shijian *pst)
{
	struct shijian time;
	int a, b;
	a = b = 0;
	if (pst[1].s - pst[0].s < 0)
	{
		pst[1].m--;
		a = 1;
		time.s = 60 - abs(pst[1].s - pst[0].s);
	}
	else
		time.s = pst[1].s - pst[0].s;
	if (pst[1].m - pst[0].m < 0)
	{
		pst[1].h--;
		b = 1;
		time.m = 60 - abs(pst[1].m - pst[0].m);
	}
	else
		time.m = pst[1].m - pst[0].m;
	if (pst[1].h < 12 && pst[0].h < 12)
	{
		if (pst[1].h - pst[0].h < 0)
			time.h = 12 + pst[0].h - pst[1].h;
		else
			time.h = abs(pst[1].h - pst[0].h);
	}
	else
	{
		if (pst[1].h - pst[0].h < 0)
			time.h = 24 - abs(pst[1].h - pst[0].h);
		else
			time.h = abs(pst[1].h - pst[0].h);

	}
	if (a)
		pst[1].m++;
	if (b)
		pst[1].h++;
	printf("Time between %.2d:%.2d:%.2d and %.2d:%.2d:%.2d is %.2d:%.2d:%.2d\n", pst[0].h, pst[0].m, pst[0].s, pst[1].h, pst[1].m,pst[1].s, time.h, time.m, time.s);

}
//9 44 3 3 45 15_ 18,01,12
//22 50 59 7 30 0_ 8,39,01