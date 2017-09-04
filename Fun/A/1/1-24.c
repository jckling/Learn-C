#include <stdio.h>

int main() {
	float num = 3.1415;
	char chFloat[20];

	printf("float num = %f\n", num);
	printf("×ª»»Îª×Ö·û´®Êä³ö£º\n");
	sprintf(chFloat, "%f", num);
	printf("chFloat = %s\n", chFloat);

	return 0;
}