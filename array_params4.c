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

#define ROWS 2
#define COLS 2

void print_2d_arr(int rows, int cols, int arr[ROWS][COLS]);  // helper fx.
void print_2d_arr1(int rows, int cols, int arr[][COLS]);
// void print_2d_arr2(int rows, int cols, int arr[][]);
void print_2d_arr3(int rows, int cols, int *arr);
void print_2d_arr4(int rows, int cols, int (*)[COLS]);
void print_2d_arr5(int rows, int cols, int (*arr)[cols]);
// void print_2d_arr6(int rows, int cols, int **arr);  // incorect, array decay

/**********************************************************
  practicing
***********************************************************/

void two_void_noparam() {
  int arr[2][2] = {{0, 1}, {2, 3}};
  printf("just print arr[0][1]: %d\n", arr[0][1]);
}

void two_void_param(int arr[2][2]) {
  arr[0][1] = 100;
  printf("%d\n", arr[0][1]);
}

void two_void_param1(int arr[][2]) {
  arr[1][1] = 200;
  printf("%d\n", arr[1][1]);
}

/**********************************************************
  main function
***********************************************************/

int main(int argc, char *argv[]) {
  two_void_noparam();
  int arr[2][2] = {{0, 1}, {2, 3}};

  two_void_param(arr);
  print_2d_arr(2, 2, arr);
  print_2d_arr1(2, 2, arr);
  // print_2d_arr2(2, 2, arr);
  // print_2d_arr3(2, 2, arr);
  print_2d_arr4(2, 2, arr);
  print_2d_arr5(2, 2, arr);

  int matrix[2][4] = {{11, 22, 33, 99}, {44, 55, 66, 110}};
  int **ptr = (int **)matrix;
  printf("%d%d\n", **matrix, *ptr);

  int x[3][5] = {{1, 2, 10, 4, 5}, {6, 7, 1, 9, 10}, {11, 12, 13, 14, 15}};

  printf("%d\n", x);   // the results of these two lines are
  printf("%d\n", *x);  // exactly the same

  return 0;
}

/**********************************************************
  function definitions
***********************************************************/

void print_2d_arr(int rows, int cols, int arr[rows][cols]) {
  // notice: the numbers of both rows and cols were explicitly defined
  printf("\nResult: \n");
  for (int *ptr = &arr[0][0]; ptr <= &arr[rows - 1][cols - 1]; ptr++) {
    printf("%d ", *ptr);
  }
  printf("\n");
}

void print_2d_arr1(int rows, int cols, int arr[][cols]) {
  // notice: the number of rows was not explicitly defined
  printf("\nResult: \n");
  for (int *ptr = &arr[0][0]; ptr <= &arr[rows - 1][cols - 1]; ptr++) {
    printf("%d ", *ptr);
  }
  printf("\n");
}

/*
void print_2d_arr2(int rows, int cols, int arr[][]) {
  // TODO: error - array type has incomplete element type ‘int[]’
  printf("\nResult: \n");
  for (int *ptr = &arr[0][0]; ptr <= &arr[rows - 1][cols - 1]; ptr++) {
    printf("%d ", *ptr);
  }
  printf("\n");
}
*/

void print_2d_arr3(int rows, int cols, int *arr) {
  printf("\nResult: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", *((arr + i * cols) + j));
    }
    printf("\n");
  }
  printf("\n");
}

void print_2d_arr4(int rows, int cols, int (*arr)[cols]) {
  printf("Result: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_2d_arr5(int rows, int cols, int (*arr)[cols]) {
  printf("Result: \n");
  for (int *ptr = &arr[0][0]; ptr <= &arr[rows - 1][cols - 1]; ptr++) {
    printf("%d ", *ptr);
  }
  printf("\n");
}