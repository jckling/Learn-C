#include<stdio.h>
int main()
{
	int i;
	char a[8][8] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty" };
	char b[20][10] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	char c[9][9] = { "one","two","three","four","five","six","seven","eight","nine" };
	scanf("%d", &i);
	if (i < 20)
		printf("%s", b[i]);
	else if (i % 10 == 0)
		printf("%s", a[i / 10 - 2]);
	else
		printf("%s-%s", a[i / 10 - 2], c[i % 10 - 1]);
}