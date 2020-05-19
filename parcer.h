//
//  parser.h 
//  

#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

char* inputString(void);
char* brkFind (char* input, int n);
char* fromWordToEnd (char* input, int n);

#endif /* parser_h */
