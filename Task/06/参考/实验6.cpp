#include<stdio.h>
#define	QUIT 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define DISCOUNT 0.95
#define STARS  *******************************************

int menu();
int getnights();
void showprice(double, int);

int main()
{
	int nights;
	double hotel_rate;
	int code;
	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1: hotel_rate = HOTEL1;
			break;
		case 2: hotel_rate = HOTEL2;
			break;
		case 3: hotel_rate = HOTEL3;
			break;
		case 4: hotel_rate = HOTEL4;
			break;
		default: hotel_rate = 0.0;
			printf("Oops!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you and GoodBye.");
	return 0;
}

int menu()
{
	int code, status;
	//	printf("\n%s%s\n",STARS,STARS);
	printf("\n********************************************\n");
	printf("Enter the number of the desired hotel:\n");
	printf("1) Fairfield Arms        2) Hotel Olympic\n");
	printf("3) chertworthy Plaza     4) The Stockton\n");
	printf("5) quit\n");
	//printf("%s%s\n",STARS,STARS);
	printf("********************************************\n");

	//while((status = scanf("%d",&code)!= 1) || code<1 ||code > 5)
	//{
	//	if(status != 1)
	//		scanf("%*s");
	//	printf("Enter an integer form 1 to 5, please.\n");
	//}
	status = scanf("%d", &code);
	while ((status != 1) || code<1 || code > 5)
	{
		while (getchar() != '\n');
		//scanf("%*s");
		printf("Enter an integer form 1 to 5, please.\n");
		status = scanf("%d", &code);

	}
	fflush(stdin);
	return code;
}

int getnights()
{
	int nights;
	printf("How many nights are needed? ");
	while (scanf("%d", &nights) != 1)
	{
		while (getchar() != '\n');
		//scanf("%*s");
		printf("Enter an integer ,such as 2.\n");
	}
	fflush(stdin);
	return nights;
}

void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	printf("The total cost will be $\n ");
	for (n = 1; n <= nights; n++)
	{
		printf("%.0f * %.1f%%", rate, factor * 100);
		if (nights>1)
			printf(" + ");
		if (n != 1 && n == nights)
			printf("\b\b");
		total += rate * factor;
		factor *= DISCOUNT;

	}
	printf(" = %0.2f", total);
}




