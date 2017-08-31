#include <stdio.h>

typedef struct date
{
	int month;
	int day;
	int year;
}DATE;

DATE dateUpdate(DATE);

int main()
{
	DATE thisDay, nextDay;
	scanf("%d%d%d", &thisDay.month, &thisDay.day, &thisDay.year);

	nextDay = dateUpdate(thisDay);

	printf("%d %d %d\n", nextDay.month, nextDay.day, nextDay.year);
	return 0;
}

DATE dateUpdate(DATE a)
{
	int flag;
	if (a.year % 400 == 0)
		flag = 1;
	else if (a.year % 4 == 0 && a.year % 100 != 0)
		flag = 1;
	else
		flag = 0;
	if (a.day == 31)
	{
		switch (a.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			a.month++;
			a.day = 1;
			break;
		case 12:
			a.month = 1;
			a.day = 1;
			a.year++;
			break;
		}
	}
	else if (a.day == 30)
	{
		switch (a.month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			a.month++;
			a.day = 1;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			a.day++;
			break;
		}
	}
	else if (a.day == (28 + flag))
	{
		switch (a.month) {
		case 2:
			a.day = 1;
			a.month++;
			break;
		}
	}
	else
		a.day++;
	return a;
}
