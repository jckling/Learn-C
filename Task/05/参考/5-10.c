#include<stdio.h>
#include<math.h>
int prime( int m);
int converse(int n);


int main()
{
    int i,conversei,count=0;
    for(i=100;i<=1000;i++)
    {
        conversei=converse(i);
        if( prime(i) && prime(conversei) && converse(i)>=i)
        {
            printf("%d,%d\n",i,conversei);
            count++;
        }
    }
    printf("count= %d\n",count);
    return 0;
}

int prime( int m)
{
    int i,flag=1,k=sqrt((double) m);
    for(i=2;i<=k && flag;i++)
        if(m%i==0)
            flag=0;
    return flag;
}

int converse(int n)
{
    int i, j,k;
    i = n / 100;			/*分出百位*/
    j = (n - i * 100) / 10;	/*分出十位*/
    k = n % 10;				/*分出个位*/
    return k*100+j*10+i;
}
