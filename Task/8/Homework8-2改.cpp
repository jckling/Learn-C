#include<stdio.h>
int main()
{
	char a[18], b[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 }, x;
	int i, j, sum = 0;
	for (i = 0; i < 18; i++)
		scanf("%c", &a[i]);
	for (i = 0; i < 17; i++)
		sum += (a[i] - '0')*b[i];
	switch (sum%11) {
	case 0:
		x = '1';
		break;
	case 1:
		x = '0';
		break;
	case 2:
		x = 'X';
		break;
	case 3:
		x = '9';
		break;
	case 4:
		x = '8';
		break;
	case 5:
		x = '7';
		break;
	case 6:
		x = '6';
		break;
	case 7:
		x = '5';
		break;
	case 8:
		x = '4';
		break;
	case 9:
		x = '3';
		break;
	case 10:
		x = '2';
		break;
	}
	if ((a[17] - x) == 0)
		printf("yes");
	else
		printf("no");
	return 0;
}