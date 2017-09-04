#include <stdio.h>
#include <math.h>

int main() {
	int start, end;
	int i, k, n;
	end = 200;
	n = 0;

	for (start = 101; start < 200; start += 2) {
		k = (int)sqrt(start);
		for (i = 2; i <= k; i++) {
			if (start % i == 0)
				break;
		}
		if (i >= k + 1) {
			printf("%4d", start);
			n++;
		}
		if (n % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}