/*
counting number of lines in a file

https://codereview.stackexchange.com/questions/156477/c-program-to-count-number-of-lines-in-a-file

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(void) {
  const char filename[] = "test.txt";
  FILE *in_file;
  char str[MAX_LENGTH + 1], lastchar = '\n';
  size_t bytes;
  int lines = 0;

  if (NULL == (in_file = fopen(filename, "r"))) {
    perror(filename);
    return EXIT_FAILURE;
  }

  while ((bytes = fread(str, 1, sizeof(str) - 1, in_file))) {
    lastchar = str[bytes - 1];
    for (char *c = str; (c = memchr(c, '\n', bytes - (c - str))); c++) {
      lines++;
    }
  }
  if (lastchar != '\n') {
    lines++; /* Count the last line even if it lacks a newline */
  }

  if (ferror(in_file)) {
    perror(filename);
    fclose(in_file);
    return EXIT_FAILURE;
  }

  fclose(in_file);

  printf("Number of lines in the file is %i\n", lines);
}