#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <Windows.h>
#define DEAL	50	/*设计最大交易次数*/
struct Date
{
	int da_year;  //年
	int da_mon;  //月
	int da_day;  //日
};
struct Time
{
	int ti_hour;   //小时
	int ti_min;   //分钟
	int ti_sec;    //秒
};
struct deal
{
	Date dt;						/*每笔交易的日期*/
	Time ti;						/*每笔交易的时间*/
	double earning;						/*每笔交易的收入额度*/
	double payout;						/*每笔交易的支出额度*/
};
typedef struct deal FINANCE;
FINANCE person[DEAL] = { 0 };    //存放用户每笔的交易信息

void getdate(Date *pd);//已实现，如下所示。获取系统日期，存入pd所指的Date结构体中
void gettime(Time *pt);// 已实现，如下所示。获取系统时间，存入pt所指的Time结构体中
void GetDateTime(FINANCE *per); //调用getdate与gettime函数将获取的时间日期存入per所指的结构体变量中
void Menu();  //显示系统菜单
char bioskey(); //返回用户输入的菜单命令
void InputOneDeal(FINANCE *per);  //执行菜单命令1，输入一笔交易，存入结构体per所指的结构体变量中。注意当输入为正数的时候存入earning中，输入为负数的时候存入payout中。
float Balance(FINANCE *per);  //返回账户中余额。账户person数组中的所有收入与支出之差。
void OneYearBalance(FINANCE *per, int year); //打印某一年的交易信息统计
void PrintBalance(FINANCE *per);  //执行菜单命令2，打印所有年份的所有交易信息
void PrintOneYear(FINANCE *per);//执行菜单命令3，打印某一年的所有交易信息，包括该年交易明细及调用OneYearBalance函数输出交易统计

int main()
{
	char key;
	int i;
	i = 0;
	while (1)
	{
		Menu();
		key = bioskey();
		fflush(stdin);   //清空缓冲区
		switch (key)
		{
		case '1':  InputOneDeal(person + i);
			i++;
			break;
		case '2':  PrintBalance(person);
			break;
		case '3':  PrintOneYear(person);
			break;
		case '4':  exit(0);
		default:  break;
		}
	}
}
//获取系统日期，存入pd所指的Date结构体中
void getdate(Date *pd)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pd->da_day = st.wDay;
	pd->da_mon = st.wMonth;
	pd->da_year = st.wYear;
}
//获取系统时间，存入pt所指的Time结构体中
void gettime(Time *pt)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pt->ti_hour = st.wHour;
	pt->ti_min = st.wMinute;
	pt->ti_sec = st.wSecond;
}
void GetDateTime(FINANCE *per)
{
	getdate(&(*per).dt);
	gettime(&(*per).ti);
}//调用getdate与gettime函数将获取的时间日期存入per所指的结构体变量中
void Menu()
{
	printf("1.Input One deal\n");
	printf("2.Print All the Balance\n");
	printf("3.Print One year Balance\n");
	printf("4.Exit to DOS\n");
}//显示系统菜单
char bioskey() 
{
	char c;
	char ch;
	scanf("%c", &c);
	while ((ch = getchar()) != '\n'&&ch != EOF);
	return c;
} //返回用户输入的菜单命令
void InputOneDeal(FINANCE *per) 
{
	float x;
    GetDateTime(per);
	printf("Please input one deal <+/->:\n");
	printf("%d/%d/%d   %02d:%02d:%02d  :", (*per).dt.da_year, (*per).dt.da_mon, (*per).dt.da_day, (*per).ti.ti_hour, (*per).ti.ti_min, (*per).ti.ti_sec);
	scanf("%f", &x);
	char ch;

	while ((ch = getchar()) != '\n'&&ch != EOF);
	if (x > 0)
		(*per).earning = x;
	else
		(*per).payout = x;
}  //执行菜单命令1，输入一笔交易，存入结构体per所指的结构体变量中。注意当输入为正数的时候存入earning中，输入为负数的时候存入payout中。
float Balance(FINANCE *per) 
{
	float sum = 0;
	int i;
	for (i = 0; per[i].earning != 0 || per[i].payout != 0; i++)
	{
		sum = sum + per[i].earning + per[i].payout;
	}
	return sum;
}  //返回账户中余额。账户person数组中的所有收入与支出之差。
void OneYearBalance(FINANCE *per, int year) 
{
	int i, flag = 0;
	float payout, earning;
	payout = earning = 0;
	for (i = 0; per[i].dt.da_year == year; i++)
	{
		payout += per[i].payout;
		earning += per[i].earning;
	}
	printf("\n\nparam of %d :\n", year);
	printf("%15s%20s%15s\n", "Sum of earning", "Sum of payout", "Balance");
	if (payout == 0 && earning == 0)
		printf("%15.2f%20.2f%15.2f\n", 0, 0, 0);
	else
		printf("%15.2f%20.2f%15.2f\n", earning, payout, Balance(per));
} //打印某一年的交易信息统计
void PrintBalance(FINANCE *per) 
{
	int i;
	printf("%6s%12s%15s%10s%12s\n", "Date", "Time", "Earning", "Payout", "Balance");
	for (i = 0; i < 60; i++)
		printf("-");
	printf("\n");
	for (i = 0; per[i].dt.da_year !=0; i++)
		printf("%d/%d/%d   %d:%d:%d%10.2f  %10.2f\n", per[i].dt.da_year, per[i].dt.da_mon, per[i].dt.da_day, per[i].ti.ti_hour, per[i].ti.ti_min, per[i].ti.ti_sec, per[i].earning, per[i].payout);
	for (i = 0; i < 60; i++)
		printf("-");
	printf("\n%55.2f\n", Balance(per));
}  //执行菜单命令2，打印所有年份的所有交易信息
void PrintOneYear(FINANCE *per) 
{
	int i, x;
	printf("Please Input one year :");
	scanf("%d", &x);
	char ch;
	while ((ch = getchar()) != '\n'&&ch != EOF);
	printf("%6s%12s%15s%10s%12s\n", "Date", "Time", "Earning", "Payout", "Balance");
	for (i = 0; i < 60; i++)
		printf("-");
	printf("\n");
	for (i = 0; per[i].dt.da_year == x; i++)
		printf("%d/%d/%d   %d:%d:%d%10.2f  %10.2f\n", per[i].dt.da_year, per[i].dt.da_mon, per[i].dt.da_day, per[i].ti.ti_hour, per[i].ti.ti_min, per[i].ti.ti_sec, per[i].earning, per[i].payout);
	for (i = 0; i < 60; i++)
		printf("-");
	OneYearBalance(per, x);
}//执行菜单命令3，打印某一年的所有交易信息，包括该年交易明细及调用OneYearBalance函数输出交易统计

