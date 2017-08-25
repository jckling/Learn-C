#include <stdio.h>


int main()
{
    const int SIZE = 10; // size of array
    int a[ SIZE ];
    int hold;
    int numberOfComp = 0; // number of comparisons made
    int comp; // used to control for loop and for subscripts
    int swapCheck = 1; // was a swap made
    
    // display original, unsorted array
//   56 4 6 32 5 8 77 64 98 99 printf("Data items in original order\n");
    
    for ( int i = 0; i < SIZE; ++i )
        scanf("%d", &a[ i ]);
    
    // begin sorting the array
    for ( int pass = 1; pass < SIZE - 1 && swapCheck == 1; pass++ )
    {
        printf( "After pass %d :", pass - 1);
        swapCheck = 0; // assume no swaps will be made
        
        // traverse and compare unsorted part of array
        for ( comp = 0; comp < SIZE - pass; comp++ )
        {
            numberOfComp++;
            
            // compare two adjacent array elements
            // if swap is made, set swapCheck to true
            if ( a[ comp ] > a[ comp + 1 ] )
            {
                hold = a[ comp ];
                a[ comp ] = a[ comp + 1 ];
                a[ comp + 1 ] = hold;
                swapCheck =1; // a swap has been made
            } // end if
            
            printf("%4d",a[ comp ]);
        } // end inner for
        
        printf("%4d\n",a[ comp ]) ; // print last array value
    } // end outer for
    
    // diplay array in sorted order
    printf("Data items in ascending order\n");
    
    for ( int j = 0; j < SIZE; j++ )
        printf("%4d", a[ j ]);
    
    // display the number of comparisons made
    printf("\nNumber of comparisons = %d\n",numberOfComp );
    return 0;
} // end main
