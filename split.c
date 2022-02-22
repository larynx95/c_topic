/*
`readline()`
`strtok()`
https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split
https://stackoverflow.com/questions/29638598/strtok-why-you-have-to-pass-the-null-pointer-in-order-to-get-the-next-token
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char* str);

int main() {
  /* simple split*/
  char buf[] = "abc/qwe/ccd";
  int i = 0;
  char* p = strtok(buf, "/");
  char* array[3];  // TODO: if we don't know this number?

  while (p != NULL) {
    array[i++] = p;
    p = strtok(NULL, "/");
  }

  for (i = 0; i < 3; ++i) printf("%s\n", array[i]);

  return 0;
}

/*
readline and return a line of string
*/
char* readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char* data = malloc(alloc_length);

  while (true) {
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line) {
      break;
    }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
      break;
    }

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data) {
      break;
    }

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n') {
    data[data_length - 1] = '\0';
  }

  data = realloc(data, data_length);

  return data;
}

char** split_string(char* str) {
  char** splits = NULL;
  char* token = strtok(str, " ");

  int spaces = 0;

  while (token) {
    splits = realloc(splits, sizeof(char*) * ++spaces);
    if (!splits) {
      return splits;
    }

    splits[spaces - 1] = token;
    token = strtok(NULL, " ");
  }

  return splits;
}