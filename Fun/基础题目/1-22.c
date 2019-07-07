#include <stdio.h>

typedef struct Date {
	int year;
	int month;
	int day;
}Date;

int IsLeapYear(int year);
int GetMaxDay(int year, int month);
int GetDays(Date date1, Date date2);

int main(){
	int days;
	Date start, end;

	printf("请输入第一个日期(以空格为间隔符)：");
	scanf("%d%d%d", &start.year, &start.month, &start.day);
	printf("请输入第二个日期：");
	scanf("%d%d%d", &end.year, &end.month, &end.day);

	days = GetDays(start, end);
	printf("两个日期间隔着%d天\n", days);

	return 0;
}

int IsLeapYear(int year) {  // 判断是否为闰年
	return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int GetMaxDay(int year, int month) {  // 返回某年某月的天数
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return IsLeapYear(year) ? 29 : 28;
	default:
		return -1;
	}
}

int GetDays(Date date1, Date date2) {
	int days;
	if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
		return 0;
	}
	else {
		if (date1.year == date2.year && date1.month == date2.month) {
			days = date2.day - date1.day;
			return days;
		}
		else if (date1.year == date2.year) {
			int start_maxday = GetMaxDay(date1.year, date1.month);
			days = start_maxday - date1.day;
			if (date2.month == date1.month + 1) {
				days += date2.day;
				return days;
			}
			else {
				int m, n;
				m = date2.month;
				n = date1.month + 1;
				if (n != m) {
					days = GetMaxDay(date1.year, n);
					n++;
				}
				days += date2.day;
				return days;
			}
		}
	}
}