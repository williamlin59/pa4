/*
 * Unit Test for processFPToken.c
 *
 * void processFPToken( long num );
 *
 * Print num as binary with a space between every 4 bits. 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa3.h"        /* For printIntBinary() function prototype */

void
testprocessFPToken()
{
    struct argsInfo temp;
    printf( "Testing processFPToken()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *processFPToken* outputs.\n");
    printf( "They should match exactly!\n" );

    /*
     * Test with 0.
     */

     /*temp.outputBases= 0x1FFFFFFFFE;*/
     temp.mode = 48;
    printf( "\nTesting with value 10.001 - should print:\n"
	    "\n" );

    processFPToken( "10.0001",temp );
    printf( "\n" );


    /*
     * Test with 1.
     */
    printf( "\nTesting with value -150.00234 - should print:\n"
	    "\n" );

    processFPToken( "-150.00234",temp );
    printf( "\n" );


    /*
     * Test with -1.
     */
    printf( "\nTesting with value 150.0000 - should print:\n"
	    "\n" );

    processFPToken("150.0000",temp );
    printf( "\n" );




    /*
     * Test with LONG_MIN.
     */
    printf( "\nTesting with value -123456789.1234567 - should print:\n"
	    "\n" );

    processFPToken("-123456789.1234567",temp );
    printf( "\n" );


    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0.005 - should print:\n"
	    "\n" );

    /* printIntBinary( -2078169706 ); */
    processFPToken( "0.005",temp );
    printf( "\n" );


}

int
main()
{
    testprocessFPToken();

    return 0;
}
