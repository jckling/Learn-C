# 目录
* [实验8 肿瘤检测](#实验8-1-肿瘤检测)
* [8-1 求二维数组两对角线数之和](#8-1-求二维数组两对角线数之和)
* [8-2 验证身份证号码的有效性](#8-2-验证身份证号码的有效性)
* [8-3 字符串逆序连接](#8-3-字符串逆序连接)
* [8-4 一个班级一门课程成绩](#8-4-一个班级一门课程成绩)
* [8-5 判断回文](#8-5-判断回文)
* [8-6 根据数字输出英文](#8-6-根据数字输出英文)
* [8-7 字符串与整数转换](#8-7-字符串与整数转换)
* [8-8 多门课程考试统计](#8-8-多门课程考试统计)
* [8-9 字符串排序](#8-9-字符串排序)
* [8-10 统计字符串中单词的个数](#8-10-统计字符串中单词的个数)
* [8-11 Playfair密码的加密](#8-11-playfair密码的加密)
* [8-12 变位词](#8-12-变位词)

<br>

## 实验8 肿瘤检测
**Description：**<br>
一张CT扫描的灰度图像可以用一个N*N（0<N<100）的矩阵描述，矩阵上的每个点对应一个灰度值（整数），其取值范围是0-255。我们假设给定的图像中有且只有一个肿瘤。<br>
在图上监测肿瘤的方法如下：<br>
如果某个点对应的灰度值小于等于50，则这个点在肿瘤上，否则不在肿瘤上。我们把在肿瘤上的点的数目加起来，就得到了肿瘤在图上的面积。任何在肿瘤上的点，如果它是图像的边界或者它的上下左右四个相邻点中至少有一个是非肿瘤上的点，则该点称为肿瘤的边界点。肿瘤的边界点的个数称为肿瘤的周长。现在给定一个图像，要求计算其中的肿瘤的面积和周长。<br>
输入：<br>
输入第一行包含一个正整数N（0<N<100），表示图像的大小；接下来N行，每行包含图像的一行。图像的一行用N个整数表示（所有整数大于等于0，小于等于255），两个整数之间用一个空格隔开。<br>
输出：<br>
输出只有一行，该行包含两个正整数，分别为给定图像中肿瘤的面积和周长，用一个空格分开。

<br>**Sample Input：**<br>
```
6
99 99 99 99 99 99
99 99 99 50 99 99
99 99 49 49 50 51
99 50 20 25 52 99
40 50 99 99 99 99
99 99 99 99 99 99
```
<br>**Sample Output：**<br>
`9 8`

<br>

## 8-1 求二维数组两对角线数之和
**Description：**<br>
要求输入一个二维nxn数组(n<20)，求其两对角线数之和。
先输入一个整数n，
再输入 nxn个整数数组元素（空格分隔）
输出其两对角线数之和（注意中间的元素，只被计算一次）
>例如：<br>
>输入：
>```
>3
>1 2 3
>4 5 6
>7 8 9
>```
>输出：`25`<br>
>注意：对角线之和为1+5+9+3+7，请注意5不重复

<br>**Sample Input：**<br>
```
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
```

<br>**Sample Output：**<br>
`68`

<br>

## 8-2 验证身份证号码的有效性
**Description：**<br>
编写程序，通过计算身份证号码第十八位校验码，检查身份证是否有效。<br>
关于身份证第18是怎么计算的，原理如下：根据〖中华人民共和国国家标准 GB 11643-1999〗中有关公民身份号码的规定，公民身份号码是特征组合码，由十七位数字本体码和一位数字校验码组成。排列顺序从左至右依次为：六位数字地址码，八位数字出生日期码，三位数字顺序码和一位数字校验码。<br>
1）地址码（身份证前六位）表示编码对象常住户口所在县(市、旗、区)的行政区划代码<br>
2）生日期码（身份证第七位到第十四位）表示编码对象出生的年、月、日，其中年份用四位数字表示，年、月、日之间不用分隔符。例如：1981年05月11日就用19810511表示<br>
3）顺序码（身份证第十五位到十七位）为同一地址码所标识的区域范围内，对同年、月、日出生的人员编定的顺序号。其中第十七位奇数分给男性，偶数分给女性<br>
4）校验码（身份证最后一位）是根据前面十七位数字码，按照ISO 7064:1983.MOD 11-2校验码计算出来的检验码<br>
第十八位数字的计算方法为：<br>
1.将前面的身份证号码17位数分别乘以不同的系数。从第一位到第十七位的系数分别为：`7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2`<br>
2.将这17位数字和系数相乘的结果相加<br>
3.用加出来和除以11，看余数是多少？<br>
4.余数只可能有`0 1 2 3 4 5 6 7 8 9 10`这11个数字。其分别对应的最后一位身份证的号码为`1 0 X 9 8 7 6 5 4 3 2`<br>
5.通过上面得知如果余数是2，就会在身份证的第18位数字上出现罗马数字的Ⅹ。如果余数是10，身份证的最后一位号码就是2<br>
>例如：<br>
>某男性的身份证号码是34052419800101001X。我们要看看这个身份证是不是合法的身份证。<br>
>首先：我们得出，前17位的乘积和是189<br>
>然后：用189除以11得到的余数是2<br>
>最后：通过对应规则就可以知道余数2对应的数字是X。所以，这是一个合格的身份证号码<br>
>**提示：**<br>
>定义一个字符数组存储身份证号`char id[18];`

<br>**Sample Input：**<br>
`34052419800101001X`
<br>**Sample Output：**<br>
`yes`
<br>**Sample Input：**<br>
`340524198001010015`
<br>**Sample Output：**<br>
`no`

<br>

## 8-3 字符串逆序连接
**Description：**<br>
编写程序，实现如下功能。将字符串str中的字符正序和逆序进行连接，形成一个新串存放在字符串t中，如str字符串为ABCD，则t的内容为ABCDDCBA。假设字符串长度不超过20个字符。

<br>**Sample Input：**<br>
`abderte`

<br>**Sample Output：**<br>
`abderteetredba`

<br>

## 8-4 一个班级一门课程成绩
**Description：**<br>
从键盘输入一个班（全班最多不超过30人）学生某门课的成绩，当输入成绩为负值时，输入结束，分别统计下列内容：<br>
（1）统计不及格人数并打印不及格学生名单<br>
（2）统计成绩在全班平均分及平均分之上的学生人数并打印其学生名单<br>
（3）统计各分数段的学生人数及所占的百分比<br>
>要求：分别编写以下函数<br>
>a)
>```
>int ReadScore(long num[], float score[]);
>/*
>  函数功能：从键盘输入一个班学生某门课的成绩及其学号，当输入成绩为负值时，输入结束
>  函数参数： 长整型数组num，存放学生学号
>            实型数组score，存放学生成绩
>  函数返回值：学生总数
>*/
>```
>b)
>```
>int GetFail(long num[], float score[], int n);
>/*
>  函数功能：统计不及格人数并打印不及格学生名单
>  函数参数：长整型数组num，存放学生学号
>           实型数组score，存放学生成绩
>           整型变量n，存放学生总数
>  函数返回值：不及格人数
>*/
>```
>输出格式：
>`printf("Fail:\nnumber -- score\n");`<br>
>`printf("%4ld%12.2f\n",学号, 成绩);`<br>
><br>
>c)       
>```
>float GetAver(float score[], int n);
>/*
>  函数功能：计算全班平均分
>  函数参数：实型数组score，存放学生成绩
>           整型变量n，存放学生总数
>  函数返回值：平均分
>*/
>```
>d)
>```
>int GetAboveAver(long num[], float score[], int n);
>/*
>  函数功能：统计成绩在全班平均分及平均分之上的学生人数并打印其学生名单
>  函数参数：长整型数组num，存放学生学号
>           实型数组score，存放学生成绩
>           整型变量n，存放学生总数
>  函数返回值：成绩在全班平均分及平均分之上的学生人数
>*/
>```
>输出格式：<br>
>`printf("aver = %.2f\n", aver);` <br>
>`printf("Above aver:\nnumber -- score\n");`<br>
>`printf("%4ld%10.2f\n",学号, 成绩);`<br>
><br>
e)
>```
>void GetDetail(float score[], int n);
>/*
>  函数功能：统计各分数段的学生人数及所占的百分比
>  函数参数：实型数组score，存放学生成绩
>                        整型变量n，存放学生总数
>  函数返回值：无
>*/
>```
>输出格式：<br>
>`printf("score   number   percent\n");`<br>
>`printf("<60%8d%12.2f\n",数量，百分比); //成绩在60分以下`<br>
>`printf("%d--%d%5d%12.2f\n", 区间左值，区间右值，数量，百分比); //成绩在某个区间内，如60-70之间`<br>
>`printf("%d%8d%12.2f\n",100,数量，百分比);//成绩为100`<br>
>**主函数如下：**
>```
>#include  <stdio.h>
>#define ARR_SIZE 30
> 
>int    ReadScore(long num[], float score[]);
>int    GetFail(long num[], float score[], int n);
>float  GetAver(float score[], int n);
>int    GetAboveAver(long num[], float score[], int n);
>void   GetDetail(float score[], int n);
> 
>int main()
>{
>       int n, fail, aboveAver;
>       float score[ARR_SIZE];   //存储成绩
>       long num[ARR_SIZE];    //存储学号
> 
>       //在此添加语句调用ReadScore函数读入数据
>            
>       printf("Total students %d\n\n",n);
> 
>       //在此添加语句调用 GetFail函数
>           
>       printf("Fail students %d\n\n",fail);
> 
>       //在此添加语句调用 GetAboveAver函数             
>        
>       printf("Above aver students %d\n\n",aboveAver);
>       //在此添加语句调用  GetDetail函数     
> 
>       return 0;
>}
>```
>**提示：**<br>
>（1）用num[i]存放第i+1个学生的学号，用score[i]存放第i+1个学生的成绩。设置计数器count，当score[i]<60分时，计数器count计数一次，并打印num[i]和score[i]<br>
>（2）先计算全班平均分aver，当第i个学生的成绩score[i]>=aver时，打印num[i]和score[i]<br>
>（3）将成绩分为六个分数段，60分以下为第0段，60~69为第1段，70~79为第2段，80~89为第3段，90~99为第4段，100分为第5段。各分数段的学生人数保存在数组stu中，用stu[i]存放第i段的学生人数。对于每个学生的成绩，先计算出该成绩所对应的分数段，然后将相应的分数段的人数加1，即stu[i]++

<br>**Sample Input：**<br>
```
1 78
2 99
3 56
4 90
5 98
6 -1
```

<br>**Sample Output：**<br>
```
Total students 5
Fail:
number -- score
   3       56.00
Fail students 1
aver = 84.20
Above aver:
number -- score
   2     99.00
   4     90.00
   5     98.00
Above aver students 3
score   number   percent
<60       1       20.00
60--69    0        0.00
70--79    1       20.00
80--89    0        0.00
90--99    3       60.00
100       0        0.00
```

<br>

## 8-5 判断回文
**Description：**<br>
编写一个函数，检查一个字符串是否是回文。主函数输入一个字符串（设不超过80个字符），输出该字符串是否是回文的信息。回文是指一个字符串顺读和倒读都一样，如ABCBA,aaaa等是回文，china,ABC就不是回文。

<br>**Sample Input：**<br>
`abccccba`
<br>**Sample Output：**<br>
`yes`
<br>**Sample Input：**<br>
`abccccb`
<br>**Sample Output：**<br>
`no`

<br>

## 8-6 根据数字输出英文
**Description：**<br>
输入一个数 （100以内），输出它的英文（首字母大写，有连接线）。

<br>**Sample Input：**<br>
`99`
<br>**Sample Output：**<br>
`Ninety-nine`
<br>**Sample Input：**<br>
`90`
<br>**Sample Output：**<br>
`Ninety`
<br>**Sample Input：**<br>
`19`
<br>**Sample Output：**<br>
`Nineteen`
<br>**Sample Input：**<br>
`1`
<br>**Sample Output：**<br>
`One`
<br>**Sample Input：**<br>
`0`
<br>**Sample Output：**<br>
`Zero`

<br>

## 8-7 字符串与整数转换
**Description：**<br>
在职工工资表中某列用来存放职工补贴或扣除的奖金，在对职工工资进行计算时，发现本列的数据是以字符串的形式输入的。现要求编写函数，将字符串改为对应的数值型数据。<br>
函数原型为：`int convertToInt(char num[30])`
>**提示：**<br>
>首先需要判断数据的正负，注意num[i]是一个字符，要将其转换为相应的数字必须令其减去字符’0’，如’8’-‘0’=8，然后将各个位数组合成相应的整数<br>
>**主函数如下：**
>```
>#include<stdio.h>
>#include<string.h>
>int convertToInt(char num[30]);
>int main()
>{
>       char num[30];
>       gets(num);
>       printf("%d", convertToInt(num));
>       return 0;
>}
>```

<br>**Sample Input：**<br>
`+1578`
<br>**Sample Output：**<br>
`1578`
<br>**Sample Input：**<br>
`-180`
<br>**Sample Output：**<br>
`-180`
<br>**Sample Input：**<br>
`6700`
<br>**Sample Output：**<br>
`6700`

<br>

## 8-8 多门课程考试统计
**Description：**<br>
某班期末考试科目为数学(MT)、英语(EN)和物理(PH)，有最多不超过30人参加考试。考试后要求：<br>
（1）计算每个学生的总分和平均分<br>
（2）按总分成绩由高到低排出成绩的名次<br>
（3）打印出名次表，表格内包括学生编号、各科分数、总分和平均分
>要求：分别定义以下函数实现<br>
>a)
>```
>void Input(long num[], int score[][COURSE], int n);
>/* 
>  函数功能：输入某班学生期末考试三门课程成绩
>  函数参数：长整型数组num，存放学生学号
>           整型数组score，存放学生成绩
>           整型变量n，存放学生人数
>  函数返回值：无
>*/
>```
>b)
>```
>void GetSumAver(int score[][COURSE], int n, int sum[], float aver[]);
>/* 
>  函数功能：计算每个学生的总分和平均分
>  函数参数：整型数组score，存放学生成绩
>           整型变量n，存放学生人数
>           整型数组sum，计算得到的每个学生的总分
>           实型数组aver，计算得到的每个学生的平均分
>  函数返回值：无
>*/
>```
>c)
>```
>void Sort(long num[], int score[][COURSE], int n, int sum[], float aver[]);
>/* 
>  函数功能：按总分成绩由高到低排出成绩的名次
>  函数参数：长整型数组num，存放学生学号
>           整型数组score，存放学生成绩
>           整型变量n，存放学生人数
>           整型数组sum，存放每个学生的总分
>           实型数组aver，存放每个学生的平均分
>   函数返回值：无
>*/
>```
>d)
>```
>void Print(long num[], int score[][COURSE], int n, int sum[], float aver[]);
>/* 
>  函数功能：打印名次表，表格内包括学生编号、各科分数、总分和平均分
>  函数参数：长整型数组num，存放学生学号
>           整型数组score，存放学生成绩
>           整型变量n，存放学生人数
>           整型数组sum，存放每个学生的总分
>           实型数组aver，存放每个学生的平均分
>  函数返回值：无
>*/
>```
>输出格式：<br>
>`printf("  NO \t   MT \t  EN \t PH \t SUM \t AVER\n");`<br>
>`printf("----------------------------------------------------\n");`<br>
>`printf("%ld\t",num[i]); //输出学号`<br>
>`printf("%4d\t",score[i][j]); //输出成绩`<br>
>`printf("%4d\t%.2f\n",sum[i],aver[i]); //输出总分及平均值`<br>
><br>
>**主函数如下：**
>```
>#include  <stdio.h>
>#define STU 30
>#define COURSE 3
>void Input(long num[], int score[][COURSE], int n);
>void GetSumAver(int score[][COURSE], int n, int sum[], float aver[]);
>void Sort(long num[], int score[][COURSE], int n, int sum[], float aver[]);
>void Print(long num[], int score[][COURSE], int n, int sum[], float aver[]);
>int  Search(long num[], int n, long x);
>int main()
>{
>    int n, score[STU][COURSE], sum[STU], pos;
>    long num[STU], x;
>    float aver[STU];
>    
>    scanf("%d",&n); /*输入参加考试的学生人数*/
>    Input(num, score, n); /*输入学生成绩*/
>    
>    GetSumAver(score, n, sum, aver); /*计算总分和平均分*/
>    printf("Before sort:\n");
>    Print(num, score, n, sum, aver);
>    
>    Sort(num, score, n, sum, aver); /*排名次*/
>    printf("After sort:\n");
>    Print(num, score, n, sum, aver);
>    return 0;
>}
>```

<br>**Sample Input：**<br>
```
5
1 89 90 78
2 100 90 99
3 70 74 60
4 56 55 30
5 88 89 98
```

<br>**Sample Output：**<br>
```
Before sort:
  NO    MT   EN  PH  SUM  AVER
----------------------------------------------------
1   89   90   78 257 85.67
2 100   90   99 289 96.33
3   70   74   60 204 68.00
4   56   55   30 141 47.00
5   88   89   98 275 91.67
After sort:
  NO    MT   EN  PH  SUM  AVER
----------------------------------------------------
2 100   90   99 289 96.33
5   88   89   98 275 91.67
1   89   90   78 257 85.67
3   70   74   60 204 68.00
4   56   55   30 141 47.00
```

<br>

## 8-9 字符串排序
**Description：**<br>
输入6个字符串（每个字符串不超过80个字符），然后按照升序（即按照字符串第一个字母的ASCII值）排序后输出。
>要求：合理划分函数完成

<br>**Sample Input：**<br>
```
I
like
programming.
what
about
you?
```

<br>**Sample Output：**<br>
```
I
about
like
programming.
what
you?
```

<br>

## 8-10 统计字符串中单词的个数
**Description：**<br>
输入一行由字母和空格组成的字符串（不超过1024个字符），统计该字符串中单词的个数。设单词之间用一个或多个空格分隔，但第一个单词之前和最后一个单词之后可能也有空格。
>要求：合理划分函数完成

<br>**Sample Input：**<br>
`I   like   programming. what about      you?`
<br>**Sample Output：**<br>
`6`
<br>**Sample Input：**<br>
`    I   like   programming.   `
<br>**Sample Output：**<br>
`3`

<br>

## 8-11 Playfair密码的加密
**Description：**<br>
Playfair密码（英文：Playfair cipher 或 Playfair square）是一种替换密码，1854年由查尔斯·惠斯通（Charles Wheatstone）的英国人发明。在1854到1855年的克里米亚战争和1899年的布尔战争中有广泛应用。但在1915年的一战中被破译了。这个密码的特点适合手工计算，没有设备的帮助就可以用笔实现加密和解密，且破解困难。<br>
>本题输入输出要求如下，输入两行字符串（小于100个字符），输出一行字符串：<br>
>输入两行字符串：<br>
>输入一行字符串作为密钥，再输入一行明文字母作为明文<br>
>输出：<br>
>用playfair算法加密后的密文<br>
>注意：全部小写字母，不必考虑大写字母情况
>![relation](https://github.com/jckling/Learn-C/tree/master/Task/8/8-11.png)

<br>**Sample Input：**<br>
```
playfirexm
helloworld
```

<br>**Sample Output：**<br>
`dmyranvqcrge`

<br>

## 8-12 变位词
**Description：**<br>
编写程序，测试两个单词是否为变位词。如果两个单词的组成字母完全相同，只是字母的排列顺序不一样，不考虑大小写（即大小写视为相同字符），则它们就是变位词，两个单词相同也被认为是变位词。如tea 与eat , nic 与cin, ddc与dcd, abc与abc 等。<br>
输入单词以回车键分割，如果是变位词，输出'y'，不是变位词，输出'n'<br>
>注意：忽略输入中的非字母字符，即仅考虑两个单词的字符是否完全相同。可以使用isalpha函数判断是否为字母，函数使用方法自行google

<br>**Sample Input：**<br>
```
smartest
mattress
```
<br>**Sample Output：**<br>
`y`
<br>**Sample Input：**<br>
```
a+b+c-d
dbAc
```
<br>**Sample Output：**<br>
`y`
<br>**Sample Input：**<br>
```
abc     ddf
fddcba
```
<br>**Sample Output：**<br>
`y`