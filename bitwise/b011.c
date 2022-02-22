/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

011. Merge bits from two values according to a mask
http://graphics.stanford.edu/~seander/bithacks.html#MaskedMerge

What is a bitmask and a mask?
https://stackoverflow.com/questions/31575691/what-is-a-bitmask-and-a-mask

TODO: ??
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  unsigned int a;     // value to merge in non-masked bits
  unsigned int b;     // value to merge in masked bits
  unsigned int mask;  // 1 where bits from b should be selected; 0 where from a.
  unsigned int r;     // result of (a & ~mask) | (b & mask) goes here

  a = 6, b = 3, mask = 0;
  r = a ^ ((a ^ b) & mask);
  printf("%d\n", r);  // 6

  a = 6, b = 3, mask = 1;
  r = a ^ ((a ^ b) & mask);
  printf("%d\n", r);  // 7

  /*
  a = 0b00110 = 6
  b = 0b00011 = 3
      0b00111 = 7
      0b00
  */

  return 0;
}