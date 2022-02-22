/*
second example with reallocation in custom function
https://stackoverflow.com/questions/26537662/read-unknown-number-of-lines-from-stdin-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 255

/* function to free allocated memory */
void free_buffer(char **buffer) {
  register int i = 0;

  while (buffer[i]) {
    free(buffer[i]);
    i++;
  }

  free(buffer);
}

/* custom realloc using calloc/memcpy */
char **recalloc(size_t *lim, char **buf) {
  int newlim = *lim * 2;
  char **tmp = NULL;

  if ((tmp = calloc(newlim, sizeof(*buf)))) {
    if (memcpy(tmp, buf, *lim * sizeof(*buf)) == tmp) {
      free(buf);
      buf = tmp;
    } else {
      fprintf(stderr, "%s(): error, memcpy failed, exiting\n", __func__);
      return NULL;
    }
  } else {
    fprintf(stderr, "%s(): error, tmp allocation failed, exiting\n", __func__);
    return NULL;
  }

  *lim = newlim;

  return tmp;
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
  int linecnt = 0;
  size_t limit = MAXLINES;

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
      filebuf = recalloc(&limit, filebuf); /* reallocate filebuf to 2X size */
      if (!filebuf) {
        fprintf(stderr, "error: recalloc failed, exiting.\n");
        return 1;
      }
    }

    filebuf[linecnt] = strdup(line); /* copy line (strdup allocates)     */

    linecnt++; /* increment linecnt                */
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