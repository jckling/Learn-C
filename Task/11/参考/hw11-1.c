#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char stringValue[ 15 ]; /* string input by user */
    double sum = 0.0;       /* sum of all four values */
    int i;                  /* loop counter */
    
    /* loop 4 times */
    for ( i = 1; i <= 4; i++ )
     {  gets_s( stringValue );
            /* atof converts stringValue to a floating-point value */
        sum += atof( stringValue );
}
    
    printf( "The total of the values is %.2f\n", sum );
    
    return 0; /* indicate successful termination */
    
} /* end main */