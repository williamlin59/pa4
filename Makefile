#
# Makefile template for CSE 30 -- PA3
#

#
# You need to change these next three lines for each assignment
#

HEADERS		= pa3.h

ASM_SRCS	= printEnglish.s printIntBinary.s printBase.s printFPBinary.s \
		  checkRange.s strToLong.s

C_SRCS		= main.c processIntToken.c processFPToken.c setFlags.c

OBJS		= main.o printEnglish.o printIntBinary.o printBase.o \
		  printFPBinary.o processIntToken.o processFPToken.o \
		  checkRange.o setFlags.o strToLong.o

EXE		= pa3

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
#
# man -M /software/common/gnu/man gcc
# man -M /software/common/gnu/man as
# man -M /opt/SUNWspro/man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn -m -D__EXTENSIONS__
LINT_FLAGS2	= -u -err=warn -m -x
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:	
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default "a.out" executable.
#

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -O -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o a.out *.ln core $(EXE)
	@echo ""
	@echo "Clean."

new:
	make clean
	make

testprintIntBinary: test.h pa3.h testprintIntBinary.c printIntBinary.s
	@echo "Compiling testprintIntBinary.c"
	gcc -g -o testprintIntBinary testprintIntBinary.c printIntBinary.s
	@echo "Done."

runtestprintIntBinary: testprintIntBinary
	@echo "Running testprintIntBinary"
	@./testprintIntBinary

# Add your Unit Tests here.


testprintEnglish: test.h pa3.h testprintEnglish.c printEnglish.s
	@echo "Compiling testprintEnglish.c"
	gcc -g -o testprintEnglish testprintEnglish.c printEnglish.s
	@echo "Done."



runtestprintEnglish: testprintEnglish
	@echo "Running testprintEnglish"
	@./testprintEnglish
