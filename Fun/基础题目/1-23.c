#include <stdio.h>

typedef struct Date {
	int year;
	int month;
	int day;
}Date;

int IsLeapYear(int year);
int GetDays(Date date);

int main() {
	int days;
	Date date;

	printf("请输入日期(以空格为间隔符)：");
	scanf("%d%d%d", &date.year, &date.month, &date.day);

	days = GetDays(date);
	printf("%d年%d月%d日是%d年的第%d天\n", date.year, date.month, date.day, date.year, days);

	return 0;
}

int IsLeapYear(int year) {  // 判断是否为闰年
	return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int GetDays(Date date) {
	int month_0[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int month_1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, days;
	days = 0;

	if (IsLeapYear(date.year)) {
		for (i = 0; i < date.month - 1; i++) {
			days += month_0[i];
		}
	}
	else {
		for (i = 0; i < date.month - 1; i++) {
			days += month_1[i];
		}
	}

	days += date.day;

	return days;
}