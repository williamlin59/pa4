/*
 * Filename : checkRange.s
 * Author: Songjun Lin
 * Userid: cs30xhy
 * Description: print out if an input is in the range (inclusive)
 * Date : 14/02/2014
 * Sources of Help: google stack overflow
 *
 */


	.global checkRange	!  Declares the symbol to be globally visible so
	                        ! we can call this function from other modules.
	.section ".text"        ! The text segment begins here

/*
 *
 * Function name: checkRange()
 * Function prototype: int checkRange(long int, long minRange, long maxRange )
 * Description: return 1 if it is in the range. return 0 if it is not in the range
 * Parameter:
 *	number: long --the actual number for checking
 *	maxRange: int --the ceiling value of the range
 *	minRange: int -- the ground value of the range
 * Return value: 0 or 1
 * Registers Used:
 *	%o0 - the actual number for checking
 *	%o1 - the ceiling value of the range
 *	%o2 - the ground value of the range
 *
 */
checkRange:

	save	%sp,	-96,	%sp	! magic code
	mov	%i0,	%o0		! copy first value of parameter to %o0
	mov	%i1,	%o1		! copy second value of parameter to %o1
	mov	%i2,	%o2		! copy second value of parameter to %o3
	cmp	%o0,	%o1		! compare %o0 and %o1
	bl	else			! if %o0 greater thatn %o1 branch to else.
	nop				! delay slot
	
	cmp	%o0,	%o2		! compare %o0 and %o2
	bg	else			! if %o0 is greater than o2 branch to else.
	nop				! delay slot

	mov	1,	%i0		! if condition if value is within range
					! set %i0 as 1
	ba	end_if			! finish if condition
	nop				! delay slot
else:
	mov	0,	%i0		! if value is outside the range move0 to %i0
end_if:
	ret				! finish function
	restore


