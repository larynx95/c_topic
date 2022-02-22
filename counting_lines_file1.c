/*
counting number of lines in a file
(require command line argument)

https://stackoverflow.com/questions/3837800/what-is-the-fastest-way-to-count-lines-and-words-in-a-text-file-in-ansi-c/3837983#3837983
*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char** argv) {
  int newlines = 0;
  char buf[BUFSIZE];
  FILE* file;

  if (argc != 2) return 1;

  file = fopen(argv[1], "r");
  while (fgets(buf, BUFSIZE, file)) {
    if (!(strlen(buf) == BUFSIZE - 1 && buf[BUFSIZE - 2] != '\n')) newlines++;
  }

  printf("Number of lines in %s: %d\n", argv[1], newlines);
  return 0;
}