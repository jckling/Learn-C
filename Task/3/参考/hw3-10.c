/* Exercise 3.24 Solution */
 #include <stdio.h>

int main()
 {
     int counter; /* counter for 10 repetitions */
     int number; /* current number input */
     int largest; /* largest number found so far */
    
     /* get first number */
     //printf( "Enter the first number: " );
     scanf( "%d", &largest );
     counter = 2;
    
     /* loop 9 more times */
     while ( counter <= 10 ) {
       //  printf( "Enter next number: " ); /* get next number */
         scanf( "%d", &number );
        
         /* if current number input is greater than largest number,
             update largest */
         if ( number > largest ) {
             largest = number;
             } /* end if */
        
         counter++;
         } /* end while */
    
     printf( "Largest is %d\n", largest ); /* display largest number */
    
     return 0; /* indicate successful termination */
    
     } /* end main */