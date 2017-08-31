# 目录
* [10-1 输出字符串中部分字符](#10-1-输出字符串中部分字符)
* [10-2 删除指定字符](#10-2-删除指定字符)
* [10-3 求最高分及学号](#10-3-求最高分及学号)
* [10-4 二维数组元素最大值及其下标](#10-4-二维数组元素最大值及其下标)
* [10-5 月份对应英文](#10-5-月份对应英文)
* [10-6 求积分](#10-6-求积分)
* [10-7 求n个质数](#10-7-求n个质数)
* [10-8 求n以内的质数](#10-8-求n以内的质数)
* [10-9 温度统计](#10-9-温度统计)
* [10-10 24点游戏](#10-10-24点游戏)

<br>

## 10-1 输出字符串中部分字符
**Description：**<br>
编写函数printstring，通过指针操作，输出该数组中第n个字符之后的m个字符。编写主函数测试这个函数。n与m的值在主函数中输入。同时需要判定n和m值的合法性。n和m的值要大于0且，n＋m的长度不能超过字符串本身的长度。<br>
函数printstring的原型如下：<br>
`void printstring(char *p, int n, int m);`
>**提示：**<br>
>m,n值不合法要循环输入，直到数值合法

<br>**Sample Input：**<br>
```
abcdefg
3 2
```
<br>**Sample Output：**<br>
`de`
<br>**Sample Input：**<br>
```
abcdefg
1 0                    
3 8
-2 5
4 1
```
<br>**Sample Output：**<br>
`e`

<br>

## 10-2 删除指定字符
**Description：**<br>
编写函数deletechar，通过指针操作，将一个字符串中的指定字符删除。
>**主函数如下：**
>```
>#include<stdio.h>
>#include<string.h>
>void deletechar(char *p,char c);
>#define SIZE 20
>int main()
>{
>    char str[SIZE];
>    char c;
>    //    printf("Please input a string.\n");
>    //    printf("The string can store %d character:",SIZE);
>    gets(str);
>    //    printf("Please input the character you want delete:");
>    scanf("%c", &c);
>    deletechar(str, c);
>    //    printf("After deleting,The string is %s\n",str);
>    puts(str);
>    return 0;
>}
>```

<br>**Sample Input：**<br>
```
I am a girl
m
```
<br>**Sample Output：**<br>
`I a a girl`
<br>**Sample Input：**<br>
```
I am a girl
a
```
<br>**Sample Output：**<br>
`I m  girl`

<br>

## 10-3 求最高分及学号
**Description：**<br>
假设每班人数最多不超过40人，具体人数由键盘输入，用一维数组和指针变量作函数参数，编程打印某班一门课成绩的最高分和学号。<br>
>函数原型如下：<br>
>`int FindMax(int score[], long num[], int n, long *pMaxNum); `<br>
>函数功能：计算最高分及最高分学生的学号<br>
>函数参数：整型数组score，存放学生的成绩<br>
>         长整型数组num，存放学生的学号<br>
>         长整型指针变量pMaxNum，存放求出来的最高分学生的学号<br>
>函数返回值：最高分<br>
>
>**主函数如下：**
>```
>#include <stdio.h>
>#define ARR_SIZE 40
>
>int FindMax(int score[], long num[], int n, long *pMaxNum);
>
>int main()
>{
>    int score[ARR_SIZE], maxScore, n, i;
>    long num[ARR_SIZE], maxNum;
>    
>    //    printf("Please enter total number:");
>    scanf("%d", &n);		/*从键盘输入学生人数n*/
>    
>    //    printf("Please enter the number and score:\n");
>    for(i = 0; i < n; i++)		/*分别以长整型和整型格式输入学生的学号和成绩*/
>    {
>        scanf("%ld%d", &num[i], &score[i]);
>    }
>    
>    maxScore = FindMax(score, num, n, &maxNum);  /*计算最高分及学生学号*/
>    
>    printf("maxScore = %d, maxNum =%ld", maxScore, maxNum);
>    
>    return 0;
>}
>```

<br>**Sample Input：**<br>
```
5
1001 88
1002 90
1003 56
1004 100
1005 88
```

<br>**Sample Output：**<br>
`maxScore = 100, maxNum =1004`

<br>

## 10-4 二维数组元素最大值及其下标
**Description：**<br>
用指向二维数组第0行第0列元素的指针作函数参数，编写一个能计算任意m行n列的二维数组中的最大值，并指出其所在的行列下标值的函数FindMax，利用该函数计算3个班学生（假设每班4个学生）的某门课成绩的最高分，并指出具有该最高分成绩的学生是第几个班的第几个学生。
>函数原型如下：<br>
>`int FindMax(int *p, int m, int n, int *pRow, int *pCol);`<br>
>函数功能：计算任意m行n列的二维数组中元素的最大值，并指出其所在的行列下标值<br>
>函数入口参数：整型指针变量p，指向一个二维整型数组的第行第列<br>
>整型变量m，二维整型数组的行数<br>
>整型变量n，二维整型数组的列数<br>
>函数出口参数：整型指针变量pRow，指向数组元素最大值所在的行<br>
>整型指针变量pCol，指向数组元素最大值所在的列<br>
>函数返回值：数组元素的最大值
>
>**主函数如下：**
>```
>#include <stdio.h>
>
>#define CLASS 3
>#define STU 4
>
>int FindMax(int *p, int m, int n, int *pRow, int *pCol);
>int main()
>{
>    int score[CLASS][STU], i, j, maxScore, row, col;
>    //    printf("Please enter score:\n");
>    for (i = 0; i < CLASS; i++)
>    {
>        for (j = 0; j < STU; j++)
>        {
>            scanf("%d", &score[i][j]);     /*输入学生成绩*/
>        }
>    }
>    
>    /*计算最高分及其学生所在班号和学号*/
>    maxScore = FindMax(*score, CLASS, STU, &row, &col);
>    
>    printf("maxScore = %d, class =%d, number =%d\n", maxScore, row + 1, col + 1);
>}
>```

<br>**Sample Input：**<br>
```
88 98 100 76
56 66 88 45
67 78 88 98
```

<br>**Sample Output：**<br>
`maxScore = 100, class =1, number =3`

<br>

## 10-5 月份对应英文
**Description：**<br>
用指针数组编程实现：从键盘任意输入一个数字表示月份值n，程序输出该月份的英文表示，月份首字母大写。若n不在1～12之间，则输出“Illegal month”。
>注意：要求用指针数组存储月份的英文表示，不允许使用switch语句。

<br>**Sample Input：**<br>
`8`
<br>**Sample Output：**<br>
`August`
<br>**Sample Input：**<br>
`13`
<br>**Sample Output：**<br>
`Illegal month`

<br>

## 10-6 求积分
**Description：**<br>
编写一个函数calc(f, a, b)，用梯形公式求函数f(x)在[a, b]上的数值积分。然后调用该函数计算下列数值积分。（函数指针作为函数参数示例）![relation](https://github.com/jckling/Learn-C/tree/master/Task/10/10-6-1.png)<br>
分析：calc()是一个通用函数，用梯形公式求解数值积分。函数f(x)在区间[a,b]上计算梯形法数值积分的表达式为：
![relation](https://github.com/jckling/Learn-C/tree/master/Task/10/10-6-2.png)<br>
它和被积函数f(x)以及积分区间[a, b]有关，相应的形参包括函数指针funp、积分区间上下限参数a和b。在函数调用时，把被积函数的名称（或函数指针）和积分区间的上下限作为实参。即cal的函数原型如下：<br>
`double calc(double (*funp)(double), double a, double b);`

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`在两行中输出两个积分计算的数值，小数点后保留4位小数`

<br>

## 10-7 求n个质数
**Description：**<br>
编写一个程序，输入一个数字n(n>=4)，输出n个质数。如果输入个数少于4，则输出4个质数。
>**提示：**<br>
>根据数字n，使用动态内存分配<br>
>质数是只能被1和这个数本身整除的整数<br>
>输出格式：`printf ("%8lu",....);`每5个数据占一行

<br>**Sample Input：**<br>
`33`

<br>**Sample Output：**<br>
```
       2       3       5       7      11
      13      17      19      23      29
      31      37      41      43      47
      53      59      61      67      71
      73      79      83      89      97
     101     103     107     109     113
     127     131     137
```

<br>

## 10-8 求n以内的质数
**Description：**<br>
编写一个程序，输入一个数字n，输出n以内的所有质数。
>**提示：**<br>
>可先使用calloc分配若干个内存，如SIZE＝10，每找到1个质数，则统计数加1，当10个空间全部都使用后，使用realloc扩展动态分配的内存，如每次扩展10个。原来的空间需要释放<br>
>质数是只能被1和这个数本身整除的整数<br>
>输出格式：`printf ("%8lu",....);`每5个数据占一行<br>

<br>**Sample Input：**<br>
`137`

<br>**Sample Output：**<br>
```
       2       3       5       7      11
      13      17      19      23      29
      31      37      41      43      47
      53      59      61      67      71
      73      79      83      89      97
     101     103     107     109     113
     127     131     137
```
<br>

## 10-9 温度统计
**Description：**<br>
编写一个程序，读入任意天数的浮点温度纪录值，每天有6个记录。温度记录存储在动态分配内存的数组中，数组的大小刚好等于输入的温度值的个数。计算出每天的平均温度，然后输出每天的记录以及该天的平均温度，平均值精确到小树点后1位。用户输入y/n以决定是否输入新的一天温度值。
>**提示：**<br>
>此题可定义指向指针的指针，即二级指针，用来存储一个动态分配的指针数组的起始地址<br>
>输出格式：`printf("%10.1lf",......);`

<br>**Sample Input：**<br>
```
24.67 25.66 27 30 32.4 30
y
18.4 13.5 12.5 20 22 23.45
y
34.5 33.6 36 35.5 33 35
n
```

<br>**Sample Output：**<br>
```
      24.7      25.7      27.0      30.0      32.4      30.0      28.3

      18.4      13.5      12.5      20.0      22.0      23.4      18.3

      34.5      33.6      36.0      35.5      33.0      35.0      34.6
```

<br>

## 10-10 24点游戏
**Description：**<br>
拿一副扑克牌，留下1～10这40张牌(A为1)。任意抽取4张牌，用加、减、乘、除(可加括号)把牌面上的数算成24。每张牌必须且只能用一次。<br>
如3、8、8、9，算式(9-8)×8×3=24。<br>
输入4个整数，能否用加、减、乘、除(可加括号)把这4个数算成24。如果能输出y，否则输出n。<br>

<br>**Sample Input：**<br>
`3 8 8 9`
<br>**Sample Output：**<br>
`y`
<br>**Sample Input：**<br>
`3 4 6 7`
<br>**Sample Output：**<br>
`n`