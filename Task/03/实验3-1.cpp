#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);

	if (a < 25){
		printf("Wrong!Too low!\n");}
	else if(a == 25){
		printf("Right!\n");}
	else{
		printf("Wrong!Too high!\n");}
	printf("The number is:25");

	return 0;
}