//#include <stdio.h>
//
//#define CLASS 3
//#define STU 4
//
//int FindMax(int *p, int m, int n, int *pRow, int *pCol);
//int main()
//{
//    int score[CLASS][STU], i, j, maxScore, row, col;
////    printf("Please enter score:\n");
//    for (i=0; i<CLASS; i++)
//    {
//        for (j=0; j<STU; j++)
//        {
//            scanf("%d",&score[i][j]);     /*输入学生成绩*/
//        }
//    }
//    
//    /*计算最高分及其学生所在班号和学号*/
//    maxScore = FindMax(*score, CLASS, STU, &row, &col);
//    
//    printf("maxScore = %d, class =%d, number =%d\n",maxScore,row+1,col+1);
//}
/*函数功能：计算任意m行n列的二维数组中元素的最大值，并指出其所在的行列下标值
 函数入口参数：整型指针变量p，指向一个二维整型数组的第行第列
 整型变量m，二维整型数组的行数
 整型变量n，二维整型数组的列数
 函数出口参数：整型指针变量pRow，指向数组元素最大值所在的行
 整型指针变量pCol，指向数组元素最大值所在的列
 函数返回值：数组元素的最大值
 */
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    int  i, j, maxScore;
    
    maxScore = p[0];                  /*置初值，假设第一个元素值最大*/
    *pRow = 0;
    *pCol = 0;
    for (i = 0; i<m; i++)
    {
        for (j = 0; j<n; j++)
        {
            if (p[i*n+j] > maxScore)
            {
                maxScore = p[i*n+j];		/*记录当前最大值*/
                *pRow = i;					/*记录行下标*/
                *pCol = j;					/*记录列下标*/
            }  								/*if结束*/
        }  									/*内层for结束*/
    }  											/*外层for结束*/
    return (maxScore);                 		/*返回最大值*/
}
