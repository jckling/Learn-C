# 目录
* [11-1 字符串转换成浮点数](#11-1-字符串转换成浮点数)
* [11-2 部分字符串比较](#11-2-部分字符串比较)
* [11-3 倒序显示句子](#11-3-倒序显示句子)
* [11-4 以字母ing结尾的字符串](#11-4-以字母ing结尾的字符串)
* [11-5 统计子串出现的次数](#11-5-统计子串出现的次数)
* [11-6 统计单词个数](#11-6-统计单词个数)
* [11-7 统计字母出现的次数](#11-7-统计字母出现的次数)
* [11-8 Pig Latin](#11-8-pig-latin)
* [11-9 从输入的文本中提取所有单词](#11-9-从输入的文本中提取所有单词)
* [11-10 统计任意长度散文中的单词频率](#11-10-统计任意长度散文中的单词频率)

<br>

## 11-1 字符串转换成浮点数
**Description：**<br>
编写一个程序，输入4个表示浮点数的字符串，然后将他们转换成双精度浮点数，计算他们的和并输出。
>**提示：**<br>
>程序的前缀及后缀代码已给出
>```
>前缀代码：
>
>#include <stdio.h>
>#include <stdlib.h>
>
>int main( void )
>{
>    char stringValue[ 15 ]; /* string input by user */
>    double sum = 0.0;       /* sum of all four values */
>    int i;                  /* loop counter */
>```
>```
>后缀代码：
>
>    printf( "The total of the values is %.2f\n", sum );
>    
>    return 0; 
>    
>}
>```

<br>**Sample Input：**<br>
```
12.5
56.7
55.89
9999.67
```

<br>**Sample Output：**<br>
`The total of the values is 10124.76`

<br>

## 11-2 部分字符串比较
**Description：**<br>
编写一个程序，用户输入两个字符串，以及待比较字符数的个数，返回比较结果。
>要求：<br>
>1）每个字符串长度不超过19个字符<br>
>2）输出格式：<br>
>`printf( "\"%s\" is greater than \"%s\" up to %d characters\n", ......);`<br>
>`printf( "\"%s\" is less than \"%s\" up to %d characters\n", ......);`<br>
>`printf( "\"%s\" is equal to \"%s\" up to %d characters\n", ......);`

<br>**Sample Input：**<br>
```
abced
abdec
2
```
<br>**Sample Output：**<br>
`"abced" is equal to "abdec" up to 2 characters`
<br>**Sample Input：**<br>
```
abcdef
Abcdef
6
```
<br>**Sample Output：**<br>
`"abcdef" is greater than "Abcdef" up to 6 characters`

<br>

## 11-3 倒序显示句子
**Description：**<br>
编写一个程序，输入一行文本，然后用strtok函数将这行文本标号化，并将文本倒序输出。假设文本长度不超过50个单词，且单词之间由空格分隔。
>注意：输出时最后一个单词之后还有一个空格

<br>**Sample Input：**<br>
`This is a amazing day. `
<br>**Sample Output：**<br>
`day. amazing a is This `
<br>**Sample Input：**<br>
`Here is your     coat!`
<br>**Sample Output：**<br>
`coat! your is Here `

<br>

## 11-4 以字母ing结尾的字符串
**Description：**<br>
编写一个程序，输入5个字符串，每个字符串长度不超过20个字符，将以“ing”结尾的字符串输出出来。
>**提示：**<br>
>先用strlen函数求出字符串长度，然后用strcmp函数进行比较

<br>**Sample Input：**<br>
```
going
start
camping
eating
ok
```

<br>**Sample Output：**<br>
```
going
camping
eating
```

<br>

## 11-5 统计子串出现的次数
**Description：**<br>
编写一个程序，输入3行文本和一个查找目标字符串，输出这个目标字符串在这些文本行中出现的总次数。文本不区分大小写。
>**提示：**<br>
>使用strstr函数来确定目标字符串在文本中第一次出现的位置，并将位置保存到指针searchPtr中，然后再次调用strstr函数（以searchPtr＋1为第一个实参），寻找第二次出现目标串的位置

<br>**Sample Input：**<br>
```
This is the first sentence.
This is the second one.
Here is the last one.
the
```
<br>**Sample Output：**<br>
`3`
<br>**Sample Input：**<br>
```
This is the first sentence.
This is the second one.
Here is the last one.
is
```
<br>**Sample Output：**<br>
`5`

<br>

## 11-6 统计单词个数
**Description：**<br>
输入4行文本，用strtok函数统计单词的总数。

<br>**Sample Input：**<br>
```
This is the first sentence.
This is the second one.
Here is the last one.
the
```

<br>**Sample Output：**<br>
`16`

<br>

## 11-7 统计字母出现的次数
**Description：**<br>
编写一个程序，输入2行文本然后用函数strchr来确定字母表中的每个字母在这些文本行中出现的总次数。同一字母的大写和小写统计到一起。将每一个字母出现的总次数存储到一个数组里。在所有次数都统计出来后，按照列表形式将这些数值打印出来。
>**提示：**<br>
>输出格式：`printf("[%c,%d times] ".....);`

<br>**Sample Input：**<br>
```
It was Sunday. I never get up early on Sundays.
I sometimes stay in bed until lunchtime.
```

<br>**Sample Output：**<br>
```
[a,5 times] [b,1 times] [c,1 times] [d,3 times] [e,8 times] [f,0 times] [g,1 times] [h,1 times] [i,7 times] [j,0 times] [k,0 times] [l,3 times] [m,3 times] [n,7 times] [o,2 times] [p,1 times] [q,0 times] [r,2 times] [s,7 times] [t,6 times] [u,5 times] [v,1 times] [w,1 times] [x,0 times] [y,4 times] [z,0 times]
```

<br>

## 11-8 Pig Latin
**Description：**<br>
请编写一个程序，将英语短语改编成“Pig Latin”——一种用于娱乐的编码语言。我们采用如下的方法进行改编。<br>
首先要用函数strtok将短语标号化，然后将每一个英语单词翻译成为一个“Pig Latin”单词，即将英语单词的第一个字母放到单词的最后，然后加上“ay”。<br>
例如，jump就翻译成umpjay，the翻译成hetay。单词之前依然保留空格。假设英语单词之间由空格、逗号或者分号分开，且所有单词至少有2个字母。句子最后加上标点符号。

<br>**Sample Input：**<br>
`And grace my fear relieved`
<br>**Sample Output：**<br>
`ndAay racegay ymay earfay elievedray.`
<br>**Sample Input：**<br>
`Bright shining as the sun;Than when we first begun.`
<br>**Sample Output：**<br>
`rightBay hiningsay saay hetay unsay hanTay henway eway irstfay egunbay.`

<br>

## 11-9 从输入的文本中提取所有单词
**Description：**<br>
请编写一个程序，输入一段文本（不超过1000个字符），提取文本中的所有单词，输出并统计。输入一个空行代表输入结束。<br>
文本的分隔字符包括："\n \".,;:!?)("
>输出格式：每5个单词输出一行。每个单词占18位，左对齐<br>
>`printf("%-18s",....);`<br>
>`printf("\n%u words found.\n",.....);`<br>
>`printf("No words found.\n");`<br>
>**提示：**<br>
>首先将输入的每行文本连接到一个字符数组中，然后调用strtok函数进行分词，并统计单词数量<br>
>输入字符串时，注意比较gets与fgets函数的用法，并选择合适的函数。

<br>**Sample Input：**<br>
```
My father's family name being Pirrip, and my Christian name Philip,
my infant tongue could make of both names nothing longer
or more explicit than Pip.
So, I called myself Pip, and came to be called Pip.
```
<br>**Sample Output：**<br>
```
My                father's          family            name              being             
Pirrip            and               my                Christian         name              
Philip            my                infant            tongue            could             
make              of                both              names             nothing           
longer            or                more              explicit          than              
Pip               So                I                 called            myself            
Pip               and               came              to                be                
called            Pip               
37 words found.
```
<br>**Sample Input：**<br>
`（仅输入一个空行）`
<br>**Sample Output：**<br>
`No words found.`

<br>

## 11-10 统计任意长度散文中的单词频率
**Description：**<br>
请编写一个程序，统计在某个随意的散文中查找每个单词出现的次数。单词不区分大小写。散文长度任意，单词数量及每个单词的长度也任意。<br>
即此题除了以下两个数组外，不能定义任何长度固定的数组。<br>
`char delimiters[] = " \n\".,;:!?)(";  //散文的分隔符`<br>
`char buf[100];  //输入缓冲数组，每次将一行文本输入此变量中`
>**提示：**<br>
>此题需要使用动态内存分配，来存储散文、单词和单词数>**提示：**<br>
>以空行结束散文的输入>**提示：**<br>
>输出格式：每4个单词一行<br>
>`printf(" %-13s %3d",.....);`<br>
>`printf("No words found. Ending program.\n");`

<br>**Sample Input：**<br>
```
Peter Piper picked a peck of pickled pepper.
A peck of pickled pepper Peter Piper picked.
If Peter Piper picked a peck of pickled pepper,
Where's the peck of pickled pepper Peter Piper picked?
```

<br>**Sample Output：**<br>
```
 peter           4 piper           4 picked          4 a               3
 peck            4 of              4 pickled         4 pepper          4
 if              1 where's         1 the             1
```