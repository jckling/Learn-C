#include <stdio.h>

void  method(int m, int n, int *a);

int main()
{
    int a[10];
    int i, m, n;
    
    for (i=0; i<10; i++)
        scanf("%d", &a[i]);
    scanf("%d%d", &m, &n);
    
    method(m,n,a);
    
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
}

void  method(int m, int n, int *a)
{
	int x, i;
	if(n % 2 != 0)
	{
		for(i = 0; i < (n - 1) / 2; i++)
		{
		   x=a[m + i - 1];
	       a[m + i - 1] = a[m + n - i - 2];
	       a[m + n - i - 2] = x;
		   
		}
	}
	else
	{
		for(i = 0; i < n / 2; i++)
		{
		   x = a[m + i - 1];
	       a[m + i - 1] = a[m + n - i - 2];
	       a[m + n - i - 2] = x;
		}
	}
}