/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

010. Conditionally negate a value without branching
http://graphics.stanford.edu/~seander/bithacks.html#ConditionalNegate

TODO: ??
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  /* If you need to negate only when a flag is false,
     then use the following to avoid branching: */
  bool fDontNegate;  // Flag indicating we should not negate v.
  int v;             // Input value to negate if fDontNegate is false.
  int r;             // result = fDontNegate ? v : -v;
  r = (fDontNegate ^ (fDontNegate - 1)) * v;

  /* If you need to negate only when a flag is true, then use this: */
  bool fNegate;  // Flag indicating if we should negate v.
  int v;         // Input value to negate if fNegate is true.
  int r;         // result = fNegate ? -v : v;
  r = (v ^ -fNegate) + fNegate;

  return 0;
}