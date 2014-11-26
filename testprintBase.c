/*
 * Unit Test for printBase.s
 *
 * void printBase( long num );
 *
 * Print num as binary with a space between every 4 bits. 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa3.h"        /* For printIntBinary() function prototype */

void
testprintBase()
{

    printf( "Testing printBase()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *printBase* outputs.\n");
    printf( "They should match exactly!\n" );

    /*
     * Test with 0.
     */
    printf( "\nTesting with value 0 - should print:\n"
	    "0\n" );

    printBase( 0,10 );
    printf( "\n" );


    /*
     * Test with 1.
     */
    printf( "\nTesting with value 1 - should print:\n"
	    "1\n" );

    printBase( 1,10 );
    printf( "\n" );


    /*
     * Test with -1.
     */
    printf( "\nTesting with value -1 - should print:\n"
	    "15000\n" );

    printBase( 200000,20 );
    printf( "\n" );


    /*
     * Test with LONG_MAX.
     */
    printf( "\nTesting with value LONG_MAX - should print:\n"
	    "2471894534\n" );

    printBase( LONG_MAX,10 );
    printf( "\n" );


    /*
     * Test with LONG_MIN.
     */
    printf( "\nTesting with value 20 - should print:\n"
	    "1\n" );

    printBase( 20,20 );
    printf( "\n" );


    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 10 - should print:\n"
	    "C\n" );

    /* printIntBinary( -2078169706 ); */
    printBase( 10,12 );
    printf( "\n" );


    /*
     * Test with 1772454945.
     */
    printf( "\nTesting with value 36 - should print:\n"
	    "1\n" );

    printBase( 36,36 );
    /* printIntBinary( 0x69A58421 ); */
    printf( "\n" );



    /*
     * Cycle thru power of 2 values shift 1 bit left all the way across.
     * Then set all bits to 1 and shift a 0 bit right all the way across.
     *
     */

}
int
main()
{
    testprintBase();

    return 0;
}
