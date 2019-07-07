#include <stdio.h>
#define MAX 20

int main()
{
    int a[ MAX ] = { 0 }; /* array for user input */
    int i; /* loop counter */
    int j; /* loop counter */
    int k = 0; /* number of values currently entered */
    int duplicate; /* flag for duplicate values */
    int value; /* current value */
    
//    printf( "Enter 20 integers between 10 and 100:\n" );
    
    /* get 20 integers from user */
    for ( i = 0; i <= MAX - 1; i++ ) {
        duplicate = 0;
        scanf( "%d", &value );
        
        /* test if integer is a duplicate */
        for ( j = 0; j < k; j++ ) {
            
            /* if duplicate, raise flag and break loop */
            if ( value == a[ j ] ) {
                duplicate = 1;
                break;
            } /* end if */
            
        } /* end for */
        
        /* if number is not a duplicate enter it in array */
        if ( !duplicate ) {
            a[ k++ ] = value;
        } /* end if */
        
    } /* end for */
    
//    printf( "\nThe nonduplicate values are:\n" );
    
    /* display array of nonduplicates */
    for ( i = 0; a[ i ] != 0; i++ ) {
        printf( "%d ", a[ i ] );
    } /* end for */
    
    printf( "\n" );
    
    return 0; /* indicate successful termination */
    
} /* end main */