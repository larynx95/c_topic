#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char numbers[42][3] = {{0}};
  char names[42][14] = {{0}};

  for (int i = 0; i < 42; i++) {
    char* temp;
    sprintf(temp, "%02d", i);
    strcpy(numbers[i], temp);

    char chap[14] = "ch10_ex";
    strcat(chap, numbers[i]);
    strcat(chap, ".cpp");
    strcpy(names[i], chap);
  }

  int i = 0;
  while (*names[i]) printf("%s\n", names[i++]);

  FILE* fp;
  for (int i = 0; i < 42; i++) {
    fp = fopen(names[i], "w");
    fclose(fp);
  }

  return 0;
}