/*
Why it's bad to use feof() to control a loop

https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?id=1043284351&answer=1046476070
*/

#include <stdio.h>
#include <stdlib.h>

#define MYFILE "test.txt"

int main(void) {
  FILE *fp;
  char buf[BUFSIZ] = "Garbage";
  int i;

  if ((fp = fopen(MYFILE, "r")) == NULL) {
    perror(MYFILE);
    return (EXIT_FAILURE);
  }

  i = 0;

  while (!feof(fp)) {
    fgets(buf, sizeof(buf), fp);
    printf("Line %4d: %s", i, buf);
    i++;
  }

  fclose(fp);

  return (0);
}