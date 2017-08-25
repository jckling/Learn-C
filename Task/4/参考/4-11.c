#include<stdio.h>

#include<math.h>
int main(int argc, char* argv[])
{
    char c='A';
    int i,j,k=0;
    int n=9;
    
    for(i=1;i<=2*n-1;i++)
    {
        for(j=0;j<= abs(n-i);j++)
            printf("+");
        for(j=1;j<=2*(n-abs(n-i))-1;j++)
            printf("%c",c+(k++%26));
        for(j=0;j<=abs(n-i);j++)
            printf("+");
        printf("\n");
    }
    return 0;
}

