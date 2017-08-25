#include <stdio.h>
#include<string.h>
struct student
{
	char name[10];
	int no;
	float score[2];
};
void sort(struct student *pst, int n);

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
	sort(student, n);
	return 0;
}

void sort(struct student *pst, int n)
{
	int i, j, temp;
	float temp1,temp2;
	char fake[10];
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (pst[j].score[0] < pst[j + 1].score[0]) // 这里是从大到小排序，如果是从小到大排序，只需将“<”换成“>”  
			{
				temp1 = pst[j].score[0];
				pst[j].score[0] = pst[j+1].score[0];
				pst[j+1].score[0] = temp1;
				temp2 = pst[j].score[1];
				pst[j].score[1] = pst[j + 1].score[1];
				pst[j + 1].score[1] = temp2;
				temp = pst[j].no;
				pst[j].no = pst[j + 1].no;
				pst[j + 1].no = temp;
				strcpy(fake, pst[j].name);
				strcpy(pst[j].name, pst[j + 1].name);
				strcpy(pst[j+1].name, fake);
			}
		}
	}

	printf("\nName\t\tNo\tScore1\tScore2\n");
	for (i = 0; i <n; i++)
		printf("%s\t\t%d\t%5.1f\t%5.1f\n", pst[i].name, pst[i].no, pst[i].score[0], pst[i].score[1]);

}