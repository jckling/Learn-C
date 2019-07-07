#include <stdio.h>
int main()
{
    const int SIZE = 10; // size of array
    int a[ SIZE ];
    int hold;
    int numberOfComp = 0; // number of comparisons made
    int comp; // used to control for loop and for subscripts
    
    // display original, unsorted array
//    printf("Data items in original order\n");
    
    for ( int i = 0; i < SIZE; ++i )
        scanf("%d", &a[i]);
    
    // begin sorting the array
    for ( int pass = 1; pass < SIZE; pass++ )
    {
        printf("After pass %d :", pass - 1 );
        
        // traverse and compare unsorted part of array
        for ( comp = 0; comp < SIZE - pass; comp++ )
        {
            numberOfComp++;
            
            // compare adjacent array elements
            if ( a[ comp ] > a[ comp + 1 ] )
            {
                hold = a[ comp ];
                a[ comp ] = a[ comp + 1 ];
                a[ comp + 1 ] = hold;
            } // end if
            
            printf("%4d",a[ comp ]);
        } // end inner for
        
        printf("%4d\n",a[ comp ]) ; // print last array value
    } // end outer for
    
    // diplay array in sorted order
    printf("\nData items in ascending order\n");
    
    for ( int j = 0; j < SIZE; j++ )
        printf("%4d", a[ j ]);
    
    // display the number of comparisons made
    printf("\nNumber of comparisons = %d\n",numberOfComp );
    return 0;
} // end main
