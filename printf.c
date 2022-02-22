/*
`printf("%s", char* ptr)`
https://en.cppreference.com/w/c/io/fprintf

https://stackoverflow.com/questions/6799470/can-a-pointer-to-a-string-be-used-in-a-printf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char* ptr = strdup("forum.falinux.com");
  printf("%s\n", ptr);
  // printf("%s\n", *ptr);
}
