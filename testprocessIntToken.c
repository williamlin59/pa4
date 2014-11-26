/*
 * Unit Test for processIntToken.c
 *
 * void processIntToken( long num );
 *
 * Print num as binary with a space between every 4 bits. 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa3.h"        /* For printIntBinary() function prototype */

void
testprocessIntToken()
{
    struct argsInfo temp;
    printf( "Testing processIntToken()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *processIntToken* outputs.\n");
    printf( "They should match exactly!\n" );

    /*
     * Test with 0.
     */

     temp.outputBases= 0x1FFFFFFFFE;
     temp.mode = 4;
    printf( "\nTesting with value 10 - should print:\n"
	    "\n" );

    processIntToken( "10",temp );
    printf( "\n" );


    /*
     * Test with 1.
     */
    printf( "\nTesting with value -150 - should print:\n"
	    "\n" );

    processIntToken( "-150",temp );
    printf( "\n" );


    /*
     * Test with -1.
     */
    printf( "\nTesting with value abcd - should print:\n"
	    "\n" );

    processIntToken("abcd",temp );
    printf( "\n" );




    /*
     * Test with LONG_MIN.
     */
    printf( "\nTesting with value 123456789 - should print:\n"
	    "\n" );

    processIntToken("123456789",temp );
    printf( "\n" );


    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0842 - should print:\n"
	    "\n" );
    processIntToken( "0842",temp );
    printf( "\n" );


    /*
     * Test with 1772454945.
     */
    printf( "\nTesting with value 1772454945 - should print:\n"
	    "\n" );

   processIntToken(" 1772454945",temp );
    printf( "\n" );
}

int
main()
{
    testprocessIntToken();

    return 0;
}
