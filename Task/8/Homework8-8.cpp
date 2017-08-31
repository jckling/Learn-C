#include  <stdio.h>
#define STU 30
#define COURSE 3

void Input(long num[], int score[][COURSE], int n);
void GetSumAver(int score[][COURSE], int n, int sum[], float aver[]);
void Sort(long num[], int score[][COURSE], int n, int sum[], float aver[]);
void Print(long num[], int score[][COURSE], int n, int sum[], float aver[]);
int  Search(long num[], int n, long x);

int main()
{
	int n, score[STU][COURSE], sum[STU], pos;
	long num[STU], x;
	float aver[STU];

	scanf("%d", &n); /*输入参加考试的学生人数*/
	Input(num, score, n); /*输入学生成绩*/

	GetSumAver(score, n, sum, aver); /*计算总分和平均分*/
	printf("Before sort:\n");
	Print(num, score, n, sum, aver);

	Sort(num, score, n, sum, aver); /*排名次*/
	printf("After sort:\n");
	Print(num, score, n, sum, aver);
	return 0;
}

void Input(long num[], int score[][COURSE], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		for (j = 0; j < COURSE; j++)
			scanf("%d", &score[i][j]);
	}
}

void GetSumAver(int score[][COURSE], int n, int sum[], float aver[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		sum[i] = score[i][0] + score[i][1] + score[i][2];
		aver[i] = 1.0 * sum[i] / 3;
	}
}

void Sort(long num[], int score[][COURSE], int n, int sum[], float aver[])
{
	int i, j, k, temp;
	float tem;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (sum[j] < sum[j + 1])
			{
				for (k = 0; k < COURSE; k++)
				{
					temp = score[j][k];
					score[j][k] = score[j + 1][k];
					score[j + 1][k] = temp;
				}
				temp = sum[j];
				sum[j] = sum[j + 1];
				sum[j + 1] = temp;
				tem = aver[j];
				aver[j] = aver[j + 1];
				aver[j + 1] = tem;
			}
		}
	}
}

void Print(long num[], int score[][COURSE], int n, int sum[], float aver[])
{
	int i, j;

	printf("  NO \t   MT \t  EN \t PH \t SUM \t AVER\n");
	printf("----------------------------------------------------\n");

	for (i = 0; i < n; i++)
	{
		printf("%ld\t", num[i]); //输出学号
		for (j = 0; j < COURSE; j++)
			printf("%4d\t", score[i][j]); //输出成绩

		printf("%4d\t%.2f\n", sum[i], aver[i]); //输出总分及平均值
	}
}