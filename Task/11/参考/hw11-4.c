#include <stdio.h>
#include <string.h>

int main( void )
{
    int i; 
    unsigned long length
    char array[ 5 ][ 20 ];

    for ( i = 0; i <= 4; i++ )
        scanf( "%19s", &array[ i ][ 0 ] );
    
    for ( i = 0; i <= 4; i++ ) 
	{
        length = strlen( &array[ i ][ 0 ] );     
        if ( strcmp( &array[ i ][ length - 3 ], "ing" ) == 0 ) 
            printf( "%s\n", &array[ i ][ 0 ] )；//比较最后三个字母    
    }   
    return 0;  
} 
