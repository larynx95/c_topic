/*
Why it's bad to use feof() to control a loop

https://stackoverflow.com/questions/5431941/why-is-while-feoffile-always-wrong
*/

/* WARNING: demonstration of bad coding technique!! */

#include <stdio.h>
#include <stdlib.h>

FILE *Fopen(const char *path, const char *mode);

int main(int argc, char **argv) {
  FILE *in;
  unsigned count;

  in = argc > 1 ? Fopen(argv[1], "r") : Fopen("test.txt", "r");
  count = 0;

  /* WARNING: this is a bug */
  while (!feof(in)) { /* This is WRONG! */
    fgetc(in);
    count++;
  }
  printf("Number of characters read: %u\n", count);
  return EXIT_SUCCESS;
}

FILE *Fopen(const char *path, const char *mode) {
  FILE *f = fopen(path, mode);
  if (f == NULL) {
    perror(path);
    exit(EXIT_FAILURE);
  }
  return f;
}