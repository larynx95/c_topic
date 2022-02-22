/*
first example with reallocation in main()
https://stackoverflow.com/questions/26537662/read-unknown-number-of-lines-from-stdin-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 255

void free_buffer(char **buffer) {
  register int i = 0;

  while (buffer[i]) {
    free(buffer[i]);
    i++;
  }

  free(buffer);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Error: insufficient input. Usage: %s input_file\n",
            argv[0]);
    return 1;
  }

  char *line = NULL; /* forces getline to allocate space for buf */
  ssize_t read = 0;  /* number of characters read by getline     */
  size_t n = 0;      /* limit number of chars to 'n', 0 no limit */
  char **filebuf = NULL;
  char **rtmp = NULL;
  int linecnt = 0;
  size_t limit = MAXLINES;
  size_t newlim = 0;

  FILE *ifp = fopen(argv[1], "r");
  if (!ifp) {
    fprintf(stderr, "\nerror: failed to open file: '%s'\n\n", argv[1]);
    return 1;
  }

  filebuf = calloc(MAXLINES, sizeof(*filebuf)); /* allocate MAXLINES pointers */

  while ((read = getline(&line, &n, ifp)) !=
         -1) /* read each line in file with getline  */
  {
    if (line[read - 1] == 0xa) {
      line[read - 1] = 0;
      read--;
    } /* strip newline         */

    if (linecnt >= (limit - 1)) /* test if linecnt at limit, reallocate */
    {
      newlim = limit * 2; /* set new number of pointers to 2X old */
      if ((rtmp =
               calloc(newlim, sizeof(*filebuf)))) /* calloc to set to NULL    */
      {
        /* copy original filebuf to newly allocated rtmp */
        if (memcpy(rtmp, filebuf, linecnt * sizeof(*filebuf)) == rtmp) {
          free(filebuf);  /* free original filebuf                */
          filebuf = rtmp; /* set filebuf equal to new rtmp        */
        } else {
          fprintf(stderr, "error: memcpy failed, exiting\n");
          return 1;
        }
      } else {
        fprintf(stderr, "error: rtmp allocation failed, exiting\n");
        return 1;
      }
      limit = newlim; /* update limit to new limit    */
    }

    filebuf[linecnt] = strdup(line); /* copy line (strdup allocates) */

    linecnt++; /* increment linecnt            */
  }

  fclose(ifp);

  if (line) free(line); /* free memory allocated to line    */

  linecnt = 0; /* reset linecnt to iterate filebuf */

  printf("\nLines read in filebuf buffer:\n\n"); /* output all lines read */
  while (filebuf[linecnt]) {
    printf(" line[%d]: %s\n", linecnt, filebuf[linecnt]);
    linecnt++;
  }

  printf("\n");

  free_buffer(filebuf); /* free memory allocated to filebuf */

  return 0;
}