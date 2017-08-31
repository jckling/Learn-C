#include<stdio.h>

int Win(char y[3][3]);

int main()
{
	int i, j, count;
	int a[9] = { 0 };
	char num[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	count = 0;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
		count++;
		for (j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				scanf("%d", &a[i]);
		}
		if (i % 2 == 0)
			num[a[i] / 3][a[i] % 3 - 1] = 'X';
		else
			num[a[i] / 3][a[i] % 3 - 1] = 'O';
		if (Win(num))
			break;	
		if (count == 9)
			break;
	}
	if (count == 9)
		printf("How boring, it is a draw\n");
	else
	{
		if (count % 2 == 0)
			printf("Congratulations, player %d, YOU ARE THE WINNER!\n", 2);
		else
			printf("Congratulations, player %d, YOU ARE THE WINNER!\n", 1);
	}
	return 0;
}

int Win(char y[3][3])
{
	int flag = 0;
	if (y[0][0] == y[0][1] && y[0][1] == y[0][2])
		flag = 1;
	if (y[1][0] == y[1][1] && y[1][1] == y[1][2])
		flag = 1;
	if (y[2][0] == y[2][1] && y[2][1] == y[2][2])
		flag = 1;
	if (y[0][0] == y[1][0] && y[1][0] == y[2][0])
		flag = 1;
	if (y[0][1] == y[1][1] && y[1][1] == y[2][1])
		flag = 1;
	if (y[0][2] == y[1][2] && y[1][2] == y[2][2])
		flag = 1;
	if (y[0][0] == y[1][1] && y[1][1] == y[2][2])
		flag = 1;
	if (y[0][2] == y[1][1] && y[1][1] == y[2][0])
		flag = 1;
	return flag;
}