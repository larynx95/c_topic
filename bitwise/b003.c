/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

003. Compute the integer absolute value (abs) without branching
http://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  int v;           // we want to find the absolute value of v
  unsigned int r;  // the result goes here

  v = -5;
  int const mask = v >> sizeof(int) * CHAR_BIT - 1;
  r = (v + mask) ^ mask;
  printf("absolute value of %d: %d\n", v, r);

  v = -5;
  r = (v < 0) ? -(unsigned)v : v;
  printf("absolute value of %d: %d\n", v, r);

  return 0;
}