#include<stdlib.h>
#include<stdio.h>
int main()
{
	char card_name[3]; //定义数组
	int val = 0;
		scanf("%2s", card_name);//输入两个字符作为牌名
	if (card_name[0] == 'K') {//card_name[0]取第一个字符
		val = 10;
	}
	else if (card_name[0] == 'J') {
		val = 10;
	}
	else if (card_name[0] == 'Q') {
		val = 10;
	}
	else if (card_name[0] == 'A') {
		val = 11;
	}
	else {
		val = atoi(card_name);//atoi函数将文本转为数值
	}

	printf("这张牌的点数是：%d\n", val);
	return 0;

}