//#include <stdio.h>
//int main()
//{
//    int*pmax,*pmin;
//    int data[10],temp,i,n;
////    printf("enter n:");
//    scanf("%d",&n);
////    printf("enter %d data:",n);
//    for(i=0;i<n;i++)
//        scanf("%d",&data[i]);
//    printf("orgin:");
//    for(i=0;i<n;i++)
//        printf("%4d",data[i]);
//    printf("\n");
    pmax=pmin=data;
    /*用pmax,pmin定位，分别指向最大值和最小值*/
    for(i=1;i<n;i++)
        if(*pmax<data[i])  pmax=data+i;
    printf("max=%d\n",*pmax);
    /*用第一个和最大值交换*/
    temp=data[0];data[0]=*pmax;*pmax=temp;
    
    for(i=1;i<n;i++)
        if(*pmin>data[i])
            pmin=data+i;
    printf("min=%d\n",*pmin);
    /*最小值和最后一个元素交换*/
    temp=data[n-1];data[n-1]=*pmin;*pmin=temp;
//    printf("sorted:");
//    for(i=0;i<n;i++)
//        printf("%4d",data[i]);
//    printf("\n");
//    
//}
