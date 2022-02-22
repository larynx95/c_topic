/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

009. Conditionally set or clear bits without branching
http://graphics.stanford.edu/~seander/bithacks.html#ConditionalSetOrClearBitsWithoutBranching

TODO: ??
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  bool f;          // conditional flag
  unsigned int m;  // the bit mask
  unsigned int w;  // the word to modify:  if (f) w |= m; else w &= ~m;

  w ^= (-f ^ w) & m;

  // OR, for superscalar CPUs:
  w = (w & ~m) | (-f & m);

  return 0;
}