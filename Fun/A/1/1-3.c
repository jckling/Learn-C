#include <stdio.h>

int main() {
	printf("size of char is:%d\n", sizeof(char));  // 字符型
	printf("size of short is:%d\n", sizeof(short));  // 短整型

	printf("size of int is:%d\n", sizeof(int));  // 整型
	printf("size of short int is:%d\n", sizeof(short int));  // 短整型
	printf("size of long int is:%d\n", sizeof(long int));  // 长整型

	printf("size of float is:%d\n", sizeof(float));  // 单精度浮点型
	printf("size of double is:%d\n", sizeof(double));  // 双精度浮点型

	char a[] = { 'a','b','c','d','e' };
	printf("size of  a[] is:%d\n", sizeof(a));  // 字符型数组

	char b[] = "abcde";
	printf("size of b[] is:%d\n", sizeof(b));  // 字符串型数组

	char c[][3] = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'} };  // 二维字符型数组
	printf("size of c[][] is:%d\n", sizeof(c));
	printf("size of (c[0]) is:%d\n", sizeof(c[0]));
	printf("size of (c[0][0]) is:%d\n", sizeof(c[0][0]));

	char d[][5] = { "abcc","deff","ghii","jkll" };  // 二维字符数组
	printf("size of d[0] is:%d\n", sizeof(d[0]));
	printf("size of d[0][0] is:%d\n", sizeof(d[0][0]));

	char *p = 0;  // 字符型指针
	printf("size of char *p is:%d\n", sizeof(p));

	return 0;
}