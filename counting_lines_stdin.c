/*
https://stackoverflow.com/questions/12591664/c-program-that-counts-words-and-lines-in-standard-input
*/

#include <stdio.h>

int main() {
  int iochar;
  int words;
  int lines;

  printf("Enter something here:\n\n");

  while ((iochar = getchar()) != EOF) {
    if ((iochar == ' ') || (iochar == '\t') || (iochar == '\n')) {
      putchar(iochar);
    }
  }
  return 0;

  return 0;
}