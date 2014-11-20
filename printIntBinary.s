/*
 * Filename: printIntBinary.s
 * Author: Songjun Lin
 * Userid: cs30xhy
 * Description: print a long value in it's 32 bits long
 *		binary form
 * Date: 	19/11/2014
 * Source of Help: google, stack overflow
 * Used registers: %l2 programme counter
 *		   %l3 store the most significant bit of bits
 */                
  .section   ".data"		!declare the section to text
   .global    printIntBinary	!declare the global label
	BIT_LONG = 32		! Bit_Long shows how many bits it has
	ONE = 49		! ascii code for one
	ZERO = 48		! ascii code for zero
	MASK = 0x80000000	! bit mask to extract the most significant bit
	SPACE=32		! ASCII for " "
fmt:
	.asciz "%c"		! set the out put format
	.section ".text"	! declare the text section
printIntBinary:
	save  %sp,  -(92 +4)&-8,  %sp

	clr  %l2		! counter for counting elements
				
	mov   %i0,  %l1	! dereference first argument to %l1
loop:
	set  MASK, %l3    !set 0x80000000 as the mask
	and  %l1, %l3, %l3	!and the fist element in  array with mask
	cmp  %l3,  %g0		! compare the value with 0
	be   printzero		! if it's 0 print -
	nop

	mov  ONE,  %o1		! if it's not 0 print 1
	ba   end_if
	nop
printzero:
	mov  ZERO,  %o1		! print 0

end_if:
	set  	fmt,  %o0
	call 	printf		! call print char
	nop

	inc 	%l2		! increment counter
	mov   	%l2,  %o0	! move counter to o0 for testing if it's divisible by 4	
	mov  	4,    %o1	! move 4 to o1	
	call 	.rem		!compare the remainder of counter/4 to 0
	nop			! to see if it needs to print out " "
	
	
	cmp  	%o0,  %g0	! compare o0 with 0
	bne  	end_if2
	nop

	mov  	SPACE, %o1		! if it's divisible by 4 print out space
	set	fmt,  %o0		! set format to o0
	call 	printf			! print out the space
	nop

end_if2:
	
	sll %l1,  1, %l1	!shift one bit left for l1
	cmp  %l2,   BIT_LONG	! compare counter with BIT Long
	bl   loop		! if is lower, go back to loop1
	nop



end_loop:

	ret			! return  
	restore
