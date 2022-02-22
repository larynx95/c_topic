/*
https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
https://stackoverflow.com/questions/44407865/reading-two-long-sentences-using-scanf
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char a[100], b[100];
  scanf("%[^\n]%*c", a);
  scanf("%[^\n]%*c", b);
  printf("%s\n%s", a, b);
  return 0;
}