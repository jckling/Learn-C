#include<stdio.h>
void printCal(int days,int firstday);

int main()
{
	int days;
	int firstday;
	do
	{
		// printf("Enter number of days in month:");
		scanf("%d", &days);
	} while (days > 31 || days < 1);
	do
	{
		// printf("Enter starting day of the week(1=Sun,...7=Sat):");
		scanf("%d", &firstday);
	} while (firstday < 1 || firstday > 7);
	printCal(days, firstday);

	return 0;
}
void printCal(int days, int firstday)
{
	int i, k;
	printf("\n Sun Mon Tue Wed Thu Fri Sat\n");
	
	for(k = 1; k < (firstday % 8); k++)
	{
		printf("%4c",' ');
	} //空格输出占4位
	for (i = 1; i <= days; i++)
	{
		printf("%4d", i); //数字输出占4位
		if (i % 7 == (8 - firstday))
			printf("\n");
	}

}