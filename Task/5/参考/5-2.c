#include <stdio.h>

int multiple( int a, int b ); /* function prototype */

int main()
{
    int x; /* first integer */
    int y; /* second integer */
    int i; /* loop counter */
    
    /* loop 3 times */
    for ( i = 1; i <= 3; i++ ) {
        //printf( "Enter two integers: " );
        scanf( "%d%d", &x, &y );
        
        /* determine if second is multiple of first */
        if ( multiple( x, y ) ) {
            printf( "%d is a multiple of %d\n", y, x );
        } /* end if */
        else {
            printf( "%d is not a multiple of %d\n", y, x );
        } /* end else */
        
    } /* end for */
    
    return 0; /* indicate successful termination */
    
} /* end main */

/* multiple determines if b is multiple of a */
int multiple( int a, int b )
{
    return !( b % a );
    
} /* end function multiple */

