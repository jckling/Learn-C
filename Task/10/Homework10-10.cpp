#include<stdio.h>
#include<math.h>

int P(int a, int b, int c, int d);

int main()
{
	int a, b, c, d;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (P(a, b, c, d))
		printf("y");
	else
		printf("n");
	return 0;
}

int P(int a, int b, int c, int d)
{
	int flag = 0;
	int x, y;
	if (a + b + c + d == 24 || a * b * c * d == 24)
		flag = 1;
	else if (a + b + c - d == 24 || a + b + d - c == 24 || a + c + d - b == 24 || b + c + d - a == 24)
		flag = 1;
	else if (abs(a - b) + abs(c - d) == 24 || abs(a - c) + abs(b - d) == 24 || abs(a - d) + abs(b - c) == 24)
		flag = 1;
	else if (abs((a + b) - (c + d)) == 24 || abs((a + c) - (b + d)) == 24 || abs((a + d) - (b + c)) == 24)
		flag = 1;
	else if (abs((a - b)*(c - d)) == 24 || abs((a - c)*(b + d)) == 24 || abs((a - d)*(b + c)) == 24)
		flag = 1;
	else if (a*b*(c + d) == 24 || a*c*(b + d) == 24 || a*d*(b + c) == 24 || b*c*(a + d) == 24 || b*d*(a + c) == 24 || c*d*(a + b) == 24)
		flag = 1;
	else if (abs(a*b*(c - d)) == 24 || abs(a*c*(b - d)) == 24 || abs(a*d*(b - c)) == 24 || abs(b*c*(a - d)) == 24 || abs(b*d*(a - c)) == 24 || abs(c*d*(a - b)) == 24)
		flag = 1;
	else if (abs((a - b)*(c + d)) == 24 || abs((a - c)*(b + d)) == 24 || abs((a - d)*(b + c)) == 24 || abs((b - c)*(a + d)) == 24 || abs((c - d)*(a + b)) == 24)
		flag = 1;
	else if ((a + b) / c*d == 24 || (a + b) / d*c == 24 || (a + c) / b*d == 24 || (a + c) / d*b == 24 || (a + d) / b*c == 24 || (a + d) / c*b == 24 || (b + c) / a*d == 24 || (b + c) / d*a == 24 || (c + d) / a*b == 24 || (c + d) / b*a == 24)
		flag = 1;
	else if (abs((a - b / c))*d == 24 || abs((a - c / b))*d == 24 || abs((a - b / d))*c == 24 || abs((a - d / b))*c == 24 || abs((a - c / d))*b == 24 || abs((a - d / c))*b == 24 || abs((b - a / c))*d == 24 || abs((b - c / a))*d == 24 || abs((b - a / d))*c == 24 || abs((b - d / a))*c == 24 || abs((b - c / d))*a == 24 || abs((b - d / c))*a == 24 || abs((c - b / a))*d == 24 || abs((c - a / b))*d == 24 || abs((c - b / d))*a == 24 || abs((c - d / b))*a == 24 || abs((c - a / d))*b == 24 || abs((c - d / a))*b == 24 || abs((d - b / c))*a == 24 || abs((d - c / b))*a == 24 || abs((d - b / a))*c == 24 || abs((d - a / b))*c == 24 || abs((d - c / a))*b == 24 || abs((d - a / c))*b == 24)
		flag = 1;
	else if ((a + b - c)*d == 24 || (a + c - b)*d == 24 || (b + c - a)*d == 24 || (a + d - c)*b == 24 || (a + c - d)*b == 24 || (d + c - a)*b == 24 || (a + b - d)*c == 24 || (a + d - b)*c == 24 || (b + d - a)*c == 24 || (d + b - c)*a == 24 || (d + c - b)*a == 24 || (b + c - d)*a == 24)
		flag = 1;
	else if (a*b + c - d == 24 || a*b + d - c == 24 || a*c + b - d == 24 || a*c + d - b == 24 || a*d + b - c == 24 || a*d + c - b == 24 || b*c - a + d == 24 || b*c - d + a == 24 || c*d + a - b == 24 || c*d + b - a == 24)
		flag = 1;
	else if (abs((a - b))*c + d == 24 || abs((a - b))*d + c == 24 || abs((a - c))*b + d == 24 || abs((a - c))*d + b == 24 || abs((a - d))*b + c == 24 || abs((a - d))*c + b == 24 || abs((b - c))*a + d == 24 || abs((b - c))*d + a == 24 || abs((b - d))*a + c == 24 || abs((b - d))*c + a == 24 || abs((c - d))*a + b == 24 || abs((c - d))*b + a == 24)
		flag = 1;
	return flag;

}