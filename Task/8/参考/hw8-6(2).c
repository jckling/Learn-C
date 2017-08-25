// one.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int f(int m,int n)
{
	if (m > 1)
	{
		if (m == 2) printf("Twenty");
		if (m == 3) printf("Thirty");
		if (m == 4) printf("Forty");
		if (m == 5) printf("Fifty");
		if (m == 6) printf("Sixty");
		if (m == 7) printf("Seventy");
		if (m == 8) printf("Eighty");
		if (m == 9) printf("Ninety");
		if (n != 0) printf("-");
		if (n == 1) printf("one");
		if (n == 2) printf("two");
		if (n == 3) printf("three");
		if (n == 4) printf("four");
		if (n == 5) printf("five");
		if (n == 6) printf("six");
		if (n == 7) printf("seven");
		if (n == 8) printf("eight");
		if (n == 9) printf("nine");
	}
    if(n==0&&m==0) printf("Zero");
    if(n==0&&m==1) printf("Ten");
	if (m == 1)
	{
		if (n == 1) printf("Eleven");
		if (n == 2) printf("Twelve");
		if (n == 3) printf("Thirteen");
		if (n == 4) printf("Forteen");
		if (n == 5) printf("Fifteen");
		if (n == 6) printf("Sixteen");
		if (n == 7) printf("Seventeen");
		if (n == 8) printf("Eighteen");
		if (n == 9) printf("Nineteen");
	}
	if (m == 0)
	{
		if (n == 1) printf("One");
		if (n == 2) printf("Two");
		if (n == 3) printf("Three");
		if (n == 4) printf("Four");
		if (n == 5) printf("Five");
		if (n == 6) printf("Six");
		if (n == 7) printf("Seven");
		if (n == 8) printf("Eight");
		if (n == 9) printf("Nine");
	}
    return 0;
}


int main(int argc, char* argv[])
{   int m,n;
    scanf("%d",&m);
    n=m%10;//个位
    m=m/10;//十位
    f(m,n);
    
    return 0;
}

