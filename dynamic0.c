/*
https://www.quora.com/How-do-I-read-in-a-txt-file-into-a-dynamically-allocated-string-array-in-C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fptr = fopen("test.txt", "r");
  char line[80];
  char *dam = calloc(1000, sizeof(char));
  while (fscanf(fptr, "%79[^\n]\n", line) == 1) {
    strcat(dam, line);
    strcat(dam, "\n");
  }
  fclose(fptr);
  printf("%s", dam);

  return 0;
}