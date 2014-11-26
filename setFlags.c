  /*
   * Filename: setFlag.c
   * Author: Songjun Lin
   * Userid: cs30xhy
   * Description: get the user input and using getopt to
   *              get user flag. setting flag bit on or off
   *              based on user input. depends on the error
   *              flag differnet bit would be set on to show the
   *              the error and correspond error message would be 
   *              shown at the end. if no error's been detected
   *              the struct will be filled with values and return
   *              to main waiting for other method to process.
   * Date : 19/11/2014
   * source of Help: Stack overflow, google
   */


#include <stdio.h>
#include <string.h>
#include "pa3.h"
#include "strings.h"
#include <errno.h>
#define PA3 "pa3"
/*constant for this programme*/
#define BASE_TEN 10
#define BASE_MIN 2
#define BASE_MAX 36

/*
 *Function name: setFlags
 *Function prototype: struct setFlags(
 *    int argc, char* argv[])
 *Description: processing the user input by using checking range
 *             strToLong, also the other validation checking will be
 *             done at this stage. If it passes full validation checking
 *             a struct with full flag information will be returned 
 *             at the end
 *Parameters:   argc: the number of argument that user input
 *              argv[] : the full argument body that user input
 *Error Conditions:
 *              input value is too big
 *              input value is not an valid integer
 *              missing input parameter
 *              -f flag with other arugment
 *              
 *         
 *Return Value: struct argsInfo
 *
 */

struct argsInfo setFlags( int argc, char* argv[] ){
    /*struct for return*/
    struct argsInfo argsInfo;
    /*initialize the struct*/
    memset(&argsInfo,0,sizeof(argsInfo));
    /*temp var to hold inputbase string*/
    char* tempInputBase = NULL;
    /*temp var to hold outputbase string*/
    char* tempOutPutBase = NULL;
    /*character*/
    int c =0;
   /*get each opt -*/
    while ((c = getopt(argc, argv,STR_GETOPT_OPTIONS)) != -1) {
    /*case to evaluate each opt*/
      switch(c) {
            /*case c*/
            case 'h':
                 /*set h_mask to mode*/
                 argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
                 break;
            /*case f*/
            case 'f':
                /*get user input*/
                 argsInfo.inFileStr = optarg;
                 /*set r_mask to mode*/
                 argsInfo.mode= argsInfo.mode | READ_FILE_MASK;
                 break;
            /*case i*/
            case 'i':
                /*get user input*/
                 tempInputBase = optarg;
                 break;
            /*case o*/
            case 'o':
                 /*get user input*/
                 tempOutPutBase =optarg;
                 break;
            /*case e*/
            case 'e':
                   /*set p_mask to mode*/
                 argsInfo.mode =argsInfo.mode | PRINT_ENGLISH_MASK;
                 break;
            /*case b*/
            case 'b':
                   /*set f mask to mode*/
                 argsInfo.mode = argsInfo.mode | PRINT_FLOAT_MASK;
                 break;
             /*else*/
            default:
                /*set h mask to mode*/
                 argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
                 break;
      }
    }
    /*both file name and argument is been input*/
    if((argsInfo.mode&READ_FILE_MASK)==READ_FILE_MASK&&argc-optind>0){
         /*error message*/ 
         fprintf(stderr,STR_FILE_AND_ARGS_ERR);
         /*set h mask to mode*/
         argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
    }
    /*if input base is mentioned*/
    if(tempInputBase!= NULL){
        /*convert string to long*/
         long inputBaseNumber = strToLong(tempInputBase,BASE_TEN);
         /*if errno is EINVAL*/
         if(errno==EINVAL){
            /*error message*/
            (void)fprintf(stderr,STR_INBASE_ENDPTR_ERR,tempInputBase);
            /*set errno to 0*/
            errno =0;
            /*set h mask to mode*/
            argsInfo.mode =argsInfo.mode | H_FLAG_MASK;

         }
         /*if argument passes all the check*/
         else if(errno !=0){
            /*error message*/
            perror(tempInputBase);
            /*set errno to 0*/
            errno = 0;
            /*set h_flag_mask to mode*/
            argsInfo.mode =argsInfo.mode | H_FLAG_MASK;

         }
         /*if it passes all evaluation*/
         else{
              /*check the range*/
              int inputRangeValidation =
              checkRange(inputBaseNumber,BASE_MIN,BASE_MAX);
              /*if it's not in the range*/
              if(inputRangeValidation == 0){
                /*error message*/
                (void)fprintf
                (stderr,STR_INBASE_BAD_RANGE,
                inputBaseNumber,BASE_MIN,BASE_MAX); 
                /*set h_flag mask to mode*/
                argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
              }
              /*if it passes all evalutaion*/
              else{
                /*get the basenumber to input base*/
                argsInfo.inputBase = inputBaseNumber;
                /*set input mask to mode*/
                argsInfo.mode = argsInfo.mode | INPUT_MASK;
              }
         }
    }
    /*output flag is on*/
    if(tempOutPutBase !=NULL){
         /*saveptr for strtok_r*/
         char *saveptr;
         /*token hold the string*/
         char *token;
         /*long long hold patter*/
         long long outputPattern = 0;
         /*for loop to divide token*/
         for
         (token = strtok_r(tempOutPutBase,STR_OUTBASE_TOK_SEPARATOR,&saveptr);
         token!=NULL;
         token=strtok_r(NULL,STR_OUTBASE_TOK_SEPARATOR,&saveptr)){
              /*long variable hold strToLong return value*/
              long outputBaseNumber = strToLong(token,BASE_TEN);
              /*errno is EINVAL*/
              if(errno==EINVAL){
              /*error message*/
               (void) fprintf(stderr,STR_OUTBASE_ENDPTR_ERR,token);
                /*set errno to 0*/
                errno = 0;
                /*set H_FLAG_MASK to mode*/
                argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
                break;
              }
              /*errno is not EINVAL but not 0*/
              else if(errno !=0){
                /*error message*/
                perror(token);
                /*set errno to 0*/
                errno =0;
                /*set H_FLAG_MASK to mode*/
                argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
                break;
              }
              /*passed all evaluation*/
              else{
                /*check range*/
                int outputRangeValidation = 
                checkRange(outputBaseNumber,BASE_MIN,BASE_MAX);
                /*if it's not within range*/
                if(outputRangeValidation ==0){
                    /*error message*/
                    (void)fprintf(stderr,
                    STR_OUTBASE_BAD_RANGE,outputBaseNumber,BASE_MIN,BASE_MAX);
                    /*set h mask to mode*/
                    argsInfo.mode =argsInfo.mode | H_FLAG_MASK;
                    break;
                }
                /*temp hold the value return from BASE_MASK*/
                else{
                    long long temp = BASE_MASK(outputBaseNumber);
                    /*store it in outputPattern*/
                    outputPattern =(outputPattern | temp);
                }
              }  
         }
         /*output base equals to output pattern*/
        /* argsInfo.outputBases = outputPattern;*/
         if((argsInfo.mode & H_FLAG_MASK) !=H_FLAG_MASK){
            argsInfo.outputBases = outputPattern;  
            argsInfo.mode = argsInfo.mode | OUTPUT_MASK;
         }
  } 
    /*optind is greater thatn argc and inFileStr is equal to null*/
    if(optind>=argc && argsInfo.inFileStr==NULL){
        /*set h mask to mode*/
         argsInfo.mode=argsInfo.mode | H_FLAG_MASK;
         /*if mode is greater than h mask*/
         if(  argsInfo.mode> H_FLAG_MASK ){
            /*error message*/
            (void)fprintf(stderr,STR_NO_INPUT_ERR);
         }
    }
    /*if i is not mentioned*/
    if( tempInputBase == NULL){
          /*set input base to 10*/
          argsInfo.inputBase = 10;

    }
    /*return argsInfo*/
    return argsInfo;
}

