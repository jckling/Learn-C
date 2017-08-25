#include<stdio.h>
void FindMaxMin(int num[], int n, int *pMax, int *pMaxPos, int *pMin, int *pMinPos)
{
    int   i;
    
    *pMax = *pMin = num[0];
    *pMaxPos = *pMinPos = -1;
    for (i=1; i<n; i++)
    {
        if (num[i] > *pMax)
        {
            *pMax = num[i];		/*记录最大值*/
            *pMaxPos = i;			/*记录最大值所在下标*/
        }
        if (num[i] < *pMin)
        {
            *pMin = num[i];		/*记录最小值*/
            *pMinPos = i;			/*记录最小值所在下标*/
        }
    }
}
int main()
{
    int num[10];
    int max,maxPos,min,minPos;
//    printf("Input 10 numbers:\n");
    for( int i=0;i<10;i++)
        scanf("%d",&num[i]);
    FindMaxMin(num,10,&max,&maxPos,&min,&minPos);
    printf("Max = %d , Position = %d, Min = %d, Position = %d\n",max,maxPos,min,minPos);
    return 0;
}
