#include <stdio.h>

#define ARR_SIZE 40

int FindMax(int score[], long num[], int n, long *pMaxNum);

int main()
{
	int score[ARR_SIZE], maxScore, n, i;
	long num[ARR_SIZE], maxNum;

	// printf("Please enter total number:");
	scanf("%d", &n); /*从键盘输入学生人数n*/

					 // printf("Please enter the number and score:\n");
	for (i = 0; i<n; i++) /*分别以长整型和整型格式输入学生的学号和成绩*/
	{
		scanf("%ld%d", &num[i], &score[i]);
	}

	maxScore = FindMax(score, num, n, &maxNum); /*计算最高分及学生学号*/

	printf("maxScore = %d, maxNum =%ld", maxScore, maxNum);

	return 0;
}
int FindMax(int score[], long num[], int n, long *pMaxNum)
{
	int i, j;
	j = score[0];
	*pMaxNum = num[0];
	for (i = 1; i < n; i++)
	{
		if (j < score[i])
		{
			j = score[i];
			*pMaxNum = num[i];
		}
	}
	return  j;
}