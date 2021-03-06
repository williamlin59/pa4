   /*
    * Filename: printBase
    * Author: Songjun Lin
    * Userid: cs30xhy
    * Description: this file will take two parameter(userinput and base) as
    *		   the argument and print out the result recursively.
    *		   
    * Date:        24/11/2014
    * Source of Help: google, stack overflow
    * Used register:  %l0 for storing remainder
    *		       %fp for tracing array of pointer
    *		      %o0 for first output argument
    *		      %o1 for second output armgument
    */		

	.section   ".data"            !declare the section to data
	.global Word			! delare string array word
Word: .byte '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
! Word contains all the characters that printbase need to deal with differnet bases

fmt:	.asciz "%c"			!declare print out format
	.section ".text"		! declare text field
    	.global    printBase		! declare globale name
printBase:

	        save  %sp,  -(92 +8)&-8,  %sp  ! save all local variable

		

		st	%i0,	[%fp-4]   ! store the parameter to local stack
		st	%i1,	[%fp-8]	  !store the base to local stack
		ld	[%fp-4],  %l0	   ! load it to l0
		ld	[%fp-8],  %l1


		cmp	%l0,	%l1	   ! l0 with 10 
		bl	else		   ! if it's lower  branch to else
		nop

		ld	[%fp-4], %o0	   ! load argument to o0
		ld	[%fp-8], %o1	   ! move base to o1
		call 	.div		   ! get the value
		nop

		call	printBase   	   ! call recursive call printBase
		nop



else:
		ld	[%fp-4],  %o0	   ! load input argument to o0
		ld	[%fp-8],  %o1        ! move base to o1
		call	.rem		   ! get the remainder
		nop

		set	Word,	%o1	   ! set the start point of the string array to o1	
		add	%o1,	%o0,	%l0! move file pointer to the place
		ldub 	[%l0],	%o1	   ! dereference the value stored in the address( a pointer in an array of pointer)
	
		set	fmt,	%o0	   ! set the print out format to o0
		
		call    printf		   ! call print f to print out the english
		nop			

		ret			   ! return 
		restore
			   


