/*
This sample shows how to read one line of user input with unknown length.
https://stackoverflow.com/questions/46395682/best-way-to-get-user-input-when-length-is-unknown-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This constant is small so you can easily examine how this code works in
// debugger Buffer increase step
#define BUFSTEP 5

int main() {
  char *in_str_buf;
  size_t buf_len;
  size_t str_len;

  in_str_buf = NULL;
  buf_len = 0;
  str_len = 0;

  // Read string by parts
  do {
    char *in_str_buf_new;

    if ((in_str_buf_new = realloc(in_str_buf, buf_len + BUFSTEP)) == NULL) {
      // realloc failed
      free(in_str_buf);
      return -1;
    }

    in_str_buf = in_str_buf_new;
    buf_len += BUFSTEP;
    if (fgets(in_str_buf + str_len, buf_len - str_len, stdin) == NULL) {
      // Error or end-of-file condition occured
      if (ferror(stdin)) {
        free(in_str_buf);
        return -2;
      }
      if (feof(stdin)) {
        break;
      }
    }
    str_len = strlen(in_str_buf);
  } while (str_len && in_str_buf[str_len - 1] != '\n');

  // Remove newline for convenience
  in_str_buf[str_len ? str_len - 1 : 0] = '\0';
  printf("Whole string: %s\n", in_str_buf);
  free(in_str_buf);
  return 0;
}