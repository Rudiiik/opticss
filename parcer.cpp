//
//  parser.c
//


#include "parcer.h"

char* inputString(void) {
    char buff[1024];
    for (int i = 0; i<1024; i++)
        buff[i] = 0; 
    char* string1;
    unsigned long int length = 1;
    fgets(buff, 1024, stdin);
    length = strlen(buff);
    string1 = (char*)malloc((length)*sizeof(char));
    for (int i = 0; i<=length; i++) {
        string1[i] = buff[i];
    }
    if (string1[strlen(string1)-1] == '\n') {
        string1[strlen(string1)-1] = 0;
    }
    return string1;
}

char* brkFind (char* input, int n) {
    char* toSend;
    long int length = strlen(input);
    int beginCut = 0;
    int endCut = 0;
    int brksFound = 0;
    for (int i = 0; i<length; i++) {
        if (input[i] == ' ')
            brksFound++;
    }
    int* brkLinks = (int*)malloc(sizeof(int)*(brksFound+2));
    brkLinks[0] = 0;
    int j = 1;
    for (int i = 0; i<length; i++) {
        if (input[i] == ' ') {
            brkLinks[j] = i+1;
            j++;
        }
    }
    brkLinks[brksFound+1] = (int)length+2;
    beginCut = brkLinks[n-1];
    endCut = brkLinks[n]-2;
    toSend = (char*)malloc(sizeof(char)*(endCut-beginCut));
    for (int i = beginCut; i<=endCut; i++) {
        toSend[i-beginCut] = input[i];
    }
    free(brkLinks);
    return toSend;
}

char* fromWordToEnd (char* input, int n) {
    char* toSend;
    long int length = strlen(input);
    int beginCut = 0;
    long int endCut = length;
    int brksFound = 0;
    for (int i = 0; i<length; i++) {
        if (input[i] == ' ') {
            brksFound++;
            if (brksFound == n) {
                beginCut = i+1;
                break;
            }
        }
    }
    if (beginCut == endCut || brksFound == 0) {
        return NULL;
    }
    else {
        toSend = (char*)malloc(sizeof(char)*(endCut-beginCut+1));
        for (int i = beginCut; i<endCut; i++) {
            toSend[i-beginCut] = input[i];
        }
        toSend[endCut-beginCut] = '\0';
        return toSend;
    }
}
