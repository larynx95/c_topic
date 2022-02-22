/*
Reading an unknown number of lines with unknown length from stdin

https://stackoverflow.com/questions/46656208/reading-an-unknown-number-of-lines-with-unknown-length-from-stdin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPTR 8

int main(int argc, char **argv) {
  size_t ndx = 0,     /* line index */
      nptrs = NPTR,   /* initial number of pointers */
      n = 0;          /* line alloc size (0, getline decides) */
  ssize_t nchr = 0;   /* return (no. of chars read by getline) */
  char *line = NULL,  /* buffer to read each line */
      **lines = NULL; /* pointer to pointer to each line */
  FILE *fp = argc > 1 ? fopen(argv[1], "r") : stdin;

  if (!fp) { /* validate file open for reading */
    fprintf(stderr, "error: file open failed '%s'.\n", argv[1]);
    return 1;
  }

  /* allocate/validate initial 'nptrs' pointers */
  if (!(lines = calloc(nptrs, sizeof *lines))) {
    fprintf(stderr, "error: memory exhausted - lines.\n");
    return 1;
  }

  /* read each line with POSIX getline */
  while ((nchr = getline(&line, &n, fp)) != -1) {
    if (nchr && line[nchr - 1] == '\n') /* check trailing '\n' */
      line[--nchr] = 0;                 /* overwrite with nul-char */
    char *buf = strdup(line);           /* allocate/copy line */
    if (!buf) {                         /* strdup allocates, so validate */
      fprintf(stderr, "error: strdup allocation failed.\n");
      break;
    }
    lines[ndx++] = buf; /* assign start address for buf to lines */
    if (ndx == nptrs) { /* if pointer limit reached, realloc */
      /* always realloc to temporary pointer, to validate success */
      void *tmp = realloc(lines, sizeof *lines * nptrs * 2);
      if (!tmp) { /* if realloc fails, bail with lines intact */
        fprintf(stderr, "read_input: memory exhausted - realloc.\n");
        break;
      }
      lines = tmp; /* assign reallocted block to lines */
      /* zero all new memory (optional) */
      memset(lines + nptrs, 0, nptrs * sizeof *lines);
      nptrs *= 2; /* increment number of allocated pointers */
    }
  }
  free(line); /* free memory allocated by getline */

  if (fp != stdin) fclose(fp); /* close file if not stdin */

  for (size_t i = 0; i < ndx; i++) {
    printf("line[%3zu] : %s\n", i, lines[i]);
    free(lines[i]); /* free memory for each line */
  }
  free(lines); /* free pointers */

  return 0;
}