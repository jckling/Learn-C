#include <stdio.h>
#define SIZE 10

int main()
{
    char letterBox[SIZE],next;
    int index = 0;
    scanf("%c",&next);
    while (next != '.' &&(index < SIZE)) {
        letterBox[index] = next;
        index++;
        scanf("%c",&next);
    }
    int numberUsed = index;
    for( index = numberUsed - 1; index >= 0 ; index--)
        printf("%c",letterBox[index]);
    
    return 0; /* indicate successful termination */
    
} /* end main */