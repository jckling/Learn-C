#include <stdio.h>
struct student
{
	char name[10];
	int no;
	float score[2];
};
void sort(struct student *pst, int n);
int main()
{
	struct student stu[45];
	int i, n;
	scanf("%d", &n); getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(stu[i].name);
		scanf("%d", &stu[i].no); getchar();
		scanf("%f", &stu[i].score[0]); getchar();
		scanf("%f", &stu[i].score[1]); getchar();
	}
	sort(stu, n);
	printf("\nName\t\tNo\tScore1\tScore2\n");
	for (i = 0; i < n; i++)
		printf("%s\t\t%d\t%5.1f\t%5.1f\n", stu[i].name, stu[i].no, stu[i].score[0], stu[i].score[1]);
}
void sort(struct student *pst, int n)
{
	int i, j = 0;
	float max = pst[0].score[0];
	struct student p;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (pst[j].score[0] < pst[j + 1].score[0])
			{
				p = pst[j + 1];
				pst[j + 1] = pst[j];
				pst[j] = p;
			}
		}
	}
}