# 目录
* [实验3-1 猜数](#实验3-1-猜数)
* [实验3-2 猜数进阶](#实验3-2-猜数进阶)
* [3-1 幼儿分班](#3-1-幼儿分班)
* [3-2 三个整数排序](#3-2-三个整数排序)
* [3-3 判断奇偶性](#3-3-判断奇偶性)
* [3-4 计算分段函数](#3-4-计算分段函数)
* [3-5 求满足条件的数的个数](#3-5-求满足条件的数的个数)
* [3-6 求阶乘之和](#3-6-求阶乘之和)
* [3-7 汽油里程](#3-7-汽油里程)
* [3-8 已知循环次数，算式求和](#3-8-已知循环次数，算式求和)
* [3-9 已知循环条件，算式求和](#3-9-已知循环条件，算式求和)
* [3-10 求一组数中的最大值](#3-10-求一组数中的最大值)
* [3-11 名字笔画计算缘分](#3-11-名字笔画计算缘分)
* [3-12 判断三角形形状](#3-12-判断三角形形状)
* [3-13 求解一元二次方程的根](#3-13-求解一元二次方程的根)
* [3-14 BMI指数](#3-14-BMI指数)

<br>

## 实验3-1 猜数
**Description：**<br>
编写一个猜数程序。预先设定一个神秘数，例如数值为25，接下来让用户输入一个数，如果输入的数值比25大，则输出“Wrong! Too high!”，如果输入数值比25小，则输出“Wrong! Too low!”，如果输入数值为25，则输出“Right!”。最后将这个神秘数字输出。

<br>**Sample Input：**<br>
`2`
<br>**Sample Output：**<br>
```
Wrong! Too low!
The number is: 25
```
<br>**Sample Input：**<br>
`40`
<br>**Sample Output：**<br>
```
Wrong! Too high!
The number is: 25
```
<br>**Sample Input：**<br>
`2`
<br>**Sample Output：**<br>
```
Right!
The number is: 25
```

<br>

## 实验3-2 猜数进阶
**Description：**<br>
编写一个猜数程序。预先设定一个神秘数，例如数值为25，接下来让用户输入一个数，如果输入的数值比25大，则输出“Wrong! Too high!”，如果输入数值比25小，则输出“Wrong! Too low!”，直到用户猜对为止，并输出用户猜了几次。

<br>**Sample Input：**<br>
```
23
45
25
```

<br>**Sample Output：**<br>
```
Wrong! Too low!
Wrong! Too high!
Right!
You guess 3 times.
The game is over!
```

<br>

##  3-1 幼儿分班
**Description：**<br>
某托儿所接收2-6岁之间的孩子，2岁、3岁孩子进小班（Lower class）；4岁孩子进中班（Middle class）；5岁、6岁孩子进大班（Higher class）。编写程序，输入孩子年龄，则输出孩子年龄及进入的班号。
>注意：输出样例中的符号均为英文符号

<br>**Sample Input：**<br>
`2`
<br>**Sample Output：**<br>
`age: 2, enter Lower class`
<br>**Sample Input：**<br>
`4`
<br>**Sample Output：**<br>
`age: 4, enter Middle class`
<br>**Sample Input：**<br>
`6`
<br>**Sample Output：**<br>
`age: 6, enter Higher class`

<br>

##  3-2 三个整数排序
**Description：**<br>
输入三个整数x,y,z，请把这三个数由小到大输出。<br>
输出格式：`printf("small to big: %d %d %d", x, y, z);`
>**提示：**<br>
>1）想办法把最小的数放到x上。先将x与y进行比较，如果x>y，则将x与y的值进行交换，然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小<br>
>2）两个数交换，需要借助第三个变量。直接 x ＝ y；不能完成两个数的交换，而是用y的值覆盖了x的值

<br>**Sample Input：**<br>
`67 45 99`

<br>**Sample Output：**<br>
`small to big: 45 67 99`

<br>

## 3-3 判断奇偶性
**Description：**<br>
编写程序，输入一个整数，判断其正负性（positive or negative）以及奇偶性（odd or even）。负偶数（negative even）、负奇数（negative odd）、正偶数（positive even）、正奇数（positive odd）。0输出"0 is zero"。

<br>**Sample Input：**<br>
`-5`
<br>**Sample Output：**<br>
`-5 is a negative odd`
<br>**Sample Input：**<br>
`0`
<br>**Sample Output：**<br>
`0 is zero`

<br>

## 3-4 计算分段函数
**Description：**<br>
编写程序，计算分段函数![relation](https://github.com/jckling/Learn-C/tree/master/Task/3/3-4.png)，输入x，打印y的数值。

>**提示：**<br>
>1）使用数学函数exp求ex，注意该函数接收的参数的数据类型为float 或者 double，若输入数据为int型，需进行强制类型转换。使用该函数需包含必要的头文件<br>
>2）要求输出的结果根据数值宽度选择以科学计数法或者小数形式输出，请使用正确的格式控制符

<br>**Sample Input：**<br>
`678`
<br>**Sample Output：**<br>
`y = 3.53461e-295`
<br>**Sample Input：**<br>
`3`
<br>**Sample Output：**<br>
`y = 0.0497871`

<br>

## 3-5 求满足条件的数的个数
**Description：**<br>
个位数为6且能被3整除的五位数共有多少个？

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`一个数字，满足题目条件的数的个数`

<br>

## 3-6 求阶乘之和
**Description：**<br>
编程计算`1!+2!+3!+4!+…+10！`的值。
>注意：求阶乘和求幂很容易使得数据发生溢出，请选择合适的数据类型

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`一个数字，计算的结果`

<br>

## 3-7 汽油里程
**Description：**<br>
请编写一个程序，读入行驶的英里数和每次加满油后使用的燃油数（单位：加仑），计算并显示这几次加油的平均每加仑行驶的英里数。
>注意:
<br>**Sample Input：**<br>
```
12.8
287
10.3
200
5
120
－1
```

<br>**Sample Output：**<br>
`21.601423`

<br>

## 3-8 已知循环次数，算式求和
**Description：**<br>
求`s = 1 / (1 + 2 + 3) - 2 / (2 + 3 + 4) + 3 / (3 + 4 + 5) - 4 / (4 + 5 + 6) + ... `的前20项之和。

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`一个数字，计算结果小数点后保留6位`

<br>

##  3-9 已知循环条件，算式求和
**Description：**<br>
计算'1 - 1/2 + 1 / 3 - 1 / 4 + ... + 1 / 99 - 1 / 100 + ... `，直到最后一项的绝对值小于10-4为止。

<br>**Sample Input：**<br>
`无`

<br>**Sample Output：**<br>
`一个数字，计算结果小数点后保留6位`

<br>

## 3-10 求一组数中的最大值
**Description：**<br>
编写程序，读入10个整数，输出其中的最大值。

<br>**Sample Input：**<br>
```
45
67
98
234
-78
345
2
45
5
56
```

<br>**Sample Output：**<br>
`Largest is 345`

<br>

## 
**Description：**<br>
看看你们的缘分！！！计算出你和另一个人的关系，准的邪门了！ <br>
计算的方法很简单，将你们姓名笔划的总数作比较，以大的数字减小的 。<br>
例如：大雄想知道自己和叮当的关系是什么，要将自己名字的笔划(共15划)和叮当名字的笔划(共21划)相减(即21-15)，得出的数字是6，「帮你的人」。 十分准确啊！ 快来试试吧！ <br><br>
描述：<br>
输入两个名字的笔画数，计算它们的差（大-小），按上表述出两人的关系。
输入：<br>
两个整数<br>
输出：<br>
一个字符串<br>
>注意：输出的是中文，两端不要有空格，考虑超出25的情况
```
差值对照表：
0 亲密无间 
1 永远和你在一起 
2 水火不相容 
3 知心朋友 
4 心上人 
5 帮你做事的人 
6 帮你的人 
7 面和心不合 
8 男女关系不正常 
9 情投意合 
10 关系马虎 
11 尊敬你的人 
12 爱你的人 
13 适合你的 
14 说你坏话的人 
15 克星 
16 救星 
17 忠心的人 
18 狼心狗肺的人 
19 单相思 
20 山盟海誓 
21 情敌 
22 服从你的人 
23 永远在一起 
24 伴终生 
25 恨你又爱你
比25大：你俩缘分超出计算范围
```

<br>**Sample Input：**<br>
`17 20`
<br>**Sample Output：**<br>
`知心朋友`
<br>**Sample Input：**<br>
`26 6`
<br>**Sample Output：**<br>
`山盟海誓 `

<br>

## 3-12 判断三角形形状
**Description：**<br>
输入三角形的三条边a，b，c，判断他们是否能构成三角形，如果可以，判断是哪种类型的三角形。<br>
请分别测试"直角三角形"、"等腰三角形"、"等腰直角三角形"、"一般三角形"、"不是三角形"等五种情况。
>**提示：**<br>
>1）可按照下述流程图编写程序，注意变量flag的作用<br>
>2）判断两个浮点数是否相等时，由于存在精度误差，因此需使用两数相减绝对值小于某一精度范围，如1e-4，来判断<br>
>3）三条边输入以逗号分隔<br>
>![relation](https://github.com/jckling/Learn-C/tree/master/Task/3/3-12.png)

<br>**Sample Input：**<br>
`3,4,5`
<br>**Sample Output：**<br>
`直角三角形`
<br>**Sample Input：**<br>
`3.3,3.3,6`
<br>**Sample Output：**<br>
`等腰三角形`

<br>

## 3-13 求解一元二次方程的根
**Description：**<br>
求一元二次方程ax2+bx+c=0的解。a,b,c为任意实数。<br>
输入：<br>
输入数据有一行，包括a b c的值<br>
输出：<br>
如果a为0同时b为0，则输出`Not an equation`<br>
如果a为0，退化一次方程，则只输出一个根的值<br>
如果a不为0，<br>
（1）如果x1和x2为实根，则以x1>=x2输出。按照`x1 x2`格式输出<br>
（2）如果方程是共轭复根，x1=m+ni，x2=m-ni，其中n>0。其中x1, x2, m,n均保留2位小数。按照如下格式输出：
```
m+ni
m-ni
```
>**提示：**<br>
>输出i的方法`printf("%0.2lf+%0.2lfi\n%0.2lf-%0.2lfi",你的实部,你的虚部,你的实部,你的虚部);`

<br>**Sample Input：**<br>
`-2 4 -1`
<br>**Sample Output：**<br>
`1.71 0.29`
<br>**Sample Input：**<br>
`1 2 3`
<br>**Sample Output：**<br>
```
-1.00+1.41i
-1.00-1.41i
```

<br>

## 3-14 BMI指数
**Description：**<br>
体型判断。按“体指数”对肥胖程度进行划分：
体指数t = 体重w / (身高h)²  （w 单位为公斤，h单位为米）<br>
*当t < 18时，为低体重（lower weight）；<br>
*当t介于18和25之间时，为正常体重（normal weight）；<br>
*当t介于25和27之间时，为超重体重（higher weight）；<br>
*当t >= 27时，为肥胖（obesity）。<br>
编程从键盘输入你的身高h和体重w，根据给定公式计算体指数t，然后判断你的体重属于何种类型。输出BMI指数的值，及体型。<br>
要求使用以下两种语句形式之一：<br>
*算法1：用在 if子句中嵌入 if语句的形式编程<br>
*算法2：用在 else子句中嵌入 if语句的形式编程 <br>

>**提示：**<br>
>如果先算h＊h，计算会有精度损失,使得计算结果与测试用例不符。可改为`t = w / h / h`
<br>**Sample Input：**<br>
`54.5 1.6`

<br>**Sample Output：**<br>
```
21.289062
normal weight
```