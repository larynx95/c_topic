/*
content of test.txt

first
second
third
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // double pointer for two string lines
  // and the two string lines will be pointed by (char *) pointer
  FILE *fp = fopen("test.txt", "r");
  char **lst = malloc(3 * sizeof(char *));

  // read lines until feof(fp) is not Null
  // Only 2 lines will be read by this loop
  int i = 0;
  int c;
  while (fgetc(fp) != EOF) {
    char line[10];
    fgets(line, 10, fp);
    *(lst + i) = line;
    printf("%d : %s", i, *(lst + i));
    i++;
  }

  /*
  Result:

  0 : first
  1 : second
  2 : third     // Why was this line printed here?

  There are 3 lines, not 2 lines!
  */

  printf("\n\n");

  int j;
  for (j = 0; j < i; j++) {
    printf("%d : %s\n", j, *(lst + j));
  }

  /*
  result:

  0 : third
  1 : third
  2 : third

  The whole lines were not printed correctly!
  */

  for (int i = 0; i < 3; i++) {
    free(lst[i]);
  }
  free(lst);
  fclose(fp);
  return 0;
}
