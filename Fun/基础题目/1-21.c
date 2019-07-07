#include <stdio.h>

int main() {
	for (int i = 32; i < 120; i++) {  // 可见部分从32号开始，第32号为空格
		if (i % 8 == 0) {
			printf("\n");
		}
		printf("%6c", (char)i);
	}

	return 0;
}