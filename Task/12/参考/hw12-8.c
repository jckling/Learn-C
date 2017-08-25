
#include <stdio.h>

/* prototypes */
void displayBits( unsigned value );
unsigned power2( unsigned n, unsigned p );

int main( void )
{
    unsigned number; /* value from user */
    unsigned pow;    /* number of bits to left shift */
    unsigned result; /* result of shift */
    
    /* prompt user and read two integers */
//    printf( "Enter two integers: " );
    scanf( "%u%u", &number, &pow );
    
    /* display bits of number */
    printf( "number:\n" );
    displayBits( number );
    
    /* display bits of pow */
    printf( "\npow:\n" );
    displayBits( pow );
    
    /* perform shift and display results */
    result = power2( number, pow );
    printf( "\n%u * 2^%u = %u\n", number, pow, result );
    displayBits( result );
    
    return 0; /* indicate successful termination */
    
} /* end main */

/* function power2 left shifts n by p */
unsigned power2( unsigned n, unsigned p )
{
    return n << p;
    
} /* end function power2 */

/* display the bits of value */
void displayBits( unsigned value )
{
    unsigned c; /* bit counter */
    unsigned displayMask = 1 << 15; /* bit mask */
    
    printf( "%10u = ", value );
    
    /* loop through bits */
    for ( c = 1; c <= 16; c++ ) {
		putchar(value&displaymask ? '1' : '0');
        value <<= 1; /* shift value 1 bit to the left */
        
        if ( c % 8 == 0 ) { /* print a space */
            putchar( ' ' );
        } /* end if */
        
    } /* end for */
    
    putchar( '\n' );
} /* end function displayBits */
