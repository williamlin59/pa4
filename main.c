/*
 * Filename: main.c
 * Author: Songjun Lin
 * Userid: cs30xhy
 * Description: the main will get the user input from the command line
 *              pass it to setflags to initilize the varibles inside that
 *              struct. After that it will either open a file read from a file
 *              line by line or read from a command line and process them 
 *              based on the flag setting. Correspond error messages will be 
 *              printed out if any error occurs during the programme.
 * Date : 24/11/2014
 * source of Help: Stack overflow, google
 */
#include"pa3.h"
#include<errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "strings.h"
/*true value*/
#define TRUE 1
 /*
  *Function name: main
  *Function prototype: int main(
  *    int argc, char *argv[])
  *Description: the main function either read from a given file or command
  *             line, tokenlize it into each string and pass it to correspond
  *             functions based on if the string contains float point
  *             different output form will be raised based on the flag
  *Parameters:   argc: the amount of argument that user input
  *              argv[]: user input argements
  *Error Conditions:if user input is not a valid float point value or
  *                 integer value,the value is out of range.
  *Return Value:  TRUE(1)
  */

int main( int argc, char *argv[] ){
  /*make sure the buffer set correctly*/
  (void) setvbuf(stdout, NULL, _IONBF, 0);
  /*struct hold all the flag information*/
  struct argsInfo argsInfo=setFlags(argc,argv);
  /*pointer array hold pointer to each string*/
  char **dynamicString=NULL;
  /*initilize index to 0*/
  int index =0;
  /*get the optind*/
  int counter = optind;
  FILE *fp=NULL;
  /*if h flag is on*/
  if((argsInfo.mode & H_FLAG_MASK)!=0){
      /*error message*/
      (void)fprintf(stderr,STR_USAGE_MSG,argv[0]);
      /*exit the programme*/
      return TRUE;
  }
  /*case user input is valid*/
  else{
      /*case read from a file*/
      if((argsInfo.mode& READ_FILE_MASK) ==READ_FILE_MASK){
          /*file pointer to open the file*/
          fp = fopen(argsInfo.inFileStr,"r");
          /*pointer point to the malloc return value*/
          char *ptr =NULL; 
          /*temp string hold the each line from the file*/
          char temp[BUFSIZ];
          /*if file doesn't exist*/
          if(fp==NULL){
              /*file doesn't exist error message*/
              perror(argsInfo.inFileStr);
              /*exit the programme*/
              return TRUE;
          }
          /*read the file line by line*/
          while(fgets(temp,BUFSIZ,fp)!=NULL){
            /*save pointer for strtok_r*/
            char *saveptr;
            /*token hold each tokenlized string*/
            char  *token;
            /*for loop to tokenlize the string*/
            for(token = strtok_r(temp,STR_FILE_TOK_SEPARATOR,&saveptr);
                token!=NULL;

                    /*dynamic allocate memory for each token*/
                 token=strtok_r(NULL,STR_FILE_TOK_SEPARATOR,&saveptr)){
                 dynamicString =
                 (char**)realloc(dynamicString,sizeof(char*));      
                    /*dynamic allocate memory for each token*/
                 ptr = (char*)malloc((strlen(token)+1)*sizeof(char));
                    /*copy the token the the memory*/
                 strcpy(ptr,token);
                    /*assign the pointer the the pointer array*/
                 *(dynamicString+index)=ptr;
                    /*increment the index*/
                 index++;
             }
          }
      }
      /*case read from command line*/
      else{
          /*read from optind un argc*/
          while(counter<argc){
              /*realloc the memory for each user input token*/
              dynamicString =
              (char**)realloc(dynamicString,
              sizeof(char*));
              /*copy each user input string to the memory space*/
             // strcpy(*(dynamicString+index),argv[counter]);
             *(dynamicString+index) = argv[counter];
              /*increment the counter*/
             counter++;
              /*increment the index*/
             index++;
          }
      }
      /*loop through all the string in the dynamic allocated memory*/
      for(counter = 0; counter < index;counter++){
          /*if string contain float point*/
          if(strchr(dynamicString[counter],'.')==NULL){
            /* user input*/
            (void) fprintf(stdout,"\n%s\n",dynamicString[counter]);
            /*pass the string to processIntToken*/
            processIntToken(dynamicString[counter],argsInfo);
          }
          /*if string doesn't contain float point*/
          else{
            /*print out the user input value*/
            (void)fprintf(stdout,"\n%s\n",dynamicString[counter]);
            /*pass it to processFPToken*/
            processFPToken(dynamicString[counter],argsInfo); 
          }
          if(fp!=NULL){/*free the dynamic allocated memory*/
            free(dynamicString[counter]);
          }
          /*give up the access*/
          //dynamicString[counter] =NULL;
      }
      free(dynamicString);

  }
  /*return true*/
  return TRUE;
}
      
