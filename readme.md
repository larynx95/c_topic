# Questions

## File read, STDIN

### Processes

- Does the file exist?
  - if exists then...
  - if doesn't exists then...
- file types
  - text, binary, csv, ...
- Checking file content
  - Where is the end of file (**EOF**)?
    - [Representing EOF in C code? - stackoverflow](https://stackoverflow.com/questions/12389518/representing-eof-in-c-code)
    - getc(), getchar()
    - feof()
  - line breaker ('\n'), trailing space
    - first or last line?
  - sentece vs. word ('\s')
    - **string split** by deliminator
- Data structure where file content will be stored
  - Immutable Array
  - Mutable data structure? (Linked list?)
- static vs. dynamic assign
  - [Dynamic Memory Allocation in C using malloc(), calloc(), free() and realloc()](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- Type conversion

### Implementation

- file read
  - just print, into array
- stdin read
  - just print, and into array

## Dynamic memory allocation
