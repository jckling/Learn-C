#include<stdio.h>
int main()
{
	int x, i, reminder;
	x = 23;
	do
	{
		reminder = x;
		for (i = 1; i < 5; i++)
		{
			if ((reminder + 1) % (i + 1) == 0)
				reminder = reminder - (reminder + 1) / (i + 1);
			else
				break;
		}
		x += 2;
	} while (reminder != 11 || i != 5);
	printf("%d", x - 2);
	return 0;
}
