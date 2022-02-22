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

void one_void_no_param_int() {
  int arr[] = {0, 1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/*
void one_void_no_param_int1() {
  int *arr = {0, 1, 2, 3, 4};  // TODO: Can't do this!
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
*/

/*
void one_void_no_param_int2() {
  int *arr = (int *){0, 1, 2, 3, 4};  // TODO: can't do this!
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
*/

void one_void_no_param_int3() {
  int *arr = (int[]){0, 1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void one_void_no_param_int4() {
  int temp[] = {0, 1, 2, 3, 4};
  int *arr = temp;
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void one_void_no_param_int5() {
  int temp[5] = {0, 1, 2, 3, 4};
  int *arr = temp;
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void one_void_no_param_int6() {
  int temp[5] = {0, 1, 2, 3, 4};
  int *arr = temp;
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int *p = temp; p <= &temp[4]; p++) {
    printf("%d ", *p);
  }
  printf("\n");
}

void one_void_no_param_int7() {
  int *arr = (int[]){0, 1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(int);
  arr[0] = 100;
  for (int *p = arr; p <= &arr[4]; p++) {
    printf("%d ", *p);
  }
  printf("\n");
}

void one_void_noparam_char() {
  char str[] = "abcde";  // TODO: modifiable
  int size = sizeof(str) / sizeof(char);
  str[0] = 'z';
  for (int i = 0; i < size; i++) {
    printf("%c ", str[i]);
  }
  printf("\n");
}

void one_void_noparam_char1() {
  char *str = "abcde";  // TODO: can't be modified
  int size = sizeof(str) / sizeof(char);
  str[0] = 'z';
  for (int i = 0; i < size; i++) {
    printf("%c ", str[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  one_void_no_param_int();  // 100 1 2 3 4
  // one_void_no_param_int1();  // error
  one_void_no_param_int3();  // 100 1
  one_void_no_param_int4();  // 100 1
  one_void_no_param_int5();  // 100 1
  one_void_no_param_int6();  // 100 1 2 3 4
  one_void_no_param_int7();  // 100 1 2 3 4

  one_void_noparam_char();  // z b c d e
  // one_void_noparam_char1();  // error

  return 0;
}