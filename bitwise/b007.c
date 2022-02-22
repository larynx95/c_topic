/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

007. Sign extending from a variable bit-width
http://graphics.stanford.edu/~seander/bithacks.html#VariableSignExtend

TODO: What is the sign extension?
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  unsigned b;                   // number of bits representing the number in x
  int x;                        // sign extend this b-bit number to r
  int r;                        // resulting sign-extended number
  int const m = 1U << (b - 1);  // mask can be pre-computed if b is fixed

  x = x & ((1U << b) - 1);
  // (Skip this if bits in x above position b are already zero.)
  r = (x ^ m) - m;

  return 0;
}