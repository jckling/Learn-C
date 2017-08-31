# 目录
* [7-1 输入10个数，找出其中绝对值最小的数](#7-1-输入10个数，找出其中绝对值最小的数)
* [7-2 统计高于平均数的个数](#7-2-统计高于平均数的个数)
* [7-3 选手打分](#7-3-选手打分)
* [7-4 修改冒泡排序法](#7-4-修改冒泡排序法)
* [7-5 逆序字符](#7-5-逆序字符)
* [7-6 更高效的冒泡排序](#7-6-更高效的冒泡排序)
* [7-7 去除重复数](#7-7-去除重复数)
* [7-8 判断两个正整数集合是否相等](#7-8-判断两个正整数集合是否相等)

<br>

## 7-1 输入10个数，找出其中绝对值最小的数
**Description：**<br>
输入10个数，找出其中绝对值最小的数。
>**提示：**<br>
>绝对值函数：<br>
>整型   abs（）<br>
>浮点型   fabs()

<br>**Sample Input：**<br>
`-10 -2 30 40 50 60 70 80 -90 100`

<br>**Sample Output：**<br>
`-2`

<br>

## 7-2 统计高于平均数的个数
**Description：**<br>
从键盘输入10个数字，计算平均数，并统计多少个数大于平均数。

<br>**Sample Input：**<br>
`1 2 3 4 5 6 7 8 9 10`

<br>**Sample Output：**<br>
`5`

<br>

## 7-3 选手打分
**Description：**<br>
编写程序，实现如下功能。9个评委给某个参赛选手打分，去掉一个最高分和一个最低分，求该参赛选手的平均分。
>**提示：**<br>
>输出格式为`printf("去掉最高分：%.2f，去掉最低分：%.2f，平均分为：%.2f",......);`

<br>**Sample Input：**<br>
`89.5 90.6 88.7 92.3 99.8 70.5 86.7 88.6 93.5`

<br>**Sample Output：**<br>
`去掉最高分：99.80，去掉最低分：70.50，平均分为：89.99`

<br>

## 7-4 修改冒泡排序法
**Description：**<br>
修改冒泡排序法，对10个数进行排序。使之可以显示排序过程中的信息以及一共经过的比较次数，输出结果如下。
>**提示：**<br>
>输出格式：<br>
>1）数字输出`％4d`<br>
>2）`printf("After pass %d :",....);` <br>
>3) `printf("\nNumber of comparisons = %d\n",...);` <br>
>冒泡排序法（对十个数排序）：<br>
>```
>#include<stdio.h>
>int main()
>{   
>    int a[10], i, j, t;
>    printf("Input 10 numbers:\n");
>    for(i = 0; i < 10; i++)
>        scanf("%d", &a[i]);
>    printf("\n");
>    
>    for(j = 0; j < 9; j++)
>    {
>        for(i = 0; i < 9 - j; i++)
>        {
>            if(a[i] > a[i + 1])
>            {
>                t = a[i]; 
>                a[i] = a[i + 1]; 
>                a[i + 1] = t;
>            }
>        }
>    }
>    
>    printf("The sorted numbers:\n");
>    for(i = 0; i < 10; i++)
>        printf("%d ",a[i]);
>}
>```

<br>**Sample Input：**<br>
`2 6 4 8 10 12 89 68 45 37`

<br>**Sample Output：**<br>
```
After pass 0 :   2   4   6   8  10  12  68  45  37  89
After pass 1 :   2   4   6   8  10  12  45  37  68
After pass 2 :   2   4   6   8  10  12  37  45
After pass 3 :   2   4   6   8  10  12  37
After pass 4 :   2   4   6   8  10  12
After pass 5 :   2   4   6   8  10
After pass 6 :   2   4   6   8
After pass 7 :   2   4   6
After pass 8 :   2   4
Data items in ascending order
   2   4   6   8  10  12  37  45  68  89
Number of comparisons = 45
```
<br>

## 7-5 逆序字符
**Description：**<br>
编写一个程序，该程序读入少于10个字母到一个数组中，然后以与输入相反的顺序将这些字母输出。输入的字母以句点标识'.'作为结束。输入字符数大于等于10时，取前10个字符逆序。

<br>**Sample Input：**<br>
`abc.`

<br>**Sample Output：**<br>
`cba`

<br>

## 7-6 更高效的冒泡排序
**Description：**<br>
针对题7-4，若数组中的数据可能已经排好序了，或者接近排好序了，可改进算法，减少比较次数。即，使其在每次排序结束时检查是否进行了交换。<br>
如果没有交换过，那么说明剩下的数据肯定已经排好序了，这样程序应该终止。<br>
如果进行过交换，那么至少还需要一遍排序。

<br>**Sample Input：**<br>
`2 6 4 8 10 12 89 68 45 37`

<br>**Sample Output：**<br>
```
After pass 0 :   2   4   6   8  10  12  68  45  37  89
After pass 1 :   2   4   6   8  10  12  45  37  68
After pass 2 :   2   4   6   8  10  12  37  45
After pass 3 :   2   4   6   8  10  12  37
Data items in ascending order
   2   4   6   8  10  12  37  45  68  89
Number of comparisons = 30
```

<br>

## 7-7 去除重复数
**Description：**<br>
编写程序，读入20个大小在10-100之间的数据。每读入一个数据，如果它不与前面读入的数据相重复，则将其输出出来。

<br>**Sample Input：**<br>
`10 11 12 13 14 15 16 17 18 19 20 21 10 11 12 13 14 15 16 17`

<br>**Sample Output：**<br>
`10 11 12 13 14 15 16 17 18 19 20 21 `

<br>

## 7-8 判断两个正整数集合是否相等
**Description：**<br>
输入两行数，每行作为一个集合，判断这两个集合是否相等。<br>
用负数作为一个输入结束的标记，如果相等输出'y'，不相等输出'n'。

<br>**Sample Input：**<br>
```
1 2 3 4 5 6 -1
6 5 4 3 2 1 -2
```
<br>**Sample Output：**<br>
`y`
<br>**Sample Input：**<br>
```
1 2 3 4 5 6 7 8 -2
1 2 3 4 5 6 7 8 9 -2
```
<br>**Sample Output：**<br>
`n`
<br>**Sample Input：**<br>
```
1 2 3 4 5 6 7 8 9 -1
2 3 1 4 6 5 8 7 9 -2
```
<br>**Sample Output：**<br>
`y`