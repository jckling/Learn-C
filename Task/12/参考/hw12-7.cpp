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
FINANCE person[DEAL]={0};    //存放用户每笔的交易信息

void getdate(Date *pd);//获取系统日期，存入pd所指的Date结构体中
void gettime(Time *pt);//获取系统时间，存入pt所指的Time结构体中
void GetDateTime(FINANCE *per); //调用getdate与gettime函数将获取的时间日期存入per所指的结构体数组中
void Menu();  //显示系统菜单
char bioskey(); //返回用户输入的菜单命令
void InputOneDeal(FINANCE *per);  //执行菜单命令1，输入一笔交易，存入结构体数组中
float Balance(FINANCE *per);  //返回账户中余额
void OneYearBalance(FINANCE *per,int year); //打印某一年的交易信息统计
void PrintBalance(FINANCE *per);  //执行菜单命令2，打印所有年份的所有交易信息
void PrintOneYear(FINANCE *per);//执行菜单命令3，打印某一年的交易信息，包括该年交易明细及交易统计

int main()
{
	char key;
	int i;

	i = 0;

	while(1)
	{
		Menu();
		key=bioskey();
		fflush(stdin);   //清空缓冲区
 		switch(key)
		{
		case '1':  InputOneDeal(person+i);
			i++;
			break;
		case '2':  PrintBalance(person);
			break;
		case '3':  PrintOneYear(person);
			break;
		case '4':  exit(0);
		default :  break;
		}
	}
}

//获取系统日期，存入pd所指的Date结构体中
void getdate(Date *pd)  
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pd->da_day=st.wDay;
	pd->da_mon=st.wMonth;
	pd->da_year=st.wYear;
}
//获取系统时间，存入pt所指的Time结构体中
void gettime(Time *pt)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	pt->ti_hour=st.wHour;
	pt->ti_min=st.wMinute;
	pt->ti_sec=st.wSecond;
}
/*	函数功能：获得计算机的系统日期、时间
函数参数：结构体指针变量per，代表指向结构体数组的指针
函数返回值：无
*/
void GetDateTime(FINANCE *per)
{
	getdate(&per->dt);
	printf("%d/%02d/%02d  ",per->dt.da_year,per->dt.da_mon,per->dt.da_day);

	gettime(&per->ti);
	printf("%02d:%02d:%02d :",per->ti.ti_hour,per->ti.ti_min,per->ti.ti_sec);
}
/*	函数功能：每一笔交易输入模块
函数参数：结构体指针变量per，代表指向结构体数组的指针
函数返回值：无
*/
void InputOneDeal(FINANCE *per)
{
	char string[10];

	printf("Please input one deal (+/-):\n");
	GetDateTime(per);

	scanf("%s",&string);
	if(string[0] == '-')
		per->payout = atof(string);  //atof函数用于将一个字符串转换为相应的数字，如将"-475.67"转换为-475.67
	else
		per->earning = atof(string);
}
/*	函数功能：求账面上的余额
函数参数：结构体指针变量per，代表指向结构体数组的指针
函数返回值：账面余额
*/
float Balance(FINANCE *per)
{
	int i;
	double sum1 = 0.0,sum2 = 0.0;

	for(i=0;i<DEAL;i++)
	{
		sum1 += (per+i)->earning;
		sum2 += (per+i)->payout;
	}
	return sum1+sum2;
}



/*	函数功能：菜单模块
函数参数：无
函数返回值：无
*/
void Menu()
{
	printf("1.Input One deal\n");
	printf("2.Print All the Balance\n");
	printf("3.Print One year Balance\n");
	printf("4.Exit to DOS\n");
}
char bioskey()
{
	char choice[10];
	scanf("%1s",choice);
	return choice[0];
}
/*	函数功能：年度统计，输出年度收入总额、支出总额、余额
函数参数：结构体指针变量per，代表指向结构体数组的指针
                      整型变量year，代表年度，如2004
函数返回值：无
*/
void OneYearBalance(FINANCE *per,int year)
{
	int i;
	double sum1 = 0.0,sum2 = 0.0;

	for(i=0;i<DEAL;i++)
	{
		if((per+i)->dt.da_year != year)continue;

		sum1 += (per+i)->earning;
		sum2 += (per+i)->payout;
	}
	printf("param of %d  : \n ",year);
	printf("Sum of earning       Sum of payout        Balance\n");
	printf("%15.2f%20.2f%15.2f\n",sum1,sum2,sum1+sum2);
}
/*	函数功能：打印所有的交易信息
函数参数：结构体指针变量per，代表指向结构体数组的指针
函数返回值：无
*/
void PrintBalance(FINANCE *per)
{
	int i;
	printf("  Date       Time      Earning     Payout    Balance \n");
	printf("-----------------------------------------------------\n");
	for(i=0;i<DEAL;i++)
	{
		if((per+i)->dt.da_year != 0)
		{
			printf("%d/%2d/%2d  ",(per+i)->dt.da_year,
				(per+i)->dt.da_mon,(per+i)->dt.da_day);
			printf("%02d:%02d:%02d  ",(per+i)->ti.ti_hour,
				(per+i)->ti.ti_min,(per+i)->ti.ti_sec);
		}
		if((per+i)->earning!=0)
			printf("%8.2f\n",(per+i)->earning);
		if((per+i)->payout!=0)
			printf("            %8.2f\n",(per+i)->payout);
	}
	printf("-----------------------------------------------------\n");
	printf("                                             %8.2f\n",	Balance(per));
}

/*	函数功能：打印某一年的交易信息
函数参数：结构体指针变量per，代表指向结构体数组的指针
函数返回值：无
*/
void PrintOneYear(FINANCE *per)
{
	int i,year;
	printf("Please Input one year :");
	scanf("%d",&year);
	printf("  Date       Time      Earning     Payout    \n");
    printf("----------------------------------------------\n");
	for(i=0;i<DEAL;i++)
	{
		if((per+i)->dt.da_year != year) continue;

		if((per+i)->dt.da_year!=0)
		{
			printf("%d/%02d/%d  ",(per+i)->dt.da_year,
				(per+i)->dt.da_mon,(per+i)->dt.da_day);
			printf("%02d:%02d:%02d   ",(per+i)->ti.ti_hour,
				(per+i)->ti.ti_min,(per+i)->ti.ti_sec);
		}
		if((per+i)->earning!=0)
			printf("%8.2f\n",(per+i)->earning);
		if((per+i)->payout!=0)
			printf("            %8.2f\n",(per+i)->payout);
	}
    printf("----------------------------------------------\n");
   printf("\n");
	OneYearBalance(per,year);
}

