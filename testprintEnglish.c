/*
 * Unit Test for printEnglish.s
 *
 * void printEnglish( long num );
 *
 * Print num as binary with a space between every 4 bits. 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa3.h"        /* For printIntBinary() function prototype */
/*void printEnglish(long num);*/
void
testprintEnglish()
{

    printf( "Testing printEnglish()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *printEnglish* outputs.\n");
    printf( "They should match exactly!\n" );

    /*
     * Test with 0.
     */
    printf( "\nTesting with value 0 - should print:\n"
	    "Zero\n" );

    printEnglish( 0 );
    printf( "\n" );


    /*
     * Test with 1.
     */
    printf( "\nTesting with value 123 - should print:\n"
	    "One Two Three\n" );

    printEnglish( 123 );
    printf( "\n" );


    /*
     * Test with -1.
     */
    printf( "\nTesting with value 10 - should print:\n"
	    "One Zero\n" );

    printEnglish( 10 );
    printf( "\n" );


    /*
     * Test with LONG_MAX.
     */
    printf( "\nTesting with value 123 - should print:\n"
	    "One Two Three Four Five\n" );

    printEnglish( 12345 );
    printf( "\n" );


    /*
     * Test with LONG_MIN.
     */
    printf( "\nTesting with value 123321 - should print:\n"
	    "One Two Three Three Two One\n" );

    printEnglish( 123321 );
    printf( "\n" );


    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0x8421A596 (2078169706) - should print:\n"
	    "Two Zero Seven Eight One Six Nine Seven Zero Six\n" );

    /* printIntBinary( -2078169706 ); */
    printEnglish( 2078169706 );
    printf( "\n" );


    /*
     * Test with 1772454945.
     */
    printf( "\nTesting with value 0x69A58421 (1772454945) - should print:\n"
	    "One Seven Seven Two Four Five Four Nine Four Five\n" );

    printEnglish( 1772454945  );
    /* printIntBinary( 0x69A58421 ); */
    printf( "\n" );


     }

int
main()
{
    testprintEnglish();
    return 0;
}
