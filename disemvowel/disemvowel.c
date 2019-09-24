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

    int i;
    i = 0;
  
    while(*c){
        if(strchr(invalid_chars, *c)){
            vowel_count++;
            // printf("%c\n", mystring[i]);
        }
        c++;
        i++;
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

    i = 0;

    length = nonVowelLengthAllocater(str);
    printf("Length: %lu\n", length);
    result = (char*) calloc(length+1+1+5, sizeof(char));

    while(*c){
        if(!strchr(invalid_chars, *c)){
            result[i] = str[i];
            printf("%c\n", str[i]);
        }
        c++;
        i++;
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
