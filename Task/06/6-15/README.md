# 目录
* [6-15-1 输出形状](#6-15-1-输出形状)
* [6-15-2 古希腊几何分类数](#6-15-2-古希腊几何分类数)
* [6-15-3 斐波那契数列变形](#6-15-3-斐波那契数列变形)
* [6-15-4 日期的前一天](#6-15-4-日期的前一天)

<br>

## 6-15-1 输出形状
**Description：**<br>
编写一个函数，它的功能是：显示一个由任意两种字符组成的方阵。方阵的大小也由参数指定。并编写主函数测试这个函数。

<br>**Sample Input：**<br>
`5 & #`
<br>**Sample Output：**<br>
```
&&&&&
#&&&&
##&&&
###&&
####&
```
<br>**Sample Input：**<br>
`4 + -`
<br>**Sample Output：**<br>
```
++++
-+++
--++
---+
```

<br>

## 6-15-2 古希腊几何分类数
**Description：**<br>
古希腊几何分类数问题。例如，如果某个数量的小鹅卵石可以排列成对称三角形，那么就称该数为“三角数”。前10个三角数为0、1、3、6、10、15、21、28、36和45。<br>
请编写一个函数用于测试某个数是不是三角数，并编写一个主函数，输出100以内的所有三角数。

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
```
0 is triangular.
1 is triangular.
3 is triangular.
6 is triangular.
10 is triangular.
15 is triangular.
21 is triangular.
28 is triangular.
.......
```

<br>

## 6-15-3 斐波那契数列变形
**Description：**<br>
有以下数列：<br>
1、1、1、3、5、9、17............<br>
除去前三项，其他项均为该数前三项之和。<br>
>要求：输入第几项然后输出该项的数字大小

<br>**Sample Input：**<br>
`2`
<br>**Sample Output：**<br>
`1`
<br>**Sample Input：**<br>
`7`
<br>**Sample Output：**<br>
`17`

<br>

## 6-15-4 日期的前一天
**Description：**<br>
输入“年 月 日” ，输出这个日期的前一天的日期。
>输入：<br>
>三个整数，比如`1992 6 30`<br>
>输出：<br>
>1992年6月30日的前一天的三个数字 `1992 6 29`

<br>**Sample Input：**<br>
`1992 7 1`
<br>**Sample Output：**<br>
`1992 6 30`
<br>**Sample Input：**<br>
`2002 1 1`
<br>**Sample Output：**<br>
`2001 12 31`
<br>**Sample Input：**<br>
`2000 2 29`
<br>**Sample Output：**<br>
`2000 2 28`
<br>**Sample Input：**<br>
`2001 3 1`
<br>**Sample Output：**<br>
`2001 2 28`