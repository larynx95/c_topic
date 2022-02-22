/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

004. Compute the minimum (min) or maximum (max) of two integers without
branching http://graphics.stanford.edu/~seander/bithacks.html#IntegerMinOrMax
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  int x;  // we want to find the minimum of x and y
  int y;
  int r;  // the result goes here

  x = 5, y = 8;

  /* min */
  r = y ^ ((x ^ y) & -(x < y));  // min(x, y)
  printf("min(%d, %d): %d\n", x, y, r);

  /* max */
  r = x ^ ((x ^ y) & -(x < y));  // max(x, y)
  printf("max(%d, %d): %d\n", x, y, r);

  /* if INT_MIN <= x - y <= INT_MAX */
  r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));  // min(x, y)
  printf("min(%d, %d): %d\n", x, y, r);
  r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));  // max(x, y)
  printf("max(%d, %d): %d\n", x, y, r);

  return 0;
}