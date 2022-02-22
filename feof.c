/*
`feof()`
https://modoocode.com/51
https://en.cppreference.com/w/c/io/feof
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE* fp = fopen("test.txt", "r");
  if (!fp) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int c;  // note: int, not char, required to handle EOF
  while ((c = fgetc(fp)) != EOF) {  // standard C I/O file reading loop
    putchar(c);
  }

  if (ferror(fp))
    puts("I/O error when reading");
  else if (feof(fp))
    puts("End of file reached successfully");

  fclose(fp);

  char* ptr;

  ptr = strdup("forum.falinux.com");
  printf("%s\n", ptr);
}
