#include<stdio.h>
#define N 100
int main()
{
	char a[N], b[N], c[N] = { 0 }, d[N] = { 0 };
	char pass[5][5] = { 0 };
	char al[N] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
	int i, k, n, m, count, flag, x, y;
	int a1, b1, a2, b2;
	count = 0;
	flag = 0;
	k = 0;
	gets_s(a);
	gets_s(b);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] != 'j')
		{
			if (count >= 5)
				k = 1;
			if (count >= 10 && count < 15)
				k = 2;
			if (count >= 15 && count < 20)
				k = 3;
			if (count >= 20)
				k = 4;
			pass[k][count % 5] = a[i];
			count++;
		}
	}
	for (m = 0; m < 25; m++)
	{
		if (count >= 5)
			k = 1;
		if (count >= 10 && count < 15)
			k = 2;
		if (count >= 15 && count < 20)
			k = 3;
		if (count >= 20)
			k = 4;
		flag = 1;
		for (n = 0; a[n] != '\0'; n++)
		{
			if (a[n] == 'j'|| a[n] == al[m])
				flag = 0;
		}
		if (flag)
		{
			pass[k][count % 5] = al[m];
			count++;
		}
	}//编制密码

	c[0] = b[0];
	n = 1;
	for (m = 1; b[m] != '\0'; m++)
	{

		if (b[m] == b[m - 1])
		{
			c[n] = 'x';
			c[n + 1] = b[m];
			n++;
		}
		else
			c[n] = b[m];
		n++;
	}
	if (n % 2 != 0)
		c[n] = 'x';
	//整理明文
	
	x = 0;
	for (i = 0; i <= n - 1; i += 2)
	{
		for (m = 0; m < 5; m++)
		{
 			for (y = 0; y < 5; y++)
			{
				if (c[i] == pass[m][y])
				{
					a1 = m;
					b1 = y;
				}
				if (c[i+1] == pass[m][y])
				{
					a2 = m;
					b2 = y;
				}
			}
		}
		if (a1 == a2)
			printf("%c%c",pass[a1][(b1 + 1) % 5], pass[a1][(b2 + 1) % 5]);
		if (b1 == b2)
			printf("%c%c", pass[(a1 + 1) % 5][b1], pass[(a2 + 1) % 5][b1]);
		if (a1 != a2&&b1 != b2)
			printf("%c%c", pass[a1][b2], pass[a2][b1]);
	}//编写输出
	return 0;
}