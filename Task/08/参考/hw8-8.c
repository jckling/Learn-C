#include  <stdio.h>

#define STU 30
#define COURSE 3

void Input(long num[],int score[][COURSE],int n);
void GetSumAver(int score[][COURSE],int n,int sum[],float aver[]);
void Sort(long num[],int score[][COURSE],int n,int sum[],float aver[]);
void Print(long num[],int score[][COURSE],int n,int sum[],float aver[]);
int  Search(long num[], int n, long x);

int main()
{
    int n, score[STU][COURSE], sum[STU], pos;
    long num[STU], x;
    float aver[STU];
    
//    printf("Please enter the total number of the students(n<=30):");
    scanf("%d",&n);					/*输入参加考试的学生人数*/
    
//    printf("Enter No. and score as: MT  EN  PH\n");
    Input(num, score, n);				/*输入学生成绩*/
    
    GetSumAver(score, n, sum, aver);	/*计算总分和平均分*/
    printf("Before sort:\n");
    Print(num, score, n, sum, aver);
    
    Sort(num, score, n, sum, aver);		/*排名次*/
    printf("After sort:\n");
    Print(num, score, n, sum, aver);
    
//    printf("Please enter searching number:");
//    scanf("%ld",&x);					/*以长整型格式输入待查找学生的学号*/
//    pos = Search(num, n, x);			/*名次查询*/
//    if (pos != -1)
//    {
//        printf("position:\t  NO \tMT\tEN\tPH \tSUM\tAVER\n");
//        printf("%8d\t%4ld\t%d\t%d\t%d\t%d\t%.2f\n", pos+1,num[pos],score[pos][0],score[pos][1],score[pos][2],sum[pos],aver[pos]);
//    }
//    else
//    {
//        printf("Not found!\n");
//    }
    return 0;
}
/* 函数功能：输入某班学生期末考试三门课程成绩
 函数参数：长整型数组num，存放学生学号
 整型数组score，存放学生成绩
 整型变量n，存放学生人数
 函数返回值：无
 */
void Input(long num[], int score[][COURSE], int n)
{
    int  i, j;
    
    for (i=0; i<n; i++)
    {
        scanf("%ld",&num[i]);
        for (j=0; j<COURSE; j++)
        {
            scanf("%d",&score[i][j]);
        }
    }
}

/* 函数功能：计算每个学生的总分和平均分
 函数参数：整型数组score，存放学生成绩
 整型变量n，存放学生人数
 整型数组sum，计算得到的每个学生的总分
 实型数组aver，计算得到的每个学生的平均分
 函数返回值：无
 */
void GetSumAver(int score[][COURSE], int n, int sum[], float aver[])
{
    int i, j;
    
    for (i=0; i<n; i++)
    {
        sum[i] = 0;
        for (j=0; j<COURSE; j++)
        {
            sum[i] = sum[i] + score[i][j];
        }
        aver[i] = (float)sum[i] / COURSE;
    }
}

/* 函数功能：按总分成绩由高到低排出成绩的名次
 函数参数：长整型数组num，存放学生学号
 整型数组score，存放学生成绩
 整型变量n，存放学生人数
 整型数组sum，存放每个学生的总分
 实型数组aver，存放每个学生的平均分
 函数返回值：无
 */
void Sort(long num[],int score[][COURSE], int n, int sum[], float aver[])
{
    int i, j, k, m;
    int temp1;
    long temp2;
    float temp3;
    
    for (i=0; i<n-1; i++)
    {
        k = i;
        for (j=i+1; j<n; j++)
        {
            if (sum[j] > sum[k])  k = j;
        }
        if (k != i)
        {
            temp1 = sum[k];  sum[k] = sum[i];  sum[i] = temp1;
            temp2 = num[k];  num[k] = num[i];  num[i] = temp2;
            temp3 = aver[k];  aver[k] = aver[i];  aver[i] = temp3;
            for (m=0; m<COURSE; m++)
            {
                temp1 = score[k][m];
                score[k][m] = score[i][m];
                score[i][m] = temp1;
            }
        }
    }
}

/* 函数功能：打印名次表，表格内包括学生编号、各科分数、总分和平均分
 函数参数：长整型数组num，存放学生学号
 整型数组score，存放学生成绩
 整型变量n，存放学生人数
 整型数组sum，存放每个学生的总分
 实型数组aver，存放每个学生的平均分
 函数返回值：无
 */
void Print(long num[], int score[][COURSE], int n,
           int sum[], float aver[])
{
    int  i, j;
    
    printf("  NO \t   MT \t  EN \t PH \t SUM \t AVER\n");
    printf("----------------------------------------------------\n");
    for (i=0; i<n; i++)
    {
        printf("%ld\t",num[i]);
        for (j=0; j<COURSE; j++)
        {
            printf("%4d\t",score[i][j]);
        }
        printf("%4d\t%.2f\n",sum[i],aver[i]);
    }
}

/* 函数功能：在学号数组中顺序查找学生的学号
 函数参数：长整型数组num，存放学生学号
 整型变量n，存放学生人数
 长整型变量x，存放待查找学生的学号
 函数返回值：找到时，返回学生学号在学号数组中的下标位置，否则返回值-1
 */
int Search(long num[], int n, long x)
{
    int  i;
    
    for (i=0; i<n; i++)
    {
        if (num[i] == x)  return(i);
    }
    return (-1);
}


