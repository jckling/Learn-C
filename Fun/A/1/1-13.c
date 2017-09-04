#include <stdio.h>
#include <stdlib.h>

void Merge(int *a, int *b, int *c, int nA, int nB, int *nCount) {
	int i, j, k;
	i = j = k = 0;

	while (i < nA&&j < nB) {
		if (a[i] < b[j]) {
			c[k++] = a[i];
			++i;
			(*nCount)++;
		}
		else if (a[i] == b[j]) {
			c[k++] = a[i];
			++i;
			++j;
			(*nCount)++;
		}
		else {
			c[k++] = b[j];
			++j;
			(*nCount)++;
		}
	}

	if (i == nA) {
		for (int m = j; m < nB; ++m) {
			c[k++] = b[m];
			(*nCount)++;
		}
	}
	else {
		for (int m = i; m < nA; ++m) {
			c[k++] = a[m];
			(*nCount)++;
		}
	}

}

int main() {
	int *a = (int*)malloc(sizeof(int) * 6);
	int *b = (int*)malloc(sizeof(int) * 3);
	
	a[0] = 2;
	a[1] = 3;
	a[2] = 4;
	a[3] = 6;
	a[4] = 8;
	a[5] = 9;

	b[0] = 7;
	b[1] = 9;
	b[2] = 10;

	int n = 0;
	int *c= (int*)malloc(sizeof(int) * 12);

	Merge(a, b, c, 6, 3, &n);

	for (int i = 0; i < n; i++) {
		printf("%3d", c[i]);
	}
	printf("\n");

	free(a);
	free(b);
	free(c);
	a = b = c = NULL;

	return 0;
}