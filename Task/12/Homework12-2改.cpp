#include<stdio.h>

void m(struct student *student, int n);
void b(struct student *student, int n);

struct student
{
	char name[20];
	int num;
	double score[2];
};

int main()
{
	struct student stu[45];
	int i, n;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(stu[i].name);
		scanf("%d", &stu[i].num);
		getchar();
		scanf("%lf",&stu[i].score[0]);
		getchar();
		scanf("%lf", &stu[i].score[1]);
		getchar();
	}
	m(stu, n);
	b(stu, n);
	return 0;
}
void m(struct student *student, int n)
{
	int i;
	int max = student[0].score[0], k = 0, l = 0;
	for (i = 1; i < n; i++)
	{
		if (student[i].score[0] > max)
		{
			max = student[i].score[0];
			k = i;
		}
		if (student[i].score[1] > max)
		{
			max = student[i].score[1];
			k = i;
			l = 1;
		}
	}
	printf("\nName\t\tSex\tAge\tScore\n");
	printf("MaxSore=%5.1f,Name is %s,No=%ld,Score.No=%d\n", student[k].score[l], student[k].name, student[k].num, l + 1);
}
void b(struct student *student, int n)
{
	double sum1, sum2;
	int i, flag = 1;
	for (sum1 = sum2 = i = 0; i < n; i++)
	{
		sum1 += student[i].score[0];
		sum2 += student[i].score[1];
	}
	sum1 /= n;
	sum2 /= n;
	printf("Below average:\n");
	for (i = 0; i < n; i++)
	{
		if (student[i].score[0] < sum1 && student[i].score[1] < sum2)
		{
			printf("%s\t\t%ld\n", student[i].name, student[i].num);
			flag = 0;
		}
	}
	if (flag)
		printf("Not Found");
}