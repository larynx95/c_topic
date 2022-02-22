/*
http://www.wellho.net/resources/ex.php4?item=c212/slurpit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *infile;
  char ln[121];
  char **info = NULL;
  int llen;
  int counter = 0;

  int backdown;

  infile = fopen("test.txt", "r");

  while (fgets(ln, 120, infile)) {
    // Allocate memory for pointer to ln just added
    info = realloc(info, (counter + 1) * sizeof(char *));
    // And allocate memory for that ln itself!
    llen = strlen(ln);
    info[counter] = calloc(sizeof(char), llen + 1);
    // Copy the ln just read into that memory
    strcpy(info[counter], ln);

    printf("%d characters in ln %d \n", llen, counter);
    counter++;
  }

  for (backdown = counter - 1; backdown >= 0; backdown--) {
    printf("%d: %s", backdown, info[backdown]);
  }

  fclose(infile);

  return 0;
}