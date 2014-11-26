/*
 * Filename: printFPBinary.s
 * Author: Songjun Lin
 * Userid: cs30xhy
 * Description: print a float value in it's 32 bits long
 *		binary form recursively by using program counter
 * Date: 	24/11/2014
 * Source of Help: google, stack overflow
 * Used registers: %l2 programme counter
 *		   %l3 store the most significant bit of bits
 */                
  .section   ".data"		!declare the section to text
   .global    printFPBinary	!declare the global label
	EXPONENT=8		!declare the lenth of exponent bits
	MANTISSA=23		!declare the length of mantissa bits
	ONE = 49		! ascii code for one
	ZERO = 48		! ascii code for zero
	MASK = 0x80000000	! bit mask to extract the most significant bit
	SPACE=32		! ASCII for " "
fmt:
	.asciz "%c"		! set the out put format
	.section ".text"	! declare the text section
printFPBinary:
	save  %sp,  -(92 +4)&-8,  %sp

	clr  	%l2		! counter for counting elements
				
	mov   	%i0,  %l1	! dereference first argument to %l1
	set   	MASK, %l3    	!set 0x80000000 as the mask
	and   	%l1, %l3, %l0	!get the most significant bit
	cmp	%l0,	%g0	! compare it with 0;
	be	printSignZero
	nop

	set   	fmt,  %o0	!set format to first arugment for printf
	mov	ONE,	%o1	!move ONE to second argument 
	call 	printf
	nop

	ba	end_if_sign
	nop

printSignZero:			!if the sign bit is 0
				
	set	fmt,	%o0	!set format to first argument for printf
	mov	ZERO,	%o1	!move ZERO to second argument
	call	printf		!call printf
	nop

end_if_sign:			
	set	fmt,	%o0	!set format to first argument for printf
	mov	SPACE,	%o1	! move space to second argument for print out
	call	printf		! call printf
	nop

	sll	%l1,	1,	%l1	! shift the float point value one left

loop:				! loop to print out the exponent bit
	and  %l1, %l3, %l4	!and the fist element in  array with mask
	cmp  %l4,  %g0		! compare the value with 0
	be   printExponentZero		! if it's 0 print 0
	nop

	mov  ONE,  %o1		! if it's not 0 print 1
	ba   end_if
	nop
printExponentZero:		! print 0 in exponent bit
	mov  ZERO,  %o1		! print 0

end_if:
	set  	fmt,  %o0	! set format to first parameter
	call 	printf		! call print char
	nop

	sll	%l1,	1,	%l1	! shift the float value one left toward

	inc 	%l2		! increment counter
        	

	cmp  	%l2,  EXPONENT	! compare counter with exponent length
	bl  	loop
	nop

	mov  	SPACE, %o1		! move space to the second argument
	set	fmt,  %o0		! set format to first argument
	call 	printf			! print out the space
	nop

	clr	%l2			! clear the counter
loop2:
	and  %l1, %l3, %l4		!and the fist element in  array with mask
	cmp  %l4,  %g0			! compare the value with 0
	be   printMantissaZero		! if it's 0 print 0
	nop

	mov  ONE,  %o1			! if it's not 0 print 1
	ba   end_if2
	nop
printMantissaZero:			! print 0 for mantissa bits.
	mov  ZERO,  %o1			! print 0

end_if2:
	set  	fmt,  %o0		!set format to first argument
	call 	printf			! call print 
	nop

	sll	%l1,	1,	%l1	! shift the float value one left forward

	inc 	%l2			! increment counter
        	

	cmp  	%l2,  MANTISSA		! compare o0 with 0
	bl  	loop2
	nop

	mov  	SPACE, %o1		! move the space to second argument of printf
	set	fmt,  %o0		! set format to o0
	call 	printf			! print out the space
	nop

	ret	
	restore
