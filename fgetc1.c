/*
`fgetc()`: Reads the next character from stdin
https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rtref/getc.htm
*/

#include <stdio.h>

#define LINE 80

int main(void) {
  char buffer[LINE + 1];
  int i;
  int ch;

  printf("Please enter string\n");

  /* Keep reading until either:
     1. the length of LINE is exceeded  or
     2. the input character is EOF  or
     3. the input character is a new-line character
  */

  for (i = 0; (i < LINE) && ((ch = getchar()) != EOF) && (ch != '\n'); ++i)
    buffer[i] = ch;

  buffer[i] = '\0'; /* a string should always end with '\0' ! */

  printf("The string is %s\n", buffer);
}