// …Ì∑›÷§ Æ∞ÀŒª.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

int main(int argc, char* argv[])
{
    int xi[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},i;
    char last[12]="10X98765432";
    int sum=0;
    char id[18];
    
    for(i=0;i<18;i++)
        scanf("%c",&id[i]);
    for(i=0;i<17;i++)
    {
        sum=sum+(id[i]-48)*xi[i];
    }
    if(id[17]==last[sum%11])
        printf("yes");
    else
        printf("no");
    
    return 0;
}

