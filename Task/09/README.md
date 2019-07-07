# 目录
* [实验9 指针判断回文](#实验9-指针判断回文)
* [9-1 三个数排序](#9-1-三个数排序)
* [9-2 直角坐标值转换为极坐标值](#9-2-直角坐标值转换为极坐标值)
* [9-3 最大最小值交换](#9-3-最大最小值交换)
* [9-4 部分逆序](#9-4-部分逆序)
* [9-5 函数求最大最小值及其下标](#9-5-函数求最大最小值及其下标)
* [9-6 统计字符串中数字字符出现的个数](#9-6-统计字符串中数字字符出现的个数)
* [9-7 找最长的单词](#9-7-找最长的单词)
* [9-8 字符串连接](#9-8-字符串连接)
* [9-9 字符串比较](#9-9-字符串比较)
* [9-10 统计子串出现的次数](#9-10-统计子串出现的次数)
* [9-11 帽子的大小](#9-11-帽子的大小)
* [9-12 Tic Tac Toe游戏](#9-12-tic-tac-toe游戏)

<br>

## 实验9 指针判断回文
**Description：**<br>
编写一个函数，检查一个字符串是否是回文。主函数输入一个字符串（设不超过80个字符），输出该字符串是否是回文的信息。回文是指一个字符串顺读和倒读都一样，如ABCBA，aaaa等是回文，china，ABC就不是回文。
>**提示：**<br>
>程序的前缀及后缀代码已给出，要求用指针完成
>```
>前缀代码:
>
>#include <stdio.h>
>#include <string.h>
>
>int main()
>{
>    char str[80], *pStart, *pEnd;
>    int len;
>
>    gets(str);
>    len = strlen(str);
>    pStart = str;
>    pEnd = str + len - 1;
>```
>```
>后缀代码：
>
>return 0;
>}
>```

<br>**Sample Input：**<br>
`abccccba`
<br>**Sample Output：**<br>
`yes`
<br>**Sample Input：**<br>
`abccccb`
<br>**Sample Output：**<br>
`no`

<br>

## 9-1 三个数排序
**Description：**<br>
从键盘上输入三个数，按从小到大的顺序显示出来。要求利用函数和指针来完成。
>**主函数如下：**
>```
>int main()
>{
>  int a, b, c;
>  scanf("%d,%d,%d", &a, &b, &c);
>  printf("origin:%d,%d,%d\n", a, b, c);
>  sort_three(&a, &b, &c);
>  printf("sort:%d,%d,%d\n", a, b, c);
>}
>```

<br>**Sample Input：**<br>
`56,-89,34`

<br>**Sample Output：**<br>
```
origin:56,-89,34
sort:-89,34,56
```

<br>

## 9-2 直角坐标值转换为极坐标值
**Description：**<br>
编写程序，将直角坐标值转化为极坐标。<br>
极坐标的公式是：<br>
`c= sqrt(x*x+y*y)`，`q=arctan(y/x)`<br>
函数f的定义为：`void fun(double x,double y,double *c,double *q)`，其中x, y为输入的直角坐标，指针c, q用于返回计算得到的极坐标值。<br>
主程序读入x, y，输出c, q，其中c,q保留小数点后面两位。
>**提示：**<br>
>程序中可以使用C++库函数sqrt和atan，它们的头文件为math.h<br>
>注意处理横坐标或纵坐标为0的特殊情况

<br>**Sample Input：**<br>
`0 0`
<br>**Sample Output：**<br>
`0.00 0.00`
<br>**Sample Input：**<br>
`0 1`
<br>**Sample Output：**<br>
`1.00 1.57`
<br>**Sample Input：**<br>
`1 0`
<br>**Sample Output：**<br>
`1.00 0.00`
<br>**Sample Input：**<br>
`1 1`
<br>**Sample Output：**<br>
`1.41 0.79`

<br>

## 9-3 最大最小值交换
**Description：**<br>
键盘上输入一组数的个数n（小于10个）以及这n个数，最大的与第一个元素交换，最小的与最后一个元素交换，并输出交换后的数组。
>**提示：**<br>
>程序的前缀及后缀代码已给出
>```
>前缀代码：
>
>#include <stdio.h>
>int main()
>{
>    int *pmax, *pmin;
>    int data[10], temp, i, n;
>    //    printf("enter n:");
>    scanf("%d", &n);
>    //    printf("enter %d data:", n);
>    for(i = 0; i < n; i++)
>        scanf("%d", &data[i]);
>    printf("orgin:");
>    for(i = 0; i < n; i++)
>        printf("%4d", data[i]);
>    printf("\n");
>```
>```
>后缀代码：
>
>    printf("sorted:");
>    for(i = 0; i < n; i++)
>        printf("%4d", data[i]);
>    printf("\n");
>}
>```

<br>**Sample Input：**<br>
```
5
67 -67 45 3 20
```

<br>**Sample Output：**<br>
```
orgin:  67 -67  45   3  20
max=67
min=-67
sorted:  67  20  45   3 -67
```

<br>

## 9-4 部分逆序
**Description：**<br>
设有一数列，包含10 个数，已按升序排好。现要求编一程序，它能够把从指定位置m开始的n个数按逆序重新排列并输出新的完整数列。<br>
进行逆序处理时要求使用指针方法（例如：原数列为2，4，6，8，10，12，14，16，18，20，m=4, n=5，即要求把从第4个数开始的5个数按逆序重新排列，则得到新数列为2，4，6，16，14，12，10，8，18，20。）<br>
输入10个整数和m, n；输出新的数组，数组元素之间以空格分隔。
>**主函数如下：**
>```
>#include <stdio.h>
>void method(int m, int n, int *a);
>int main()
>{
>    int a[10];
>    int i, m, n;
>    
>    for(i = 0; i < 10; i++)
>        scanf("%d", &a[i]);
>    scanf( "%d%d", &m, &n);
>    
>    method(m, n, a);
>
>    for(i = 0; i < 10; i++ )
>        printf( "%d ", a[i]);
>}
>```

<br>**Sample Input：**<br>
```
2 4 6 8 10 12 14 16 18 20
4 5
```

<br>**Sample Output：**<br>
`2 4 6 16 14 12 10 8 18 20`

<br>

## 9-5 函数求最大最小值及其下标
**Description：**<br>
从键盘任意输入10个整数，用函数编程实现计算最大值和最小值，并返回它们所在数组中的位置。当有重复数值出现时，仅记录首次出现时所在数组中的位置。
>要求定义如下函数求最大最小值<br>
>函数功能：求n个数中的最大值和最小值及其所在下标位置<br>
>函数入口参数：整型数组num，存储n个整数;整型变量n，表示数组元素个数<br>
>函数出口参数：整型指针变量pMaxPos，指向的地址单元存储最大值在数组中的下标位置; 整型指针变量pMax，指向的地址单元存储最大值;整型指针变量pMinPos，指向的地址单元存储最小值在数组中的下标位置;整型指针变量pMin，指向的地址单元存储最小值<br>
>函数返回值：无<br>
>void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos)<br>
>输出格式：
`printf("Max = %d , Position = %d, Min = %d, Position = %d\n",....);`

<br>**Sample Input：**<br>
`4 -6 67 89 -123 5 6 7 90 64`

<br>**Sample Output：**<br>
`Max = 90 , Position = 8, Min = -123, Position = 4`

<br>

## 9-6 统计字符串中数字字符出现的个数
**Description：**<br>
编写函数numbers，通过指针操作，统计一个字符串中数字字符的个数。
>**提示：**<br>
>程序的前缀代码已给出
>```
>前缀代码：
>
>#include<stdio.h>
>#include<string.h>
>int numbers(char *p);
>#define SIZE 20
>int main()
>{
>    char str[SIZE];
>    int num;
>    //    printf("Please input a string.\n");
>    //    printf("The string can store %d character:",SIZE);
>    gets(str);
>    num = numbers(str);
>    printf("There are %d numbers in \"%s\"", num, str);
>    return 0;
>}
>```

<br>**Sample Input：**<br>
`0p9o8i7u66y`

<br>**Sample Output：**<br>
`There are 6 numbers in "0p9o8i7u66y"`

<br>

## 9-7 找最长的单词
**Description：**<br>
主函数传入字符串，单词之间以空格分隔，被调用函数中找出最长的单词，在主函数中输出此单词. 忽略单词中的非字母字符，单词长度相同的单词以最后一个作为输出单词。

<br>**Sample Input：**<br>
`my name is      davidzhang`
<br>**Sample Output：**<br>
`word=daividzhang`
<br>**Sample Input：**<br>
`here is 88sample`
<br>**Sample Output：**<br>
`word=sample`
<br>**Sample Input：**<br>
`ab cd ef`
<br>**Sample Output：**<br>
`word=ef`

<br>

## 9-8 字符串连接
**Description：**<br>
使用指针作为函数参数，编写函数strconnect，实现两个字符串的首尾连接。将字符串str2接到str1的后面，str1最后面的`\0`被取消）。
>**提示：**<br>
>程序的前缀代码已给出
>```
>前缀代码：
>
>#include <stdio.h>
>void strconnect(char *,char *);
>int main()
>{
>	char str1[100], str2[100];
>	scanf("%s", str1);
>	scanf("%s", str2);
>	strconnect(str1, str2);
>	printf("%s", str1);
>}
>```

<br>**Sample Input：**<br>
```
ILove
China
```

<br>**Sample Output：**<br>
`ILoveChina`

<br>

## 
**Description：**<br>
写一函数，实现两个字符串的比较，即自己写一个类似strcmp功能的函数。<br>
函数原型为：`int strcompare(char *p1, char *p2)`<br>
设p1指向字符串s1，p2指向字符串s2。要求：当s1=s2时，返回值为0。当s1不等于s2时，返回它们二者的第一个不同字符的ASCII码差值（如“BOY”与“BAD”，第二字母不同，“O”与“A”之差为79-65=14）；即如果s1>s2，则输出正值；如果s1<s2，则输出负值。

<br>**Sample Input：**<br>
```
BOY
BAD
```
<br>**Sample Output：**<br>
`14`
<br>**Sample Input：**<br>
```
CHINA
Chen
```
<br>**Sample Output：**<br>
`-32`

<br>

## 9-10 统计子串出现的次数
**Description：**<br>
编写一个函数，统计某个子串在一个字符串中出现的次数。
>要求:函数参数为指向字符串和要查找的子串的指针,返回值为该子串出现的次数
>**提示：**<br>
>程序的前缀代码已给出
>```
>前缀代码：
>
>#include <string.h>
>#include <stdio.h>
>int CountSubstr( char *s1, char *s2);
>
>int main()
>{
>	char s1[100], s2[100];
>	scanf("%s", s1);
>	scanf("%s", s2);
>	printf("%d", CountSubstr(s1, s2));
>}
>```

<br>**Sample Input：**<br>
```
goodgoodstudy
good
```

<br>**Sample Output：**<br>
`2`

<br>

## 9-11 帽子的大小
**Description：**<br>
用户想买一顶帽子，帽子太大，会遮挡视线。帽子太小，会导致箍紧头疼。编写一个程序，根据用户的头围（英寸），为用户推荐帽子的大小。<br>
<br>
在美国和英国，帽子的尺寸一般是6 1/2到7 7/8，其增量为1/8英寸。即帽子的尺寸有6 1/2，6 5/8，6 3/4，6 7/8....7 7/8共12个尺寸。这12个尺寸分别对应的头围是164，166，169，172，175，178，181，184，188，191，194，197. 单位为1/8英寸。即如果一个用户的头围是164的1/8英寸（约20.5英寸），那么帽子的尺寸是6 1/2。 如果一个用户的头围是197的1/8英寸，帽子的尺寸是7 7/8。<br>
<br>
如果用户的头围不在以上的数据中，则选取最接近的头围数。如果头围数比最接近的1/8英寸还小，则向下选取小一号的帽子。例如，如果头围数是171（21.375英寸），介于169和172之间，且171<172-1不成立，则帽子大小按照头围172计算，即6 7/8. 如果头围数是170，介于169和172之间，且170<172-1成立，则帽子大小按照小一号头围169计算，即6 3/4。 <br>
<br>
如果头围比最小的164还少，且小于1个1/8单位以内，如163，则按照头围164计算。如果头围比最小的164还少，且大于1个1/8单位，如162，150等，则输出如下语句：<br>
`printf("You are the proverbial pinhead. No hat for you I'm afraid.\n");`<br>
如果头围比最大的197还大，则输出如下语句：<br>
`printf("You, in technical parlance, are a fathead. No hat for you, I'm afraid.\n");`
>要求：<br>
>不能使用12个if语句或者switch分支语句完成。应该将帽子的12个尺寸以及帽子的12个参照头围存放在数组内<br>
>输入：<br>
>用户头围，单位是英寸。输入后头围＊8，再取整，即位头围的1/8单位英寸<br>
>输出：<br>
>帽子大小

<br>**Sample Input：**<br>
`18.5`
<br>**Sample Output：**<br>
`You are the proverbial pinhead. No hat foryou I'm afraid.`
<br>**Sample Input：**<br>
`20.375`
<br>**Sample Output：**<br>
`6 1/2`
<br>**Sample Input：**<br>
`23.375`
<br>**Sample Output：**<br>
`7 1/2`
<br>**Sample Input：**<br>
`22`
<br>**Sample Output：**<br>
`7`
<br>**Sample Input：**<br>
`25`
<br>**Sample Output：**<br>
`You, in technical parlance, are a fathead. No hat for you, I'm afraid.`

<br>

## 9-12 Tic Tac Toe游戏
**Description：**<br>
Tic Tac Toe，又称作三连棋游戏。游戏规则类似五子棋游戏。两人轮流在一有九格方盘上划加字或圆圈, 谁先把三个同一记号排成横线、直线、斜线, 即是胜者。<br>
用户的棋盘分别用1-9数值标识。两个玩家依次输入要下的位置，玩家1首先输入，用X表示，玩家2用字母O表示。如果玩家输入的数字是已经使用过，则需要重新输入。最后输出比赛结果。<br>
不分胜负则输出：`printf("How boring, it is a draw\n");`<br>
某玩家获胜：`printf("Congratulations, player %d, YOU ARE THE WINNER!\n", ...... );`

<br>**Sample Input：**<br>
```
5
7
6
3
4
```
<br>**Sample Output：**<br>
`Congratulations, player 1, YOU ARE THE WINNER!`
<br>**Sample Input：**<br>
```
1
3
6
9
7
6
5
8
4
2
```
<br>**Sample Output：**<br>
`How boring, it is a draw`
