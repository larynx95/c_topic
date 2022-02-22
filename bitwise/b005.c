/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

005. Determining if an integer is a power of 2
http://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  unsigned int v;  // we want to see if v is a power of 2
  bool f;          // the result goes here

  v = 15;
  f = (v & (v - 1)) == 0;
  printf("Is %4d a power of 2? %d\n", v, f);

  v = 0;
  f = (v & (v - 1)) == 0;
  printf("Is %4d a power of 2? %d\n", v, f);  // incorrect

  v = 16;
  f = v && !(v & (v - 1));
  printf("Is %4d a power of 2? %d\n", v, f);  // fixed

  return 0;
}