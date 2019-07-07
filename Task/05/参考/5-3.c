#include <stdio.h>
#include <math.h>

double calculateCharges( double hours ); /* function prototype */

int main()
{
    double h;                  /* number of hours for current car */
    double currentCharge;      /* parking charge for current car */
    double totalCharges = 0.0; /* total charges */
    double totalHours = 0.0;   /* total number of hours */
    int i;                     /* loop counter */
    int first = 1;             /* flag for printing table headers */
    
   // printf( "Enter the hours parked for 3 cars: " );
    
    /* loop 3 times for 3 cars */
    for ( i = 1; i <= 3; i++ ) {
        scanf( "%lf", &h );
        totalHours += h; /* add current hours to total hours */
        
        /* if first time through loop, display headers */
        if ( first ) {
            printf( "%5s%15s%15s\n", "Car", "Hours", "Charge" );
            
            /* set flag to false to prevent from printing again */
            first = 0;
        } /* end if */
        
        /* calculate current car's charge and update total */
        totalCharges += ( currentCharge =  calculateCharges( h ) );
        
        /* display row data for current car */
        printf( "%5d%15.1f%15.2f\n", i, h, currentCharge );
    } /* end for */
    
    /* display row data for totals */
    printf( "%5s%15.1f%15.2f\n", "TOTAL", totalHours, totalCharges );
    
    return 0; /* indicate successful termination */
    
} /* end main */

/* calculateCharges returns charge according to number of hours */
double calculateCharges( double hours )
{
    double charge; /* calculated charge */
    
    /* $2 for up to 3 hours */
    if ( hours < 3.0 ) {
        charge = 2.0;
    } /* end if */
    
    /* $.50 for each hour or part thereof in excess of 3 hours */
    else if ( hours < 19.0 ) {
        charge = 2.0 + .5 * ceil( hours - 3.0 );    //cei为数学函数，用于四舍五入求整
    } /* end else if */
    else { /* maximum charge $10 */
        charge = 10.0;
    } /* end else */
    
    return charge; /* return calculated charge */
    
} /* end function calculateCharges */
