/*
 * Filename: strToULong
 * Author: Songjun Lin
 * Userid: cs30xhy
 * Description: convert string to long, if number 
 *		is too big or there are characters in  
 *		change errno to non zero
 * Date:		28/10/2014
 * Source of Help: google, stack over flow
 */
	
	.section ".text"	!declare the section to text
	.global	strToLong	!declare a global label
	PTRSIZ = 4 		! PTRSIZ for the amount of pointers
	endptrOffset =4		! off set for endptr

strToLong:

	save 	%sp,   -(92+PTRSIZ)&-8,  %sp
	mov	%i0,	%o0		! move argument1 to o0
	add	%fp,	-4,	%o1	! move pointer to the offset(the end of pointer address)
	mov	%i1,	%o2		! move argument2 to o2
	call	strtol			! call strtoul
	nop

	mov	%o0,	%i0		! move return value to %io (return)
	

	ld	[%fp-endptrOffset],	%l0 !save the address to %l0
	ldub	[%l0],	%l0		!dereference the pointer
	cmp	%l0,	%g0		!compare the value with 0
	be	end_if			! if its zero return return value
	nop
		
	set 	errno,  %l0		! set error no address to %l0
	mov     22,   %l2
	st	%l2, [%l0]		! set ptrError to errno
	
end_if:
	ret				!return value
	restore
