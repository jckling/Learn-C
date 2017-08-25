#include <stdio.h>

#define CLASS 3
#define STU 4

int FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{
	int score[CLASS][STU], i, j, maxScore, row, col;
	// printf("Please enter score:\n");
	for (i = 0; i<CLASS; i++)
	{
		for (j = 0; j<STU; j++)
		{
			scanf("%d", &score[i][j]); /*输入学生成绩*/
		}
	}

	/*计算最高分及其学生所在班号和学号*/
	maxScore = FindMax(*score, CLASS, STU, &row, &col);

	printf("maxScore = %d, class =%d, number =%d\n", maxScore, row + 1, col + 1);
}

int FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
	int max, i, j;

	max = *p;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (*p> max)
			{
				max = *p;
				*pRow = i;
				*pCol = j;
			}
			p++;
		}
	}
	return max;
}