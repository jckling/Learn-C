#include <stdio.h>
struct student
{
	char name[10];
	int no;
	float score[2];
};
void maxscore(struct student *pst, int n);
void average(struct student *pst, int n);
int main()
{
	struct student student[45];
	int n, i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(student[i].name);
		scanf("%d", &student[i].no);
		getchar();
		scanf("%f", &student[i].score[0]);
		getchar();
		scanf("%f", &student[i].score[1]);
		getchar();
	}
	maxscore(student, n);
	average(student, n);
	return 0;
}

void maxscore(struct student *pst, int n)
{
	int i, max, flag=0;
	max = 0;
	for (i = 1; i < n; i++)
	{
		if (pst[max].score[0] < pst[i].score[0])
			max = i;
	}
	for (i = 0; i < n; i++)
	{
		if (flag)
		{
			if (pst[max].score[1] < pst[i].score[1])
				max = i;
		}
		else
		{
			if (pst[max].score[0] < pst[i].score[1])
			{
				max = i;
				flag = 1;
			}
		}
	}
	if (flag)
		printf("MaxSore=%5.1f,Name is %s,No=%ld,Score.No=%d\n", pst[max].score[1], pst[max].name, pst[max].no, 2);
	else
		printf("MaxSore=%5.1f,Name is %s,No=%ld,Score.No=%d\n", pst[max].score[0], pst[max].name, pst[max].no, 1);
}

void average(struct student *pst, int n)
{
	double avg1,avg2;
	int i, flag;
	avg1 = avg2 = 0;
	for (i = 0; i < n; i++)
	{
		avg1 += pst[i].score[0];
		avg2 += pst[i].score[1];
	}
	avg1 = avg1 / (n*1.0);
	avg2 = avg2 / (n*1.0);
	for (i = 0; i < n; i++)
	{
		flag = 0;
		if ((pst[i].score[0] < avg1)&&(pst[i].score[1] < avg2))
		{
			flag = 1;
			break;
		}
	}
	printf("Below average:\n");
	if (flag)
	{
		for (i = 0; i < n; i++)
		{
			if ((pst[i].score[0] < avg1)&&(pst[i].score[1] < avg2))
				printf("%s\t\t%ld\n", pst[i].name, pst[i].no);
		}
	}
	else
		printf("Not Found");
}