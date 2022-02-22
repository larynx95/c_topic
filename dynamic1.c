/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

int main(void) {
  char **arr_lines;
  char buf_file[BUFSIZE], buf_line[16];
  int num_lines = 0;

  // open file
  FILE *fp = fopen("test.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return -1;
  }
  // get number of lines; from http://stackoverflow.com/a/3837983
  while (fgets(buf_file, BUFSIZE, fp))
    if (!(strlen(buf_file) == BUFSIZE - 1 && buf_file[BUFSIZE - 2] != '\n'))
      num_lines++;
  // allocate memory
  arr_lines = malloc(num_lines * sizeof(char *));
  // read lines
  rewind(fp);
  num_lines = 0;
  while (!feof(fp)) {
    fscanf(fp, "%s", buf_line);
    strcpy(arr_lines[num_lines], buf_line);
    num_lines++;
  }
  // print first four lines
  printf("%s\n%s\n%s\n%s\n", arr_lines[0], arr_lines[1], arr_lines[2],
         arr_lines[3]);
  // finish
  fclose(fp);

  return 0;
}