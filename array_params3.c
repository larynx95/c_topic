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
      (1) returns primitive value
      (2) returns array
        a. returning local array declared within fx.
          - (DONT) returning locally declared array variable
          - (char array only) returing string literal
          - using globally declared array variable
          - using a static array
          - explicitly allocated memory to hold the return value
          - caller allocates memory to hold return value
        b. storing, copying returned array
          - (DONT) assign operator (`=`)
          - copying each element one by one
          - memset, memcpy
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
#include <stdlib.h>
#include <string.h>

int one_ret_noparam_int() {
  // returns an integer value, not array
  return 100;
}

int one_ret_noparam_int1() {
  int arr[3] = {0, 1, 2};
  // returns an integer value, not array
  return arr[2];
}

/*
int *one_ret_noparam_arr() {
  int arr[3] = {0, 1, 2};
  return arr;  // TODO: error
}
*/

char *one_ret_noparam_arr1() {
  // returning string literal, not very useful
  return "This is string literal";
}

char global_carr[5];
char *one_ret_noparam_arr2() {
  global_carr[0] = 'a';
  global_carr[1] = 'b';
  global_carr[2] = 'c';
  global_carr[3] = 'd';
  global_carr[4] = '\0';
  return global_carr;
}

int *one_ret_noparam_arr3() {
  // actually, this fx is not so useful
  static int static_iarr[5] = {0, 1, 2, 3, 4};
  return static_iarr;
}

int *one_ret_noparam_arr4() {
  int *iarr = malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++) *(iarr + i) = i;
  return iarr;
}

int *one_ret_param_arr5(int *orig) {
  int *ptr = orig;
  int i = 0;
  for (; ptr < orig + 5; ptr++) *ptr = i++;
  return orig;
}

int main(int argc, char *argv[]) {
  printf("%d\n", one_ret_noparam_int());   // 100
  printf("%d\n", one_ret_noparam_int1());  // 2

  /********************************************************
    returning string literal value
  *********************************************************/

  printf("%s\n", one_ret_noparam_arr1());  // This is string literal

  /********************************************************
    using globally declared character variable
     - TODO: char and int are not always interchangeable!
  *********************************************************/

  int iarr[5];
  memcpy(iarr, one_ret_noparam_arr2(), sizeof(one_ret_noparam_arr2()));
  printf("%s\n", iarr);  // abcd

  for (int i = 0; i < 5; i++) printf("%c ", iarr[i]);
  printf("\n");  // result is not correltly printed, cuz type mismatch

  for (int *p = iarr; p <= &iarr[4]; p++) printf("%c ", *p);
  printf("\n");
  // result is not correltly printed, cuz type mismatch

  /********************************************************
    using globally declared character variable
     - correct type mismatching
  *********************************************************/

  char carr[5];
  memcpy(carr, one_ret_noparam_arr2(), sizeof(one_ret_noparam_arr2()));
  printf("%s\n", carr);  // abcd

  for (char i = 0; i < 5; i++) printf("%c ", carr[i]);
  printf("\n");

  for (char *p = carr; p <= &carr[4]; p++) printf("%c ", *p);
  printf("\n");

  /********************************************************
    using globally declared character variable
     - strncpy() fx.
  *********************************************************/

  char carr1[5];
  strncpy(carr1, one_ret_noparam_arr2(), 5);
  printf("%s\n", carr1);

  /********************************************************
    using statically declared array within function
  *********************************************************/

  for (int i = 0; i < 5; i++) printf("%d ", one_ret_noparam_arr3()[i]);
  printf("\n");  // 0 1 2 3 4

  int *iptr;
  memcpy(iptr, one_ret_noparam_arr3(), 5);
  for (int i = 0; i < 5; i++) printf("%d ", one_ret_noparam_arr3()[i]);
  printf("\n");  // 0 1 2 3 4

  int iarr1[5];
  memcpy(iarr1, one_ret_noparam_arr3(), 5);
  for (int i = 0; i < 5; i++) printf("%d ", one_ret_noparam_arr3()[i]);
  printf("\n");  // 0 1 2 3 4

  /********************************************************
    explicitly allocated memory to hold the return value
  *********************************************************/

  for (int i = 0; i < 5; i++) printf("%d ", one_ret_noparam_arr4()[i]);
  printf("\n");  // 0 1 2 3 4
  // TODO: How can the memory be freed?
  //       This is not good.

  int iarr2[5];
  memcpy(iarr2, one_ret_noparam_arr4(), 5 * sizeof(int));
  for (int i = 0; i < 5; i++) printf("%d ", iarr2[i]);
  printf("\n");  // 0 1 2 3 4

  /********************************************************
    caller allocates memory to hold return value
  *********************************************************/

  int *iarr3 = malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++) printf("%d ", one_ret_param_arr5(iarr3)[i]);
  free(iarr3);   // memory can be freed! good!
  printf("\n");  // 0 1 2 3 4

  return 0;
}