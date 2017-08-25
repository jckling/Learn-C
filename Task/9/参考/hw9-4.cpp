#include <stdio.h>
void  method(int m,int n,int *a);
int main()
{

    int a[10];
    int i, m, n;
    for ( i=0; i<10; i++ )
        scanf("%d", &a[i] );
    scanf( "%d%d", &m, &n );   
    method(m,n,a);
    for( i=0;i<10;i++ )
        printf( "%d ", a[i] );
}
void  method(int m,int n,int *a)
{
	int *k=a+(m+n/2)-1,*i,*j,t;
	i=a+m-1;
	j=a+m+n-2;

	for(;i<k;i++,j--)
	{
		t=*i;
		*i=*j;
		*j=t;
	}
}

