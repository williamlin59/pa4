/*
 * Unit Test for printIntBinary.s
 *
 * void printIntBinary( long num );
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

    printf( "Testing printIntBinary()\n\n" );

    printf( "First line in each group below is the *expected* output.\n" );
    printf( "Second line in each group is what *printIntBinary* outputs.\n");
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
    printf( "\nTesting with value 1 - should print:\n"
	    "One\n" );

    printEnglish( 1 );
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
	    "One Two Three\n" );

    printEnglish( 123 );
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


    /*
     * You can use the Unix command bc (basic calculator) for more.
     *
     * % bc
     * obase=2
     * 1772454945
     * 1101001101001011000010000100001
     * ^D  <Control>-D
     */

    /*
     * Cycle thru power of 2 values shift 1 bit left all the way across.
     * Then set all bits to 1 and shift a 0 bit right all the way across.
     *
     */

   /* {
      unsigned long int i;

      printf( "\nCycle a 1 bit across right to left:\n" );
      for( i = 1; i != 0; i = i << 1 )
      {
	printf( "%11ld\t", i );
	printIntBinary( i );
	printf( "\n" );
      }

      printf( "\nSet all bits to 1 and shift 0's left to right:\n" );
      for( i = -1; i != 0; i = i >> 1 )
      {
	printf( "%11ld\t", i );
	printIntBinary( i );
	printf( "\n" );
      }

    }


    printf( "\n\nFinished running tests on printIntBinary()\n" );
*/
}

int
main()
{
    testprintEnglish();
    return 0;
}
