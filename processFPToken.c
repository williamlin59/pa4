 /*
  * Filename: processFPToken.c
  * Author: Songjun Lin
  * Userid: cs30xhy
  * Description: get the user input from main and passed to setflags
  *             after that if the input string contains '.', it will be
  *             passed to this processFPToken and be converted to 
  *             double value.Then depends on the flag bits, it will print
  *             out the float value in either binary form or english form
  * Date : 24/11/2014
  * source of Help: Stack overflow, google
  */
       

#include <stdio.h>
#include "strings.h"
#include"pa3.h"
#include<errno.h>
#include <string.h>
#include <stdlib.h>
/*base ten*/
#define BASE_TEN  10
/*the max range of digits that it can printout*/
#define RANGE 36\
/*string dot*/
#define DOT  "dot "
/*string zero*/
#define ZERO  "zero "
/*string minus*/
#define MINUS "minus "
 /*
  *Function name: processFPToken
  *Function prototype: void processFPToken(
  *    char *inStr, struct argsInfo info)
  *Description: the function takes user input and argsInfo as two
  *           parameters. the input value will be converted to double
  *           if it is really a valid double value.  and based on the
  *           flag stored in argsInfo struct it will either print out
  *           that double value in binary form or english form
  *Parameters:   inStr: user input string
  *               argsInfo: all the flag values
  *Error Conditions:if user input is not a valid float point value or
  *               the value is out of range.
  *Return Value: none
  */

void processFPToken( char *inStr, struct argsInfo info){
  /*end pointer for strtod to use*/
  char *endptr;
  /*flag value to show input value negtive or not*/
  int negtiveOrNot=0;
  /*double variable hold the return double value*/
  double input;

  /*set errno to 0*/
  errno =0;
  /*if input is negtive*/
  if(inStr[0]=='-'){
  /*flag on*/
    negtiveOrNot=1;
  }
  /*hold return double value*/
  input = strtod(inStr,&endptr);
  /*if the value is too large*/
  if(errno != 0){ 
      /*error message*/
      perror(inStr);
      /*set errno back to 0*/
      errno = 0;
      return;
  }
  /*case if input is not a valid number*/
  if(*endptr != '\0'){ 
      /*error message*/
      (void)fprintf(stderr,STR_FLOAT_ENDPTR_ERR,inStr);  
      /*set errno back to 0*/
      errno = 0;
      return;
  }
  /*case user no is a valid number*/
  else{
      /*if print english flag is on*/
      if((info.mode & PRINT_ENGLISH_MASK) ==PRINT_ENGLISH_MASK){
        /*pointer point to the rightSide of the decimal point*/
         char *rightSide=NULL;
         /*hold the value of the integer part of the double*/
         long integer =0;
         /*hold the value of the frganent part of the double value*/
         long decimal =0;
         /*find the decimal point in the string*/
         rightSide=strchr(inStr,'.');
          /*replace the decimal point with null character*/
         *rightSide='\0';
          /*move pointer right forward one*/
         (rightSide)++;
         /*if this is a negtive number*/
         if(negtiveOrNot ==1){
            /*print englisbh minus out*/
            (void)fprintf(stdout,"%s",MINUS);
            /*move the pointer right forward one*/
            inStr++;
         }
         /*convert the left integer part to integer*/
         integer = strToLong(inStr,BASE_TEN);
         /*convert the right integer part to integer*/
         decimal = strToLong(rightSide,BASE_TEN);
        /* call printEnglish to print the left integer part*/
         printEnglish(integer);
         /*print out the string dot in the middle*/
        (void) fprintf(stdout,DOT);
        /*print out the initial 0 for the right part of decimal point*/
         while(*rightSide=='0'){
            /*print out string zero*/
           (void) fprintf(stdout,"%s",ZERO);
           /*increment pointer*/
            rightSide++;
         }
         /*once the value is not equal to 0*/
         if(decimal!=0){
            /*print out the english string for the non zero part*/
            printEnglish(decimal);
         }
         /*print out new line character*/
         (void)fprintf(stdout,"\n");

      } 
      /*case print float mask is on*/
      if((info.mode & PRINT_FLOAT_MASK) !=0){
          /*print double value in binary form*/
          printFPBinary(input);
          /*new line character*/
         (void) fprintf(stdout,"\n");
      }
  }
}
