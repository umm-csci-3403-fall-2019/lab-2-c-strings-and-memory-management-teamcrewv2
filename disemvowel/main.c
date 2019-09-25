#include <stdio.h>
#include <stdlib.h>
// #include "disemvowel.c"
#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  char* linDis;

  while (getline(&line, &size, stdin) > 0) {
    linDis = disemvowel(line);
    printf("%s\n", linDis);
    free(linDis);
  }
 free(line);
}

// int main(int argc, char *argv[]) {
//     char const the_string[] = "Test test dog";
    
//     char *t;
//     t = disemvowel(the_string);
//     free(t);

// }