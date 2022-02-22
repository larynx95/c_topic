/*
https://stackoverflow.com/questions/44407865/reading-two-long-sentences-using-scanf
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ch;
  char s[50];
  char sen[100];

  fgets(sen, sizeof(sen), stdin);
  fflush(stdin);  // or `scanf("%c",&temp);` // temp statement to clear buffer
  printf("%s", sen);

  /* another example */
  char a[100] = "";
  char b[100] = "";
  fgets(a, 100, stdin);
  fgets(b, 100, stdin);

  // if needed, strip newlines, e.g. like this:
  size_t n = strlen(a);
  if (n && a[n - 1] == '\n') a[--n] = 0;
  n = strlen(b);
  if (n && b[n - 1] == '\n') b[--n] = 0;

  printf("%s\n%s", a, b);

  return 0;
}
