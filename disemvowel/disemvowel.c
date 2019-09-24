#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "disemvowel.h"


int nonVowelLengthAllocater(char const *str) {
    const char *invalid_chars = "AEIOUaeiou";
    char mystring[] = "This is my test string"; //mystring[]
    char *c = mystring;
    int vowel_count = 0;
  
    while(*c){
        if(strchr(invalid_chars, *c)){
            vowel_count++;
        }
        c++;
    }

    printf("Vowel count: %d\n", vowel_count);

    printf("Amount of nonvowels: %lu\n", strlen(mystring) - vowel_count);

    int len = strlen(mystring) - vowel_count;
  
    return len;
}

char *disemvowel(char const *str){
    const char *invalid_chars = "AEIOUaeiou";
    int length, i; 
    char *result;
    char const *c = str;

    length = nonVowelLengthAllocater(str);
    result = (char*) calloc(length+1, sizeof(char));

    for(i = 0; i < length; ++i){
        if(!strchr(invalid_chars, *str)){
            result[i] = str[i];
            c++;
        }
    }

    result[length] = '\0';

    printf("Disemvowel end result: %s\n", result);

    return result;
}

int main(int argc, char *argv[]) {
    char const the_string[] = "This is my test string";
    char *r;

    r = disemvowel(the_string);
    printf("Main returns: %s\n", r);
    free(r);
}
