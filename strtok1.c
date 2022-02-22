/*
`strtok()`: Split a string into tokens
https://stackoverflow.com/questions/20305853/length-of-string-returned-by-strtok
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char str[] = "Hello world!";
  char* word = strtok(str, " ");
  printf("%s %d\n", word, strlen(word));
  while (word != NULL) {
    word = strtok(NULL, " ");
    if (word != NULL) {
      printf("%s %d\n", word, strlen(word));
    }
  }

  // `char str1[] = "hello world!";`
  char str1[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w',
                 'o', 'r', 'l', 'd', '!', '\0'};
  char* word1 = strtok(str1, " ");
  printf("%s %d\n", word1, strlen(word1));
  while (word1 != NULL) {
    word1 = strtok(NULL, " ");
    if (word1 != NULL) {
      printf("%s %d\n", word1, strlen(word1));
    }
  }

  // https://stackoverflow.com/questions/4090434/strtok-char-array-versus-char-pointer
  char* str2 = strdup("Hello world!");
  char* word2 = strtok(str, " ");
  printf("%s %d\n", word2, strlen(word2));
  while (word2 != NULL) {
    word2 = strtok(NULL, " ");
    if (word2 != NULL) {
      printf("%s %d\n", word2, strlen(word2));
    }
  }
}