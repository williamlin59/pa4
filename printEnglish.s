   /*
    * Filename: printEnglish
    * Author: Songjun Lin
    * Userid: cs30xhy
    * Description: this one will take a long number as a parameter
    *		   and using recursive to print out its english words
    *		   
    * Date:        19/11/2014
    * Source of Help: google, stack overflow
    * Used register:  %l0 for storing remainder
    *		       %fp for tracing array of pointer
    *		      %o0 for first output argument
    *		      %o1 for second output armgument
    */		

	.section   ".data"            !declare the section to data
BASE= 10
BYTE=4
One:
	.asciz "One" 		      !label for "One"
Two:
	.asciz "Two"		      !	label for "Two"
Three:
	.asciz "Three"		      ! label for "Three"	
Four:
	.asciz "Four"		      ! label for "Four"
Five:
	.asciz "Five"		      ! label for "Five"
Six:
	.asciz "Six"			! label for "Six"
Seven:
	.asciz "Seven"		      ! label for "Seven"
Eight:
	.asciz "Eight"			! label for "Eight"
Nine:
	.asciz "Nine"			! label for "Nine"
Zero:
	.asciz "Zero"			! label for "Zero"
fmt:					! define fmt for print out format
	.asciz "%s "			! string formate=
	.section ".text"		! declare text field
    	.global    printEnglish		! declare globale name
printEnglish:

	        save  %sp,  -(92 +44)&-8,  %sp  ! save all local variable

		set	One,	%l0	   ! set one to l0 register
		st	%l0,	[%fp-4]	   ! store it to array[0] 
		set     Two,	%l0        ! set two to l0 register
		st      %l0,	[%fp-8]	   ! store it to array[1]
		set	Three,	%l0	  ! set three to l0 register
		st	%l0,	[%fp-12]  ! store it ot array[2]
		set	Four,	%l0	   ! set four to l0 register
		st	%l0,	[%fp-16]   ! store it to array [3]
		set	Five,	%l0	   ! set five to l0 register
		st	%l0,	[%fp-20]   ! store it to array[4]
		set	Six,	%l0	   ! set six to l0 register
		st	%l0,	[%fp-24]   ! store it to array[5]
		set	Seven,	%l0	   ! set seven to l0 register
		st	%l0,	[%fp-28]   ! store it to array [6]
		set	Eight,	%l0	   !set eight to l0 register
		st	%l0,	[%fp-32]   ! store it to array [7]
		set	Nine,	%l0	   ! set nine to l0 register
		st	%l0,	[%fp-36]   ! store it to array [8]
		set	Zero,	%l0	   ! set zero to l0 register
		st	%l0,	[%fp-40]   ! store it to array [9]
		

		st	%i0,	[%fp-44]   ! store the parameter to local stack
		ld	[%fp-44],  %l0	   ! load it to l0
		cmp	%l0,	BASE	   ! l0 with 10 
		bl	else		   ! if it's lower  branch to else
		nop

		ld	[%fp-44], %o0	   ! load argument to o0
		mov	BASE,	%o1	   ! move base to o1
		call 	.div		   ! get the value
		nop

		call	printEnglish	   ! call recursive call printENglish
		nop



else:
		ld	[%fp-44],  %o0	   ! load input argument to o0
		mov	BASE,	%o1        ! move base to o1
		call	.rem		   ! get the remainder
		nop

		cmp	%o0,	%g0	   ! compare remainder with zero
		bne	print		   ! if it's not equal branch to print
		nop

		add	%o0,	BASE,	%o0! else add 10 to the remainder
print:
		mov	BYTE,	%o1	   ! move 4 to the o1
		call	.mul		   ! mulply the remainder with 4 so get teh total address it needs to move
		nop

		sub	%fp,	%o0,	%l0! move file pointer to the place
		ld 	[%l0],	%o1	   ! dereference the value stored in the address( a pointer in an array of pointer)
	
		set	fmt,	%o0	   ! set the print out format to o0
		
		call    printf		   ! call print f to print out the english
		nop			

		ret			   ! return 
		restore
			   


