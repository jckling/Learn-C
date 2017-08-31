# 目录
* [实验13 单链表](#实验13-单链表)
* [13-1 双向链表](#13-1-双向链表)
* [13-2 人员信息处理](#13-2-人员信息处理)
* [13-3 人员信息处理－升级版](#13-3-人员信息处理－升级版)
* [13-4 统计单词数](#13-4-统计单词数)
* [13-5 递归打印单链表](#13-5-递归打印单链表)

<br>

## 实验13 单链表
**Description：**<br>
设有如下马匹结构体Horse，依次输入马匹信息，构成一个单链表，然后再将马匹信息输出。
```
typedef struct horse                      
{
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
    struct horse *next;              
}Horse;
```
>输入：<br>
>y代表继续输入，n代表结束输入。然后依次输入马匹的名字，年龄，身高，父亲和母亲信息<br>
>输出格式：<br>
>`printf("\n\n%s is %d years old, %d hands high,", ......);`<br>
>`printf(" and has %s and %s as parents.", ......);`
>**提示：**<br>
>清除输入缓冲区的方法：
>```
>char ch;
>while ((ch = getchar()) != '\n' && ch != EOF);
>```

<br>**Sample Input：**<br>
```
y
lily
10
122
molly
steve
y
may
9
110
Jack
Holy
n
```

<br>**Sample Output：**<br>
```
lily is 10 years old, 122 hands high, and has molly and steve as parents.
may is 9 years old, 110 hands high, and has Jack and Holy as parents.
```

<br>

## 13-1 双向链表
**Description：**<br>
设有如下马匹结构体Horse，依次输入马匹信息，构成一个双向单链表，即结构体中包含两个自引用，一个指针指向前驱结点，另一个指针指向后继结点。然后再以逆序方式将马匹信息输出。
```
typedef struct horse                      
{
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
    struct horse *previous;     
    struct horse *next;              
}Horse;
```
>输入：<br>
>y代表继续输入，n代表结束输入。然后依次输入马匹的名字，年龄，身高，父亲和母亲信息<br>
>输出格式：<br>
>`printf("\n\n%s is %d years old, %d hands high,", ......);`<br>
>`printf(" and has %s and %s as parents.", ......);`

<br>**Sample Input：**<br>
```
y
lily
10
122
molly
steve
y
may
9
110
Jack
Holy
n
```

<br>**Sample Output：**<br>
```
may is 9 years old, 110 hands high, and has Jack and Holy as parents.
lily is 10 years old, 122 hands high, and has molly and steve as parents.
```

<br>

## 13-2 人员信息处理
**Description：**<br>
设有如下表示家庭信息的双向链表：
```
typedef struct Date
{
    int day;
    int month;
    int year;
}Date;

typedef struct Family  /* Family structure declaration */
{
    struct Date dob;
    char name[20];
    char father[20];
    char mother[20];
    struct Family *next;  /* Pointer to next structure    */
    struct Family *previous;  /* Pointer to previous structure */
}Family;
```
请根据主函数，完成三个函数的实现。该程序依次输入人员信息（姓名，日，月，年，父亲，母亲），然后分别以正序和逆序输出人员信息。<br>
```
Family *get_person(void); /* 获取家庭成员信息，返回链表的指针*/
void show_people(int forwards,Family *pfirst,Family *plast); /* 显示家庭成员信息，第一个参数forwards表示正向还是反向输出，值为1时，正向输出。值为0时，反向输出。其他两个参数是链表中第一个和最后一个family对象的地址*/
void release_memory(Family *pfirst);/*提供链表中第一个Family对象的地址，该函数就可以遍历链表中的所有元素，释放它们占用的内存。*/
```
>输出格式：<br>
>`printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n",......);`<br>
>**提示：**<br>
>清除输入缓冲区的方法：
>```
>char ch;
>while ((ch = getchar()) != '\n' && ch != EOF);
>```
>**主函数如下：**
>```
>#include <stdio.h>
>#include <ctype.h>
>#include <stdlib.h>
>#include <string.h>
>
>typedef struct Date
>{
>    int day;
>    int month;
>    int year;
>}Date;
>
>typedef struct Family                          /* Family structure >declaration */
>{
>    struct Date dob;
>    char name[20];
>    char father[20];
>    char mother[20];
>    struct Family *next;                /* Pointer to next structure    */
>    struct Family *previous;           /* Pointer to previous structure */
>}Family;
>
>Family *get_person(void);
>void show_people(int forwards, Family *pfirst, Family *plast);
>void release_memory(Family *pfirst);
>
>int main(void)
>{
>    struct Family *first = NULL;  /* Pointer to first person      */
>    struct Family *current = NULL;  /* Pointer to current person    */
>    struct Family *last = NULL;  /* Pointer to previous person   */
>    char more = '\0';  /* Test value for ending input  */
>    
>    while(1)
>    {
>   // printf("\nDo you want to enter details of a%s person (Y or N)? ",
>   // first != NULL?"nother" : "");
>      
>        scanf(" %c", &more);
>        if(tolower(more) == 'n')
>            break;
>        
>        current = get_person();
>        
>        if(first == NULL)
>        {
>            first = current;  /* Set pointer to first Family  */
>        }
>        else
>        {
>            last->next = current;   /* Set next address for previous Family */
>            current->previous = last;   /* Set previous address for current */
>        }
>        last = current;  /* Remember for next iteration  */
>    }
>    printf("\nShow in a forward way.\n");
>    show_people(1, first, last);
>    printf("\nShow in a reverse way.\n");
>    show_people(0, first, last);
>    release_memory(first);
>    first = last = NULL;
>
>    return 0;
>}
>```

<br>**Sample Input：**<br>
```
Y
GuoXiang
30 5 1880
Guo Jing
Huang Rong
y
Yang Guo
2 26 1224
Yang Kang
Xiao Longnv
y
Zhang Wuji
9 9 1888
Zhang Cuishan
Yin susu
n
```

<br>**Sample Output：**<br>
```
Show in a forward way.
GuoXiang was born 30/5/1880, and has Guo Jing and Huang Rong as parents.
Yang Guo was born 2/26/1224, and has Yang Kang and Xiao Longnv as parents.
Zhang Wuji was born 9/9/1888, and has Zhang Cuishan and Yin susu as parents.
Show in a reverse way.
Zhang Wuji was born 9/9/1888, and has Zhang Cuishan and Yin susu as parents.
Yang Guo was born 2/26/1224, and has Yang Kang and Xiao Longnv as parents.
GuoXiang was born 30/5/1880, and has Guo Jing and Huang Rong as parents.
```

<br>

## 13-3 人员信息处理－升级版
**Description：**<br>
请在13-2的基础上，完成下面函数的实现。<br>
>注意：family结构体有所改动
```
typedef struct family
{
    struct Date dob;
    char name[20];
    char father[20];
    char mother[20];
    struct family *next;  /* Pointer to next structure     */

    struct family *previous;  /* Pointer to previous structure */

    struct family *p_to_pa;  /* Pointer to father structure   */

    struct family *p_to_ma;  /* Pointer to mother structure   */

}Family;
```
`void Initparents(Family *pfirst, Family *plast); /*遍历链表中的每一个节点，并为其父亲和母亲指针域赋值。例如，节点“郭湘”的父亲名字“郭靖”与节点的“郭靖”一致，则节点“郭湘”的父亲域指针指向节点“郭靖”*/`
>输入：<br>
>人员信息（姓名，日，月，年，父亲，母亲）<br>
>输出：<br>
>以正序输出人员信息。如果在链表中找到其父母，则将父母信息依次输入<br>
>注意：每句话输出均有句号'.'<br>
>输出格式：<br>
>1）没有父母信息：<br>
>`printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n"....);`<br>
>2)仅有父亲信息：<br>
>`printf("%s's birth date is %d/%d/%d",......);`<br>
>3)仅有母亲信息：<br>
>`printf(" and %s's birth date is %d/%d/%d.".......);`<br>
>4)父母信息都有：<br>
>`printf("%s's birth date is %d/%d/%d",......);`<br>
>`printf(" and %s's birth date is %d/%d/%d.".......);`

<br>**Sample Input：**<br>
```
Y
GuoXiang
30 5 1880
Guo Jing
Huang Rong
y
Yang Guo
2 26 1224
Yang Kang
Xiao Longnv
y
Zhang Wuji
9 9 1888
Zhang Cuishan
Yin susu
y
Guo Jing
1 4 1777
Guo Xiaotian
Li Ping
y
Yang Kang
3 7 1011
Yang tiexin
Bao xiruo
y
Huang Rong
1 5 1774
Huang Yaoshi
Feng heng
y
Yin susu
3 5 1665
Who knows
YIN
n
```

<br>**Sample Output：**<br>
```
Show in a forward way.

GuoXiang was born 30/5/1880, and has Guo Jing and Huang Rong as parents.
Guo Jing's birth date is 1/4/1777 and Huang Rong's birth date is 1/5/1774.

Yang Guo was born 2/26/1224, and has Yang Kang and Xiao Longnv as parents.
Yang Kang's birth date is 3/7/1011.

Zhang Wuji was born 9/9/1888, and has Zhang Cuishan and Yin susu as parents.
 and Yin susu's birth date is 3/5/1665.

Guo Jing was born 1/4/1777, and has Guo Xiaotian and Li Ping as parents.

Yang Kang was born 3/7/1011, and has Yang tiexin and Bao xiruo as parents.

Huang Rong was born 1/5/1774, and has Huang Yaoshi and Feng heng as parents.

Yin susu was born 3/5/1665, and has Who knows and YIN as parents.
```
<br>

## 13-4 统计单词数
**Description：**<br>
输入一段文本（小于10000个字符），使用如下结构体记录每个单词及其出现次数。并输出结果。
```
typedef struct WordCounter
{
    char *word;
    int word_count;
    struct WordCounter *pNext;  /* Pointer to the next word counter in the list */
}WordCounter;
```
>文本段中单词之间的分隔字符如下：<br>
>`static char separators[] = { ' ' , ',',':' , '\"', '?' , '!' , '.'};`

由于结构体的成员word为指针，因此需要为其动态分配空间，以存放每个单词。<br>
文本长度未知，也需要根据单词数量动态分配存储空间。程序中不定义结构体数组。仅定义结构体指针。<br>
请适当划分函数完成此题。如创建链表、显示链表、删除链表。<br>
>输出格式：<br>
>`printf("%-20s   %5d\n"....);`

<br>**Sample Input：**<br>
`This is the book he wants.This is your book!`

<br>**Sample Output：**<br>
```
This                       2
is                         2
the                        1
book                       2
he                         1
wants                      1
your                       1
```

<br>

## 13-5 递归打印单链表
**Description：**<br>
输入5个数，编写一个printListBackWards来递归地倒序输出链表中的内容。输出数据以空格分隔。
>**提示：**<br>
>结点数据域为int<br>
><br>
>**主函数如下：**
>```
>#include <stdio.h>
>#include <stdlib.h>
>
>/* ListNode structure definition */
>struct ListNode {
>    int data;                 /* node data */
>    struct ListNode *nextPtr; /* pointer to next node */
>}; /* end struct ListNode */
>
>typedef struct ListNode ListNode;
>typedef ListNode *ListNodePtr;
>
>/* function prototype */
>void printList(ListNodePtr currentPtr);
>void printListBackward(ListNodePtr currentPtr);
>void insertItem(ListNodePtr *sPtr, int value);
>
>int main( void )
>{
>    ListNodePtr startPtr = NULL; /* list pointer */
>    int item; /* loop counter */
>    int number;
>    
>    /* insert integers into list */
>    for (item = 1; item <= 5; item++) {
>        scanf("%d", &number);
>        insertItem(&startPtr, number);
>    } /* end for */
>    
>    printList(startPtr);
>    printf( "\n" );
>    printListBackward(startPtr);
>    
>    return 0; /* indicate successful termination */
>
>} /* end main */
>```

<br>**Sample Input：**<br>
`6 7 8 9 4`

<br>**Sample Output：**<br>
```
4 6 7 8 9 
The list reversed is:
9 8 7 6 4
``` 