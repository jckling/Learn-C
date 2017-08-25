
#include <stdio.h>

/* prototypes */
unsigned packCharacters( char x, char y );
void displayBits( unsigned value );

int main( void )
{
    char a;          /* first character from user */
    char b;          /* second character from user */
    unsigned result; /* result of packing both characters */
    
    /* prompt user and read two characters */
//    printf( "Enter two characters: " );
    scanf( "%c %c", &a, &b );
    
    /* display first character as bits */
    printf( "\n\'%c\' in bits as an unsigned integers is:\n", a );
    displayBits( a );
    
    /* display second character as bits */
    printf( "\n\'%c\' in bits as an unsigned integers is:\n", b );
    displayBits( b );
    
    /* pack characters and display result */
    result = packCharacters( a, b );
    printf( "\n\'%c\' and \'%c\' packed in an unsigned integer:\n",
           a, b );
    displayBits( result );
    
    return 0; /* indicate successful termination */
    
} /* end main */

/* function packCharacters packs two characters into an unsigned int */
unsigned packCharacters( char x, char y )
{
    unsigned pack = x; /* initialize pack to x */
    
    pack <<= 8; /* shift pack 8 bits to the left */
    pack |= y; /* pack y using inclusive OR operator */
    return pack;
    
} /* end function packCharacters */

/* display the bits of value */
void displayBits( unsigned value )
{
    unsigned c; /* bit counter */
    unsigned displayMask = 1 << 15; /* bit mask */
    
    printf( "%10u = ", value );
    
    /* loop through bits */
    for ( c = 1; c <= 16; c++ ) {
        value & displayMask ? putchar( '1' ) : putchar( '0' );
        value <<= 1; /* shift value 1 bit to the left */
        
        if ( c % 8 == 0 ) { /* print a space */
            putchar( ' ' );
        } /* end if */
        
    } /* end for */
    
    putchar( '\n' );
} /* end function displayBits */

