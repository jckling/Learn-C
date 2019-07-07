#include <stdio.h>

int main() {
	int m, n;
	int m_cup, n_cup, res;

	printf("请输入两个数字：\n");
	scanf("%d%d", &m, &n);

	if (m > 0 && n > 0) {
		m_cup = m;
		n_cup = n;
		res = m_cup % n_cup;

		while (res != 0) {
			m_cup = n_cup;
			n_cup = res;
			res = m_cup % n_cup;
		}

		printf("最大公约数为：%d\n", n_cup);
		printf("最小公倍数为：%d\n", m*n / n_cup);
	}
	else {
		printf("输入的数字错误\n");
	}

	return 0;
}