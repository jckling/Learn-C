#include  <stdio.h>
#include<time.h>

struct clock
{
	int hour;
	int minute;
	int second;
};
typedef struct clock CLOCK;

/*函数功能：时、分、秒时间的更新
函数参数：指向CLOCK结构体变量的指针t，表示时、分、秒时间
函数返回值：	无
*/
void Update(CLOCK *t)
{
	t->second++;
	if (t->second == 60) 	/*若second值为，表示已过一分钟，则minute值加*/
	{
		t->second = 0;
		t->minute++;
	}
	if (t->minute == 60)   	/*若minute值为，表示已过一小时，则hour值加*/
	{
		t->minute = 0;
		t->hour++;
	}
	if (t->hour == 24)     	/*若hour值为，则hour值从开始计时*/
	{
		t->hour = 0;
	}
}

/*函数功能：时、分、秒时间的显示
函数参数：指向CLOCK结构体变量的指针t，表示时、分、秒时间
函数返回值：	无
*/
void Display(CLOCK *t)
{
	printf("%02d:%02d:%02d\r", t->hour, t->minute, t->second);
}

/*函数功能：模拟延迟秒的时间
函数参数：无
函数返回值：	无
*/
void Delay(void)
{
	long t;
	/*time_t currentTime;
	currentTime = time(NULL);
	while( time(NULL) < currentTime + 1);*/

	for (t = 0; t<500000000; t++)
	{
		/*循环体为空语句的循环，起延时作用*/
	}
}

int main()
{
	long i;
	CLOCK myclock;

	myclock.hour = myclock.minute = myclock.second = 0;
	for (i = 0; i<100000; i++)    		/*利用循环结构，控制时钟运行的时间*/
	{
		Update(&myclock);          	/*时钟更新*/
		Display(&myclock);          	/*时间显示*/
		Delay();                     	/*模拟延时秒*/
	}
}
