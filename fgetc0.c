/*
`fgetc()`: Reads the next character from stdin
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ch;
  /* read/print "abcde" from stdin */
  while ((ch = getchar()) != EOF) printf("%c", ch);
  /* EOF is Ctrl-Z */

  /* Test reason for reaching EOF. */
  if (feof(stdin)) /* if failure caused by end-of-file condition */
    puts("End of file reached");
  else if (ferror(stdin)) /* if failure caused by some other error      */
  {
    perror("getchar()");
    fprintf(stderr, "getchar() failed in file %s at line # %d\n", __FILE__,
            __LINE__ - 9);
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}