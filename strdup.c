/*
`strdup()`: Returns a pointer to a null-terminated byte string, which is a
duplicate of the string pointed to by str1. The returned pointer must be passed
to free to avoid a memory leak.
https://en.cppreference.com/w/c/experimental/dynamic/strdup
*/

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char *s1 = "String";
  char *s2 = strdup(s1);
  printf("%s %s", s1, s2);
  assert(strcmp(s1, s2) == 0);
  free(s2);
}