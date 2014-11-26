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
BASE= 10			      ! declare constant base 10	
BYTE=4				      ! declare constant bytes long 4
One:
	.asciz "one" 		      !label for "One"
Two:
	.asciz "two"		      !	label for "Two"
Three:
	.asciz "three"		      ! label for "Three"	
Four:
	.asciz "four"		      ! label for "Four"
Five:
	.asciz "five"		      ! label for "Five"
Six:
	.asciz "six"			! label for "Six"
Seven:
	.asciz "seven"		      ! label for "Seven"
Eight:
	.asciz "eight"			! label for "Eight"
Nine:
	.asciz "nine"			! label for "Nine"
Zero:
	.asciz "zero"			! label for "Zero"
fmt:					! define fmt for print out format
	.asciz "%s "			! string formate= "%s " 
	.global Words			! delare string array word
	.align 4			! alignment 4
Words: .word Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine
					! initialize string array with each
					! string i declared
	.section ".text"		! declare text field
    	.global    printEnglish		! declare globale name
printEnglish:

	        save  %sp,  -(92 +4)&-8,  %sp  ! save all local variable

		

		st	%i0,	[%fp-4]   ! store the parameter to local stack
		ld	[%fp-4],  %l0	   ! load it to l0
		cmp	%l0,	BASE	   ! l0 with 10 
		bl	else		   ! if it's lower  branch to else
		nop

		ld	[%fp-4], %o0	   ! load argument to o0
		mov	BASE,	%o1	   ! move base to o1
		call 	.div		   ! get the value
		nop

		call	printEnglish	   ! call recursive call printENglish
		nop



else:
		ld	[%fp-4],  %o0	   ! load input argument to o0
		mov	BASE,	%o1        ! move base to o1
		call	.rem		   ! get the remainder
		nop

		mov	BYTE,	%o1	   ! move 4 to the o1
		call	.mul		   ! mulply the remainder with 4 so get teh total address it needs to move
		nop
	
		set	Words,	%o1	   ! set the start point of the string array to o1	
		add	%o1,	%o0,	%l0! move file pointer to the place
		ld 	[%l0],	%o1	   ! dereference the value stored in the address( a pointer in an array of pointer)
	
		set	fmt,	%o0	   ! set the print out format to o0
		
		call    printf		   ! call print f to print out the english
		nop			

		ret			   ! return 
		restore
			   


