#include <stdio.h>

void chaxun(int n) {
	int b;
	b = n;
	printf("您的余额为：%d\n", b);
}

int cunkuan(int n) {
	int a;
	printf("请输入您要存的金额：\n");
	scanf("%d", &a);
	if (a < 0) {
		printf("对不起，没有负存款\n");
	}
	else {
		printf("\n您好，您已存入%d元\n", a);
		n = n + a;
	}
	return n;
}

int qukuan(int n) {
	int a, b;
	printf("请输入您要提取的现金：\n");
	scanf("%d", &a);
	b = n - a;
	if (b < 0) {
		printf("对不起，您的余额不足\n");
	}
	else {
		printf("请收好您的%d元现金\n", a);
		n = n - a;
	}
	return n;
}

int xiugai(int n) {
	int b, c, d, e;
	c = e = 1;

	while (e) {
		printf("请输入您的旧密码：\n");
		scanf("%d", &d);
		if (d == n) {
			e = 0;
		}
		else {
			printf("您输入的密码错误，请重新输入：\n");
		}
	}
	while (c) {
		printf("请输入您的六位数新密码：\n");
		scanf("%d", &n);
		printf("请确认您的六位数新密码：\n");
		scanf("%d", &b);
		if (n == b) {
			if (b > 100000 && b < 999999 && b / (b / 100000) != 111111) {
				c = 0;
				printf("密码修改成功");
			}
			else {
				printf("您输入的密码不符合要求，请重新输入：\n");
			}
		}
		return n;
	}

}

void quka() {
	printf("\n提醒您\n");
	printf("请收好您的卡片，谢谢，再见\n\n");
}

int main() {
	int b, c, k, l;
	int a1 = 123456;
	int a2 = 123456;
	int a3 = 1000;
	b = 1;

	while (b == 1) {
		printf("请输入您的账号：\n");
		scanf("%d", &k);
		printf("请输入您的密码\n");
		scanf("%d", &l);
		if (k == a1 && l == a2) {
			b = 0;
			printf("您的账户余额为：%d\n", a3);
		}
		else {
			printf("对不起，您输入的账号或密码有误,请重新输入\n");
		}
	}

	do {
		printf("\n请选择您要的服务项目：\n");
		printf("1.查询余额\n");
		printf("2.存款\n");
		printf("3.取款\n");
		printf("4.修改密码\n");
		printf("5.取卡\n");

		scanf("%d", &c);
		switch (c) {
		case 1:
			chaxun(a3);
			break;
		case 2:
			a3 = cunkuan(a3);
			break;
		case 3:
			a3 = qukuan(a3);
			break;
		case 4:
			a2 = xiugai(a3);
			break;
		case 5:
			quka();
			break;
		}
	} while (c != 5);

	return 0;
}