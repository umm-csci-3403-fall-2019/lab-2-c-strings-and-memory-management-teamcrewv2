#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "disemvowel.h"


char *disemvowel(char const *str) {
    const char *invalid_chars = "AEIOUaeiou";
    // char mystring[] = "Test test dog"; //mystring[]
    char const *str_copy = str;
    int vowel_count = 0;

    size_t i = 0;
    int j = 0;
  
    while(*str_copy){
        if(strchr(invalid_chars, *str_copy)){
            vowel_count++;
        }
        str_copy++;
    }

    int len = strlen(str) - vowel_count;

    char *result = (char*) calloc(len+1, sizeof(char));

    for(i=0; i < strlen(str); i++){
        if(!strchr(invalid_chars, str[i])){
            result[j] = str[i];
            j++;
        } 
    }

    result[len] = '\0';

    printf(result);
  
    return result;
}

int main(int argc, char *argv[]) {
    char const the_string[] = "Test test dog";
    char *t;

    t = disemvowel(the_string);

    free(t);

}


