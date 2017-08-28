# 目录
* [实验1-1 warm up](#实验1-1-warm-up)
* [实验1-2 摄氏度与华氏度](#实验1-2-摄氏度与华氏度)
* [1-1 计算a+b](#1-1-计算a+b)
* [1-2 计算(a-b)*(a+b)](#1-2-计算(a-b)*(a+b))
* [1-3 计算(a+b)*5](#1-3-计算(a+b)*5)
* [1-4 铅球的重量](#1-4-铅球的重量)
* [1-5 铅球的重量－进阶](#1-5-铅球的重量－进阶)
* [1-6 空心铅球的重量](#1-6-空心铅球的重量)
* [1-7 代码冰箱贴－21点](#1-7-代码冰箱贴－21点)

<br>

## 实验1-1 warm up
**Description：**<br>
创建一个工程。编辑如下代码，编译并运行，观察程序的运行结果。记录运行中出现的错误。<br>

```
#include<stdio.h>
int main()
{
	int fahr, celsius;
	int upper, lower, step;

	upper = 300;
	lower = 0;
	step = 20;
	fahr = lower;

	while(fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
```

<br>**Sample Input：**<br>
`无`<br>

<br>**Sample Output：**<br>
```
0 -17
20 -6
40 4
60 15
80 26
100 37
120 48
140 60
160 71
180 82
200 93
220 104
240 115
260 126
280 137
300 148
```

<br>

## 实验1-2 摄氏度与华氏度
**Description：**<br>
在实验1-1中，显示的是0~300华氏温度，每隔20度，对应的摄氏度，<br>
修改实验1－1，由用户自己输入华氏温度的上限与下限，间隔仍为20度，输出对应的摄氏度。

>**提示：**<br>
>若从键盘输入一个数，放到变量a中，可使用如下语句：
>`scanf(“%d”,&a);`
><br>
>若从键盘输入两个数，分别放到变量a和变量b中，可使用如下语句：
>`scanf(“%d %d”,&a,&b);  `
>或
>`scanf(“%d”,&a);`
>`scanf(“%d”,&b);`

<br>**Sample Input：**<br>
```
100
300
```

<br>**Sample Output：**<br>
```
100 37
120 48
140 60
160 71
180 82
200 93
220 104
240 115
260 126
280 137
300 148
```

<br>

## 1-1 计算a+b
**Description：**<br>
编写程序，实现两个数相加。<br>
输入两个整数，以空格或者回车键分隔。<br>
输出两个整数的和。

<br>**Sample Input：**<br>
`1 4`

<br>**Sample Output：**<br>
`5`

<br>

## 1-2 计算(a-b)*(a+b)
**Description：**<br>
输入两个整数a,b，计算(a-b)*(a+b)，输出计算结果。

<br>**Sample Input：**<br>
`1 4`

<br>**Sample Output：**<br>
`-15`

<br>

## 1-3 计算(a+b)*5
**Description：**<br>
编写程序，输入两个整数，计算两个整数相加后乘以5的结果。

<br>**Sample Input：**<br>
`1 4`

<br>**Sample Output：**<br>
`25`

<br>

## 1-4 铅球的重量
**Description：**<br>
已知某种铅密度为11340kg/m³ ，求直径为9.8cm的铅球有多少kg。

>**提示：**<br>
>1）请用double类型存储小数数据; 圆周率取值3.1415926，C语言不识别数学中特殊字符，如圆周率pi<br>
>2）在C语言中两个整数相除的结果还是整数，如4/3，在C语言中计算结果为1，因此若想输出小数，则应为4.0/3<br>
>3）在C语言中，无法输入上标，因此x3应写为x\*x\*x<br>
>4) double类型数据的输出使用格式控制符％lf<br>

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`5.588431`

<br>

## 1-5 铅球的重量－进阶
**Description：**<br>
已知某种铅密度为11340kg/m³ ，求输入球的直径（厘米数），求铅球有多少kg。

>**提示：**<br>
>1）请用double类型存储小数数据； 圆周率取值3.1415926<br>
>2）double类型数据的输入用％lf格式控制符

<br>**Sample Input：**<br>
`9.8`
<br>**Sample Output：**<br>
`5.588431`
<br>**Sample Input：**<br>
`0.25`
<br>**Sample Output：**<br>
`0.000093`

<br>

## 1-6 空心铅球的重量
**Description：**<br>
已知某种铅密度为11340kg/m³ ，输入外直径（cm），内径（cm），求空心球有多kg。

<br>**Sample Input：**<br>
`9.8  5.1`

<br>**Sample Output：**<br>
`4.800801`

<br>

## 1-7 代码冰箱贴－21点
**Description：**<br>
某小组写了一些代码贴在寝室的冰箱上，但有人把冰箱贴弄乱了。你能用这些冰箱贴重组代码吗？<br>
该段代码用于计算牌面点数的程序，大牌点数有A（11），J（10），Q（10），K（10），小牌点数即为自身数字，如3，4，5，6等。即输入牌面，然后输出牌面点数。
>冰箱贴(代码)如下：
>```
>return
>
>'J'
>
><stdlib.h>
>
>else if
>
>'A'
>
>val =11; 
>
>#include
>
>int
>
>#include
>
>val = 10;
>
><stdio.h>
>
>
>      main()
>
>{
>
>    char card_name[3]; //定义数组
>
>    scanf("%2s",card_name);//输入两个字符作为牌名
>
>    int val = 0;
>
>    if (card_name[0] == 'K') {//card_name[0]取第一个字符
>
>        val = 10;
>
>    }else if (card_name[0] =='Q'){
>
>                               
>
>    }else if (card_name[0] ==          ){
>
>        val = 10;
>
>}         (card_name[0] ==         ){
>
>                        
>
>    }else{
>
>        val = atoi(card_name);//atoi函数将文本转为数值
>
>    }
>
>    printf("这张牌的点数是：%d\n",val);
>
>            0;
>
>}
>```

<br>**Sample Input：**<br>
`K`
<br>**Sample Output：**<br>
`这张牌的点数是：10`
<br>**Sample Input：**<br>
`A`
<br>**Sample Output：**<br>
`这张牌的点数是：11`
<br>**Sample Input：**<br>
`2`
<br>**Sample Output：**<br>
`这张牌的点数是：2`