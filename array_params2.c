/**********************************************************
Array Parameters
- dimension, param, return, length

I. 1-D Array
  1. void
    1) no param
    2) param
      (1) length specified
      (2) length specified
  2. return
    1) no param
    2) param
      (1) length specified
      (2) length unspecified

II. 2-D Array
  1. void
    1) no param
    2) param
      (1) length specified
      (2) length unspecified
  2. return
    1) no param
    2) param
      (1) length specified
      (2) length unspecified
 **********************************************************/

#include <stdio.h>
#include <string.h>

void one_void_param_int(int ar[]) {
  ar[0] = 100;
  for (int i = 0; i < 3; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void one_void_param_int1(int ar[3]) {
  ar[0] = 100;
  for (int i = 0; i < 3; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void one_void_param_int2(int *ar) {
  ar[0] = 100;
  for (int i = 0; i < 3; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void one_void_param_int3(int *ar) {
  *ar = 100;
  // TODO: We don't know array size!
  for (int *p = ar; p <= &ar[2]; p++) {
    printf("%d ", *p);
  }
  printf("\n");
}

void one_void_param_int4(int *ar) {
  *ar = 100;
  for (int *p = ar; p <= &ar[2]; p++) {
    printf("%d ", *p);
  }
  printf("\n");
}

void one_void_param_char(char str[]) {
  *str = 'z';
  for (int i = 0; i < 3; i++) {
    printf("%c ", str[i]);
  }
  printf("\n");
}

void one_void_param_char1(char str[4]) {
  *str = 'z';
  for (int i = 0; i < 3; i++) {
    printf("%c ", str[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int iarr[3] = {0, 1, 2};
  int iarr2[2] = {0, 1};
  char carr[4] = "abc";

  one_void_param_int(iarr);    // 100 1 2
  one_void_param_int(iarr2);   // 100 1 100  // TODO: What is this?
  one_void_param_int1(iarr);   // 100 1 2
  one_void_param_int1(iarr2);  // 100 1 100 // TODO: What is this?
  one_void_param_int2(iarr);   // 100 1 2
  one_void_param_int3(iarr);   // 100 1 2
  one_void_param_int4(iarr2);  // 100 1 100 // TODO: What is this?

  one_void_param_char(carr);  // z b c
  one_void_param_char(carr);  // z b c

  return 0;
}