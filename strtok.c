/*
`strtok()`: Split a string into tokens
https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
*/

#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "strtok needs to be called several times to split a string";
  int init_size = strlen(str);
  char delim[] = " ";

  char *ptr = strtok(str, delim);

  while (ptr != NULL) {
    printf("'%s' %d\n", ptr, sizeof(ptr));
    ptr = strtok(NULL, delim);
  }

  /* This loop will show that there are zeroes in the str after tokenizing */
  for (int i = 0; i < init_size; i++) {
    printf("%d ", str[i]);
    /* Convert the character to integer, in this case the character's ASCII
     * equivalent */
  }
  printf("\n");

  return 0;
}