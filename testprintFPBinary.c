/*
 * Unit Test for printFPBinary.s
 *
 * void printFPBinary( long num );
 *
 * Print num as binary with a space between every 4 bits. 
 */

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa3.h"        /* For printIntBinary() function prototype */

void
testprintFPBinary()
{

    printf( "Testing printFPBinary()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *printFPBinary* outputs.\n");
    printf( "They should match exactly!\n" );

    /*
     * Test with 0.
     */
    printf( "\nTesting with value 0 - should print:\n"
	    "0 00000000 00000000000000000000000\n" );

    printFPBinary( 0 );
    printf( "\n" );


    /*
     * Test with 1.
     */
    printf( "\nTesting with value 1 - should print:\n"
	    "0 01111111 111111111111111111111111\n" );

    printFPBinary( 1 );
    printf( "\n" );


    /*
     * Test with -1.
     */
    printf( "\nTesting with value -1 - should print:\n"
	    "1 01111111 11111111111111111111111\n" );

    printFPBinary( -1 );
    printf( "\n" );


    /*
     * Test with LONG_MAX.
     */
    printf( "\nTesting with value LONG_MAX - should print:\n"
	    "0 10011110 00000000000000000000000\n" );

    printFPBinary( LONG_MAX );
    printf( "\n" );


    /*
     * Test with LONG_MIN.
     */
    printf( "\nTesting with value LONG_MIN - should print:\n"
	    "0 10000101 11101101010010001011010\n" );

    printFPBinary( 123.321 );
    printf( "\n" );


    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0x8421A596 (13.5625) - should print:\n"
	    "1 10000010 10110010000000000000000\n" );

    /* printIntBinary( -2078169706 ); */
    printFPBinary( 13.5625 );
    printf( "\n" );

    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0x8421A596 (13.5625) - should print:\n"
	    "1 10000010 1011001000000000000\n" );

    /* printIntBinary( -2078169706 ); */
    printFPBinary( 13.5625 );
    printf( "\n" );

    /*
     * Test with -2078169706.
     */
    printf( "\nTesting with value 0x8421A596 (1.23456) - should print:\n"
	    "0 01111111 00111100000011000010000\n" );

    /* printIntBinary( -2078169706 ); */
    printFPBinary( 1.23456 );
    printf( "\n" );



}

int
main()
{
    testprintFPBinary();

    return 0;
}
