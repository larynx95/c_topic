/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // char buf[] = "abc/qwe/ccd";
  char *buf = strdup("abc/qwe/ccd");
  int i = 0;
  char *p = strtok(buf, "/");
  char *array[3];

  while (p != NULL) {
    array[i++] = p;
    p = strtok(NULL, "/");
  }

  for (i = 0; i < 3; ++i) printf("%s\n", array[i]);

  return 0;
}