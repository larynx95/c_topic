/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

008. Sign extending from a variable bit-width in 3 operations
http://graphics.stanford.edu/~seander/bithacks.html#VariableSignExtendRisky

TODO: What is the sign extension?
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  unsigned b;  // number of bits representing the number in x
  int x;       // sign extend this b-bit number to r
  int r;       // resulting sign-extended number

#define M(B) (1U << ((sizeof(x) * CHAR_BIT) - B))  // CHAR_BIT=bits/byte
  static int const multipliers[] = {
      0,     M(1),  M(2),  M(3),  M(4),  M(5),  M(6),  M(7),  M(8),
      M(9),  M(10), M(11), M(12), M(13), M(14), M(15), M(16), M(17),
      M(18), M(19), M(20), M(21), M(22), M(23), M(24), M(25), M(26),
      M(27), M(28), M(29), M(30), M(31), M(32)};  // (add more if using more
                                                  // than 64 bits)
  static int const divisors[] = {
      1,     ~M(1), M(2),  M(3),  M(4),  M(5),  M(6),  M(7),  M(8),
      M(9),  M(10), M(11), M(12), M(13), M(14), M(15), M(16), M(17),
      M(18), M(19), M(20), M(21), M(22), M(23), M(24), M(25), M(26),
      M(27), M(28), M(29), M(30), M(31), M(32)};  // (add more for 64 bits)
#undef M
  r = (x * multipliers[b]) / divisors[b];

  const int s = -b;  // OR:  sizeof(x) * CHAR_BIT - b;
  r = (x << s) >> s;

  return 0;
}