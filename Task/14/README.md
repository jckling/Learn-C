# 目录
* [14-1 个税计算](#14-1-个税计算)
* [14-2 求π值](#14-2-求π值)
* [14-3 买糖果](#14-3-买糖果)
* [14-4 找合数](#14-4-找合数)
* [14-5 字符串中插入空格](#14-5-字符串中插入空格)
* [14-6 词典查找单词](#14-6-词典查找单词)
* [14-7 计算明天的日期](#14-7-计算明天的日期)
* [14-8 二维数组每一列的众数](#14-8-二维数组每一列的众数)
<br>

## 14-1 个税计算
**Description：**<br>
个人所得税是对个人（自然人）取得的各项所得征收的一种所得税。2016年我国个人所得税的计算方法如下：<br>
```
应纳税所得额 = 工资收入金额 － 各项社会保险费 － 起征点(3500元)
应纳税额 = 应纳税所得额 ＊ 税率 － 速算扣除数
```
个人所得税税率表如下所示：<br>
```
级数 	      应纳税所得额 	                             税率（％） 	速算扣除数
1 	 不超过1500元的(含1500元) 	                           3 	         0
2 	 超过1500元至4500元的部分(不含1500元,含4500元,下同) 	  10 	        105
3 	 超过4500元至9,000元的部分 	                          20 	        555
4 	 超过9,000元至35,000元的部分                          25 	        1005
5 	 超过35,000元至55,000元的部分 	                      30        	2775
6 	 超过55,000元至80,000元的部分 	                      35 	        5505
7 	 超过80,000的部分 	                                   45   	    13505
```
例如：<br>
张三在2016年一月份税前工资10000元，他需要缴纳各项社会保险金1100元，那么他的税后工资是多少呢？<br>
应纳税所得额==(应发工资－保险金)－3500 =10000 － 1100 － 3500 = 5400元，参照上面的工资税率表，超过4,500元至9,000元的部分，则适用税率20%，速算扣除数为555。<br>
缴费 = 应纳税所得额*税率 － 速算扣除数 = 5400*20% －555= 525元。<br>
实发工资=应发工资－保险金－缴税 = 10000 －1100－525 = 8375元<br>
编写程序，输入用户的税前工资和保险金数值，计算并输出应纳税所得额、适用税率、速算扣除数、应缴税款、实发工资。如果不需要纳税，则输出“您无须缴纳个人所得税”。<br>
>要求：<br>
>1）税前工资及保险金数值为整数，其中任意一个为负数，要求用户重新输入，直到输入正确为止<br>
>2）输出格式按照示例要求输出，其中小数点后保留2位小数，分号为英文输入法的分号<br>
>输出格式：`printf("应纳税所得额:%.2f\n适用税率:%d%%\n速算扣除数:%d\n应缴税款:%.2f\n实发工资:%.2f\n".......);`

<br>**Sample Input：**<br>
`3600 100`
<br>**Sample Output：**<br>
`您无须缴纳个人所得税`
<br>**Sample Input：**<br>
```
10000 -500
-8000 450
10000 1100
```
<br>**Sample Output：**<br>
```
应纳税所得额:5400.00
适用税率:20%
速算扣除数:555
应缴税款:525.00
实发工资:8375.00
```
<br>**Sample Input：**<br>
`106786 1456`
<br>**Sample Output：**<br>
```
应纳税所得额:101830.00
适用税率:45%
速算扣除数:13505
应缴税款:32318.50
实发工资:73011.50
```
<br>**Sample Input：**<br>
`9000 1000`
<br>**Sample Output：**<br>
```
应纳税所得额:4500.00
适用税率:10%
速算扣除数:105
应缴税款:345.00
实发工资:7655.00
```

<br>

## 14-2 求π值
**Description：**<br>
根据下面公式计算π值的近似值（double类型），直到最后一项的绝对值小于10-5。请输出一共计算了多少个有效项。小于10-5的项不计算在内。<br>
![relation](https://github.com/jckling/Learn-C/tree/master/Task/14/14-2.png)<br>
>**提示：**<br>
>求浮点数的绝对值可以使用fabs函数。头文件为<math.h>。函数原型为：`double fabs(double);`

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`一个整数`

<br>

## 14-3 买糖果
**Description：**<br>
假设你去超市购买糖果，一元钱可以购买一个糖果，每个糖果中有一张兑换券，用5张兑换券可以再兑换一个糖果。编写一个程序，输入你的钱数，输出用所有的钱及兑换券所能换得的糖果数和剩余的兑换券数。<br>
例如，如果你有30元。可以先买到30个糖果，这样就能得到30张兑换券，你可以用30张兑换券兑换得到6个糖果，6个糖果有6张兑换券，用其中的5张兑换券还可以兑换1个糖果，最终剩余2张兑换卷，最后，你共有37个糖果和2张兑换券。
>**提示：**<br>
>可利用除法和求余数运算，循环计算糖果数和兑换券数，直到兑换券小于5张

<br>**Sample Input：**<br>
`30`
<br>**Sample Output：**<br>
`37 2`
<br>**Sample Input：**<br>
`23`
<br>**Sample Output：**<br>
`28 3`

<br>

## 14-4 计算明天的日期
**Description：**<br>
编写一个程序，任意输入10个正整数，找出其中的合数（合数即为非素数，最小的合数是4），并将这些合数按由小到大顺序输出。如果输入数据中没有合数，则输出"No"。

<br>**Sample Input：**<br>
`10 9 21 7 5 4 11 35 2 100`
<br>**Sample Output：**<br>
`4 9 10 21 35 100`
<br>**Sample Input：**<br>
`23 17 2 19 29 37 13 11 5 7`
<br>**Sample Output：**<br>
`No`

<br>

## 14-5 字符串中插入空格
**Description：**<br>
编写程序，输入一行文本，用字符指针作函数参数实现在字符串每个字符间插入一个空格。最后一个字符之后也有一个空格。
>**提示：**<br>可能用到以下字符串处理函数：
>1）字符串拷贝函数。函数原型：char *strcpy(char * s1, const char *s2); 函数功能：将字符串s2复制到字符数组s1中，返回s1的值<br>
>2）求字符串长度函数。函数原型：int strlen(const char *s);函数功能：返回字符串结束符前面的字符的个数
>**主函数如下：**
>```
>#include<stdio.h>
>#include<string.h>
>
>void addSpace(char *);
>
>int main()
>{
>    char str[80];
>    gets(str);
>    addSpace(str);
>    puts(str);
>    return 0;
>}
>```

<br>**Sample Input：**<br>
`hello`
<br>**Sample Output：**<br>
`h e l l o `
<br>**Sample Input：**<br>
`This is a book!`
<br>**Sample Output：**<br>
`T h i s   i s   a   b o o k ! `

<br>

## 14-6 词典查找单词
**Description：**<br>
编写程序，根据词典内容进行单词查找。输入的单词不区分大小写。如果找到输出该单词在词典中的解释，反之提示没有找到该单词。<br>
已知词典的存储方式如下：
```
typedef struct Entry
{
    char word[15];       //单词
    char definition[50]; //单词的解释
}ENTRY;
```
>**提示：**<br>
>可编写一个子函数实现两个单词的比较
>**主函数如下：**
>```
>#include <stdio.h>
>#include <string.h>
>typedef struct Entry
>{
>    char word[15];       //单词
>    char definition[50]; //单词的解释
>}ENTRY;
>
>int lookup(ENTRY dictionary[],char search[],int entries);
>
>int main()
>{
>    ENTRY dictionary[100]=
>    { {"aardvark",  "a burrowing African mammal"  },
>      {"abyss",     "a bottomless pit"            },
>      {"acumen",    "mentally sharp;keen"         },
>      {"addle",     "to become confused"          },
>      {"affix",     "to append;attach"            },
>      {"ahoy",      "a nautical call of greeting" },
>      {"ajar",      "partically opened"           } };  //存储了7个单词及其解释
>    
>    char word[10];     //待查找单词
>    int entries = 7;   //词典实际存储单词和解释的数量
>    int entry;
>    
>    scanf("%14s",word);
>    
>    entry = lookup(dictionary,word,entries);
>    
>    if (entry!=-1) {
>        printf("%s\n",dictionary[entry].definition);
>    }
>    else
>        printf("Sorry,the word %s is not in my dictionary",word);
>    
>    return 0;
>    
>}
>```

<br>**Sample Input：**<br>
`abyss`
<br>**Sample Output：**<br>
`a bottomless pit`
<br>**Sample Input：**<br>
`aby`
<br>**Sample Output：**<br>
`Sorry,the word aby is not in my dictionary`
<br>**Sample Input：**<br>
`AjaR`
<br>**Sample Output：**<br>
`partically opened`

<br>

## 14-7 计算明天的日期
**Description：**<br>
编写一个程序，输入今天的日期，输出明天的日期。请注意闰年情况。

<br>**Sample Input：**<br>
`2 28 2016`
<br>**Sample Output：**<br>
`2 29 2016`
<br>**Sample Input：**<br>
`12 31 2016`
<br>**Sample Output：**<br>
`1 1 2017`
<br>**Sample Input：**<br>
`2 29 2016`
<br>**Sample Output：**<br>
`3 1 2016`

<br>

## 14-8 二维数组每一列的众数
**Description：**<br>
众数，是指一组数值中出现次数最多的那个数。编写一个程序，输入行数和列数，动态生成一个二维数组。然后通过键盘输入，给二维数组赋值，二维数组的每一个元素的取值范围在0-9之间。统计每一列的众数，并输出，输出以一个空格作为分隔。
>动态分配存储空间的函数原型为： 
>```
>    void *malloc(unsigned int num_bytes);
>    头文件：#include<stdlib.h>
>    功能：分配长度为num_bytes字节的内存块。
>    说明：如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。
>    当内存不再使用时，应使用free()函数将内存块释放
>```
>内存空间释放的函数原型：
>```
>    void free(void*ptr);
>    功能：释放ptr所指向的一块内存空间，ptr是一个任意类型的指针变量，它指向被释放区域的首地址,被释放区应是由malloc函数所分配
>```
>**提示：**<br>
>由于二维数组每个元素的取值范围为0-9，因此可以使用一个大小为10的数组存储每一个数值出现的次数<br>
>暂不处理两个数字出现次数相等的情况

<br>**Sample Input：**<br>
```
6 3
3 4 6
6 7 8
5 4 6
5 4 5
2 1 1
0 4 6
```
<br>**Sample Output：**<br>
`5 4 6 `
<br>**Sample Input：**<br>
```
10 10
5 8 9 9 2 0 3 1 5 5 
4 8 4 9 9 0 9 5 2 1 
6 2 4 9 0 2 4 8 0 2 
5 8 6 4 6 0 7 9 9 5 
6 9 3 5 2 5 9 8 3 4 
2 0 5 8 3 3 2 9 5 7 
4 3 8 7 7 5 3 1 4 7 
6 1 7 4 8 7 8 8 4 9 
3 4 2 7 2 3 3 0 1 8 
3 5 1 2 2 0 3 2 4 7
```
<br>**Sample Output：**<br>
`6 8 4 9 2 0 3 8 4 7`