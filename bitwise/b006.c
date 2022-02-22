/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

006. Sign extending from a constant bit-width
http://graphics.stanford.edu/~seander/bithacks.html#FixedSignExtend

“:” (colon) in C struct - what does it mean? [duplicate]
https://stackoverflow.com/questions/8564532/colon-in-c-struct-what-does-it-mean

TODO: What is the sign extension?
**********************************************************/

#include <stdbool.h>
#include <stdio.h>
#define CHAR_BIT 8  // a byte is 8 bits

int main() {
  int x;  // convert this from using 5 bits to a full int
  int r;  // resulting sign extended number goes here

  x = -1;
  struct {
    signed int x : 5;  // 0b00000   16 ~ -17
  } s;
  r = s.x = x;
  printf("%d\n", r);

  return 0;
}