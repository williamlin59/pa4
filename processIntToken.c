  /*
   * Filename: processIntToken.c
   * Author: Songjun Lin
   * Userid: cs30xhy
   * Description: get the user input from main and passed to setflags
   *             after that if the input string does not contains '.', it 
   *             will be
   *             passed to this processIntToken and be converted to 
   *             Integer value.Then depends on the flag bits, it will print
   *             out the Intteger value in  correpond base form or english form
   * Date : 24/11/2014
   * source of Help: Stack overflow, google
   */

#include <stdio.h>
#include "strings.h"
#include"pa3.h"
#include<errno.h>
/*base 10*/
#define BASE_TEN  10
/*max range of the base*/
#define RANGE 36
/*string minus*/
#define MINUS "minus "
/*
 *Function name: processIntToken
 *Function prototype: void processIntToken(
 *    char *inStr, struct argsInfo info)
 *Description: the function takes user input and argsInfo as two
 *           parameters. the input value will be converted to Integer
 *           if it is really a valid integer value.  and based on the
 *           flag stored in argsInfo struct it will either print out
 *           that integer value in correspond base form or english form
 *Parameters:   inStr: user input string
 *               argsInfo: all the flag values
 *Error Conditions:if user input is not a valid integer point value or
 *               the value is out of range.error message will be printed out
 *Return Value: none
 */

void processIntToken( char *inStr, struct argsInfo info){
  /*abs point to the first elemtn in the string*/
  char *abs =inStr;
  /*input hold the actual long value converted from strToLong*/
  long input;
  /*if the first character is -*/
  if(inStr[0]=='-'){
    /*increment pointer*/
    abs++;
  }
  /*convert the string to long*/
  input = strToLong( abs,info.inputBase);
  /*if user input is not a valid integer*/
  if(errno == EINVAL){
  /*error message*/
      (void)fprintf(stderr,STR_INBASE_ENDPTR_ERR,inStr);  
      /*set errno back to 0*/
      errno = 0;
  }
  /*user input is out of range*/

  else if(errno !=0){
      /*error message*/
      perror(inStr); 
      /*set errno back to 0*/
      errno = 0;
  }
 /*case user input is a valid integer*/
  else{
      /*if print english mask is on*/
      if((info.mode & PRINT_ENGLISH_MASK) ==PRINT_ENGLISH_MASK){
          /*input integer is lower than 0*/
          if(inStr[0]=='-'){
              /*print out string minus*/
              (void)fprintf(stdout,MINUS);
          } 
          /*print out the english form of input string*/
          printEnglish(input);
          /*new line character*/
          (void)fprintf(stdout,"\n");  
      }
      /*if user specified the out put base*/
      if((info.mode & OUTPUT_MASK) !=0){
          /*long long hold the mask */
          long long  mask = 2;
          /*counter count the digits through mask*/
          int counter = 1;
          /*trace through the range of digits*/
          while(counter<=RANGE){
              /*if the digit is on (1)*/
              if((mask & info.outputBases)!=0){
                    /*out put initialized as input value*/
                    int output =input;
                    /*second digits*/
                    if(counter ==2){
                        /*print out the binary form*/
                        printIntBinary(input);
                        /*new line character*/
                        (void)fprintf(stdout,"\n");  
                    }
                    /*other form*/
                    else{
                      /*user input is lower than 0*/
                      if(inStr[0]=='-'){
                        /*print out the minus sign*/
                        (void)fprintf(stdout,"-");
                      }
                      /*print out octal*/
                      if(counter == 8){
                        /*inital 0 for octal*/
                        (void)fprintf(stdout,"0");
                      }
                      /*print out hexdecimal*/
                      if(counter == 16){
                        /*initial 0x for hex*/
                        (void)fprintf(stdout,"0x");
                      }
                      /*call print base to print out the value based on given
                        base*/
                      printBase(output,counter);
                      /*new line character*/
                      (void)fprintf(stdout,"\n");  
                    }
              }
              /*shift teh mask 1 left forward*/
              mask = mask<<1;
              /*increment counter*/
              counter ++;
          }
      }
  }
}
