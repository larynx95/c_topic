/*
Why is “while (!feof(file))” always wrong?

https://stackoverflow.com/questions/5431941/why-is-while-feoffile-always-wrong
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char *path = argc > 1 ? argv[1] : "test.txt";

  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    perror(path);
    return EXIT_FAILURE;
  }

  while (!feof(fp)) {
    /* THIS IS WRONG */
    /* Read and process data from file… */
    char str[10];
    fgets(str, 10, fp);
    printf("%s \n", str);
  }
  if (fclose(fp) == 0) {
    return EXIT_SUCCESS;
  } else {
    perror(path);
    return EXIT_FAILURE;
  }
}