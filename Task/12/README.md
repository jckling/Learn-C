# 目录
* [12-1 最高分成绩](#12-1-最高分成绩)
* [12-2 平均成绩](#12-2-平均成绩)
* [12-3 统计得票数](#12-3-统计得票数)
* [12-4 成绩排序](#12-4-成绩排序)
* [12-5 计算两个时间点的时长](#12-5-计算两个时间点的时长)
* [12-6 查询员工生日](#12-6-查询员工生日)
* [12-7 交易管理](#12-7-交易管理)
* [12-8 左移整数](#12-8-左移整数)
* [12-9 字符封装到整数中](#12-9-字符封装到整数中)
* [12-10 将字符从整数中解析出来](#12-10-将字符从整数中解析出来)
* [12-11 将一个整数的二进制位颠倒过来](#12-11-将一个整数的二进制位颠倒过来)

<br>

## 12-1 最高分成绩
**Description：**<br>
建立一结构体，其中包括学生的姓名、性别、年龄和一门课程的成绩。建立的结构体数组通过输入存放全班（最多45人）学生信息，输入班级人数，以及每个学生的姓名，性别，年龄，成绩（以回车分隔），输出考分最高的学生的姓名、年龄、性别和课程的成绩。

>**提示：**<br>
>1）请使用getchar()读出多余的回车<br>
>2）输出格式：<br>
>`printf("\nName\t\tSex\tAge\tScore\n");`<br>
>`printf("%s\t\t%c\t%d\t%5.1f\n", ......);`<br>
>3）清除输入缓冲区的方法：
>```
>char ch;
>while ((ch = getchar()) != '\n' && ch != EOF);
>```

<br>**Sample Input：**<br>
```
3
zhang san
m
18
89.9
li si
m
17
90.8
wang wu
f
18
99
```

<br>**Sample Output：**<br>
```
Name Sex Age Score
wang wu f 18 99.0
```

<br>

## 12-2 平均成绩
**Description：**<br>
已知一个班有45人，本学期有两门课程的成绩，输入学生人数，及学生姓名、学号、两门课程成绩，求：
1）所有课程中的最高成绩，以及对应的姓名、学号和课程编号
2）求出两门课程都低于各自平均成绩的学生姓名和学号，若没有找到，则输出`Not Found`
>要求：
>定义结构体，第一成员项为学生姓名，第二成员项为学号，另外两个成员项为两门课程成绩。1）2）分别用函数完成<br>
>**提示：**<br>
>必要时，请使用`getchar();` 读出上一个数据输入后的回车<br>
>最高分输出格式：<br>
>`printf("MaxSore=%5.1f,Name is %s,No=%ld,Score.No=%d\n",......);`<br>
>低于平均成绩的学生信息输出格式：<br>
>`printf("Below average:\n");`<br>
>`printf("%s\t\t%ld\n",......);`<br>
>程序的前缀代码已给出
>```
>#include <stdio.h>
>struct student
>{
>    char name[10];
>    int no;
>    float score[2];
>};
>void maxscore(struct student *pst,int n);
>void average(struct student *pst,int n);
>```

<br>**Sample Input：**<br>
```
3
zhang san
1000
78.9
80
lisi
1006
98.9
99
wangwu
1030
45
60
```
<br>**Sample Output：**<br>
```
MaxSore= 99.0,Name is lisi,No=1006,Score.No=2
Below average:
wangwu 1030
```
<br>**Sample Input：**<br>
```
1
lili
1000
78
89
```
<br>**Sample Output：**<br>
```
MaxSore= 89.0,Name is lili,No=1000,Score.No=2
Below average:
Not Found
```

<br>

## 12-3 统计得票数
**Description：**<br>
编写一个程序，为某次投票统计得票情况。候选人共3人，分别为li，zhang，wang。共有10人参与投票。请统计每人的得票分数。名字不区分大小写。非以上三人为无效票。
>输入：10个人的投票<br>
>输出格式：<br>
>`printf("%s:%d\n",......);`
<br>**Sample Input：**<br>
```
wang
WANg
zhang
li
Li
zhang
sun
wang
LI
Wan
```

<br>**Sample Output：**<br>
```
li:3
zhang:2
wang:3
```

<br>

## 12-4 成绩排序
**Description：**<br>
基于12-2，已知一个班有45人，本学期有两门课程的成绩，输入学生人数，及学生姓名、学号、两门课程成绩，对编号1的课程从高分到低分排序。（注意其他成员项应保持对应关系）
>要求：<br>
>定义结构体，第一成员项为学生姓名，第二成员项为学号，另外两个成员项为两门课程成绩。用函数完成。<br>
>**提示：**<br>
>必要时，请使用`getchar();` 读出上一个数据输入后的回车<br>
>输出格式：<br>
>`printf("\nName\t\tNo\tScore1\tScore2\n");`<br>
>`printf("%s\t\t%d\t%5.1f\t%5.1f\n",......);`<br>
>程序的前缀代码已给出
>```
>#include <stdio.h>
>struct student
>{
>    char name[10];
>    int no;
>    float score[2];
>};
>void sort(struct student *pst, int n);
>```

<br>**Sample Input：**<br>
```
3
zhang san
1000
78.9
80
lisi
1006
98.9
99
wangwu
1030
45
60
```

<br>**Sample Output：**<br>
```
Name No Score1 Score2
lisi 1006 98.9 99.0
zhang san 1000 78.9 80.0
wangwu 1030 45.0 60.0
```

<br>

## 12-5 计算两个时间点的时长
**Description：**<br>
编写一个函数，以两个time结构体（用小时、分、秒表示）为参数，并返回一个time结构体。用于表示两个时间点之间的时长。然后，编写一个主函数，输入两个时间点，输出两个时间点之间的时长。注意处理跨午夜的情况。
>输入：两个时间点，以空格分隔
>输出格式：<br>
>`printf ("Time between %.2d:%.2d:%.2d and %.2d:%.2d:%.2d is %.2d:%.2d:%.2d\n",......);`

<br>**Sample Input：**<br>
`3 45 15 9 44 3`

<br>**Sample Output：**<br>
`Time between 03:45:15 and 09:44:03 is 05:58:48`

<br>

## 12-6 查询员工生日
**Description：**<br>
某企业有为员工祝贺生日的传统，但随着企业规模的扩大，员工人数的增多，该企业希望运用信息化技术，保存本企业所有员工的生日信息，查找指定日期过生日的员工，试编写一个程序，输入员工总数，员工的姓名、工号、出生日期以及待查询日期，根据员工的出生月、日，查找过生日的员工。若没找到，输出`Not Found`。
>要求：<br>
>1、设该企业最多有员工100人，员工的信息包括姓名、工号、出生日期（年、月、日），要求使用结构体嵌套方式定义数据结构<br>
>2、要求使用typedef对结构体进行重命名<br>
>3、要求划分合理函数完成。查找函数原型为：`void Input(Employee *p,int n);  //n为员工总数，p为指向结构体数组的指针。`<br>
>输出格式：<br>
>`printf("%d月%d日过生日的有：\n",...... );`<br>
>`printf("       姓名    工号    生日(年   月   日)\n");`<br>
>`printf("%8s%10d%14d%4d%4d\n",.......);`

<br>**Sample Input：**<br>
```
4
zhang 1001 1987 5 7
wang 1002 1998 5 7
sun 1003 1990 4 5
wanghi 1004 2000 10 10
5 7
```
<br>**Sample Output：**<br>
```
5月7日过生日的有：
       姓名    工号    生日(年   月   日)
   zhang      1001          1987   5   7
    wang      1002          1998   5   7
```
<br>**Sample Input：**<br>
```
4
zhang 1001 1987 5 7
wang 1002 1998 5 7
sun 1003 1990 4 5
wanghi 1004 2000 10 10
5 8
```
<br>**Sample Output：**<br>
`Not Found`

<br>

## 12-7 交易管理
**Description：**<br>
[Details](https://github.com/jckling/Learn-C/tree/master/Task/12/实验12-结构体.doc)

<br>

## 12-8 左移整数
**Description：**<br>
无符号数左移一位相当于将该数乘以2。请编写一个函数power2，该函数接收两个整形变量number和pow作为实参，使用移位运算符计算number＊2^pow的结果，并以整型和二进制位的形式输出结果。
>输出格式：<br>
>`printf( "number:\n" );`<br>
>`printf( "\npow:\n" );`<br>
>`printf( "\n%u * 2^%u = %u\n", ......);`

<br>**Sample Input：**<br>
`5 2`
<br>**Sample Output：**<br>
```
number:
         5 = 00000000 00000101 

pow:
         2 = 00000000 00000010 

5 * 2^2 = 20
        20 = 00000000 00010100 
```

<br>

## 12-9 字符封装到整数中
**Description：**<br>
左移运算可以将两个字符值封装到一个无符号整数变量中。请编写一个程序，从键盘读入两个字符（以空格分隔），然后将其传递给函数packCharacters。为了将两个字符封装到一个无符号整数中，首先将第一个字符赋值给该无符号整数变量，然后将该变量向左移8位，再用按位或运算符将该变量和第二个字符整合在一起。该程序将按二进制位格式输出封装前和封装后的两字符，以验证它们被正确地封装到无符号整型变量中。
>输出格式：
>`printf( "\n\'%c\' in bits as an unsigned integers is:\n",..);`
>`printf( "\n\'%c\' and \'%c\' packed in an unsigned integer:\n",..);`

<br>**Sample Input：**<br>
`a A`

<br>**Sample Output：**<br>
```
'a' in bits as an unsigned integers is:
        97 = 00000000 01100001 

'A' in bits as an unsigned integers is:
        65 = 00000000 01000001 

'a' and 'A' packed in an unsigned integer:
     24897 = 01100001 01000001 
```

<br>

## 12-10 将字符从整数中解析出来
**Description：**<br>
请使用右移运算符、按位与运算符和一个掩码来编写函数unpackCharacters，该函数将从无符号整数中解析出两个字符。为了从一个无符号整数中解析出两个字符，首先使用取位与运算符将无符号数与掩码65280（00000000 00000000 11111111 00000000）整合在一起，右移结果8位，得到的结果赋值给一个字符变量；然后将无符号数与掩码255（00000000 00000000 00000000 11111111）整合在一起，得到的结果赋值给另一个字符变量。该程序以二进制位的格式打印分解前的无符号整数，再以二进制位的格式打印（displayBits函数）得到的两字符，以验证它们被正确分解。
>输出格式：<br>
>`printf( "\nThe unpacked characters are \'%c\' and \'%c\'\n",......);`

<br>**Sample Input：**<br>
`16706`

<br>**Sample Output：**<br>
```
     16706 = 01000001 01000010 

The unpacked characters are 'A' and 'B'
        65 = 00000000 01000001 
        66 = 00000000 01000010 
```

<br>

## 12-11 将一个整数的二进制位颠倒过来
**Description：**<br>
请编写一个程序，颠倒一个无符号整数的二进制位的顺序。该程序请用户输入一个整数值，然后调用reverseBits来打印其反序的二进制位。按二进制格式打印该整数颠倒处理前后的值，以验证数位已被正确的颠倒了。
>**提示：**<br>
>可用&运算将一个数的最低一个bit求出来，存放到temp变量中。然后将原数据右移1位，以使得倒数第二位变为最后一位，原来的temp变量左移1位，将新得到的倒数第二位放在temp的最后一位中。依次重复以上过程。

<br>**Sample Input：**<br>
`35467`

<br>**Sample Output：**<br>
```
Before bits are reversed:
     35467 = 10001010 10001011 

After bits are reversed:
     53585 = 11010001 01010001 
```