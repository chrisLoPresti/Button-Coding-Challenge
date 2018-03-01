#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/* allows us to find where the error in the input is visuaslly */
void printError(char * ptr, int move){
    
    if( move ==1 ){
        
        ++ptr;
    }
    printf("--> ");
    while(*ptr != '\0'){
        
        printf("%c", *ptr);
        ++ptr;
    }
    printf("\n");
    exit(0);
}
/* recursively find our total */

/* input is the string we will be referencing, delimExpected = 1 for expecting a deliminator and 0 otherwise */
int evaluate(char * input,int delimExpected){
    
    char * ptr = input;
    
    /* throw the first character of our shrinking string(from left to right)into a switch statement */
    switch (*ptr) {/* Switch statemnts run faster then if else statements due to jump commands */
            
        case '+':
            /* if we expect a '+' but found a deliminator, thats an error */
            if(delimExpected){
                
                printf("Inproper Deliminator used ");
                printError(ptr, 0);
            }
            /* return the evaluated expression
             * in the case we are given "+" or "+ " "+ 3" or "+ 3 " these will be error as the grammer clearly states <Operator> <Expression> <Expression>
             */
            return evaluate(ptr+1, 1) + evaluate(ptr+3, 1);
            
            break;
            
        case '-':
            /* if we expect a '-' but found a deliminator, thats an error */
            if(delimExpected){
                
                printf("Inproper Deliminator used ");
                printError(ptr, 0);
            }
            /* return the evaluated expression
             * in the case we are given "-" or "- " "- 3" or "- 3 " these will be error as the grammer clearly states <Operator> <Expression> <Expression>
             */
            return evaluate(ptr+1, 1) - evaluate(ptr+3, 1);
            
            break;
            
        case ' ':
            /* if we are given a deliminator, we want to make sure its a single space character
             * we also want to make sure we are expecting a deliminator at this point in the input string
             * if we are not it is an error, exit the program, and print out the faulty deliminator
             */
            if(delimExpected){
                
                return evaluate(ptr+1, 0);
                
            }else{
                
                printf("Expected an expression ");
                printError(ptr, 0);
            }
            /* we have found a digit so evaluate it  */
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            
            /* if we expect a deliminator but found a digit, thats an error */
            if(delimExpected){
                
                printf("Inproper Deliminator used ");
                printError(ptr, 0);
                exit(0);
            }
            /*  we found that we completed our expression ie: <operator> <grammer> <grammer> --> <operator> <digit> <digit>
             * however, this check will make sure if more input follows, if so, the inpout string does not properly follow the gramemr rules
             * it is an error so we must exit
             * i have it print out from where the error starts onward
             * example + 3 4 + 5 6 will print Invalid input, found -> + 5 6 because + 3 4 has no more right most derivation
             */
            if(isdigit(*(ptr -2)) && *(ptr+1) != '\0'){
                
                printf("Invalid input, found ");
                printError(ptr, 1);
            }
            /* passed all checks, return the value */
            return atoi(ptr);
            
            /* we have found something unexpected that does not belong in our grammer */
        default:
            
            if(*ptr == '\0'){
                
                printf("Expected a valid expression, found -> '\\0'\n");
                
            }else{
                
                printf("Expected a valid expression, found ");
                printError(ptr, 0);
            }
            
            exit(0);
    }
}

int main(int argc, char** argv){
    
    /* If thee is more or less then two arguements, that is invalid input  (The executable itself is 1 arguement) */
    if(argc != 2){
        
        printf("Invalid Numnber of Arguements\n");
        exit(0);
    }
    /* grammer clearly states <Operator> <Expression> <Expression>
     * if the the input does not start with + or - it is invalid input
     */
    if(*argv[1] != '+' && *argv[1] != '-'){
        
        printf("Invalid Input\n");
        exit(0);
    }
    /* take our arguement and have a pointer point to it */
    char* input = argv[1];
    /* recursively find our total */
    int result = evaluate(input,0);
    /* print out the input string and the resulting total from the evaluated expression */
    printf("Input: %s\n",input);
    printf("result of input: %d\n", result);
    
    return 0;
}



