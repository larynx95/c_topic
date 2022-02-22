/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

012. Counting bits set (naive way)
http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive

Count set bits in an integer
https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

**********************************************************/

#include <stdbool.h>
#include <stdio.h>

int main() {
  unsigned int v;  // count the number of bits set in v
  unsigned int c;  // c accumulates the total bits set in v

  v = 9;
  for (c = 0; v; v >>= 1) {
    c += v & 1;
  }
  printf("%d\n", c);

  return 0;
}

/*
  13 == 1 1 0 1
        ---   -
        (2)  (1)
        -------
        (3)       three set bit

  9 ==  1 0 0 1
        -     -
        (2)  (1)  two set bit
*/