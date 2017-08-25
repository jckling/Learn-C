#include<stdio.h>
int main()
{
	int  a, b, num;
	scanf("%d %d", &a, &b);
	if (a > b)
		num = a - b;
	else
		num = b - a;

		if (num == 0)
	    printf("亲密无间");
	    if (num == 1)
		printf("永远和你在一起");
	    if (num == 2)
		printf("水火不相容");
	    if (num == 3)
		printf("知心朋友");
		if (num == 4)
		printf("心上人");
		if (num == 5)
		printf("帮你做事的人");
		if (num == 6)
		printf("帮你的人");
		if (num == 7)
		printf("面和心不合");
		if (num == 8)
		printf("男女关系不正常");
		if (num ==9)
		printf("情投意合");
		if (num == 10)
		printf("关系马虎");
		if (num == 11)
		printf("尊敬你的人");
		if (num == 12)
		printf("爱你的人");
		if (num == 13)
		printf("适合你的");
		if (num == 14)
		printf("说你坏话的人");
		if (num == 15)
		printf("克星");
		if (num == 16)
		printf("救星");
		if (num == 17)
		printf("忠心的人");
		if (num == 18)
		printf("狼心狗肺的人");
		if (num == 19)
		printf("单相思");
		if (num == 20)
		printf("山盟海誓");
		if (num == 21)
		printf("情敌");
		if (num == 22)
		printf("服从你的人");
		if (num == 23)
		printf("永远在一起");
		if (num == 24)
		printf("伴终生");
		if (num == 25)
		printf("恨你又爱你");
        if(num>25)
		printf("你俩缘分超出计算范围");

	return 0;
}