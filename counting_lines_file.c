/*
https://www.geeksforgeeks.org/c-program-count-number-lines-file/
*/

#include <stdio.h>
#define MAX_FILE_NAME 100

int main() {
  FILE *fp;
  int count = 0;
  char filename[MAX_FILE_NAME];
  char c;

  printf("Enter file name: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return 0;
  }

  for (c = getc(fp); c != EOF; c = getc(fp))
    if (c == '\n') count = count + 1;

  fclose(fp);

  printf("The file %s has %d lines\n ", filename, count);

  return 0;
}