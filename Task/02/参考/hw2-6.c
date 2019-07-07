#include <stdio.h>
// function main begins program execution
int main()
{
    int hour,minute,second;
    
  scanf("%d%*c%d%*c%d",&hour,&minute,&second);
    printf("%02d,%02d,%02d",hour,minute,second);
    return 0; // indicate that program ended successfully
    
} // end function main