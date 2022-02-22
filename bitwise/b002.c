/**********************************************************
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

002. Detect if two integers have opposite signs
http://graphics.stanford.edu/~seander/bithacks.html#DetectOppositeSigns

a b a ^ b (a XOR b)
-------------------
0 0 0
0 1 1
1 0 1
1 1 0

dec   bin          two'scomplement: (2^3 - n)2
----------------------------------------------
3     011          101
2     010          110
1     001          111
0     000          000
-1    111          001
-2    110          010
-3    101          011
-4    100          100

dec   bin          two'scomplement: (2^8 - n)2
----------------------------------------------
127   0111 1111    1000 0001
126   0111 1110    1000 0010
2     0000 0010    1111 1110
1     0000 0001    1111 1111
0     0000 0000    0000 0000
−1    1111 1111    0000 0001
−2    1111 1110    0000 0010
−126  1000 0010    0111 1110
−127  1000 0001    0111 1111
−128  1000 0000    1000 0000

**********************************************************/

#include <stdbool.h>
#include <stdio.h>

int main() {
  int x, y;              // input values to compare signs
  bool f = (x ^ y) < 0;  // true iff x and y have opposite signs

  return 0;
}