# Data types and builtin data structures

## Python

- Primitive types: Integer, Float, Strings, Boolean
- Non-Primitive types: Array, List, Tuple, Dictionay, Set, File
- Abstract data types: stack, queue, trie, tree, graph

## Go

- Basic types:
  - string
  - boolean (bool)
  - numeric: int8 (byte), int16, int32 (rune), int64
  - numeric: unit8, unit16, unit32, unit64
  - numeric: int, unit, uintptr
- Composite types: pointer, struct, function, container (array, slice, map), channel, interface
- References
  - [Go 101](https://go101.org/article/101.html)

## C

- Primitive types: void, int, char, double, float, int*, float*, char\*, \_Bool, \_Complex, \_Imaginary

  - short int: 2, -32,768~32,767, %hd
  - unsigned short int: 2, 0~65,535, %hu
  - unsigned int: 4, 0~4,294,967,295, %u
  - int: 4, -2,147,483,648~2,147,483,647, %d
  - long int: 4, -2,147,483,648~2,147,483,647, %ld
  - unsigned long int: 4, 0~4,294,967,295, %lu
  - long long int: 8, -(2^63)~(2^63)-1, %lld
  - unsigned long long int: 8, 0~18,446,744,073,709,551,615, %llu
  - signed char: 1, -128~127, %c
  - unsigned char: 1, 0~255, %c
  - float: 4, %f
  - double: 8, %lf
  - long double: 12, %Lf

- Derived data types: array, references, pointers
- User defined data types: struct, union, enumeration
- Abstract data types: stack, queue, linked list, tree

- References
  - [w3schools](https://www.w3schools.in/c-tutorial/data-types/)
  - [GeeksforGeeks](https://www.geeksforgeeks.org/data-types-in-c/)

## C++

- Primitive types: integer, character, boolean, float, double, void, whid character

- Containers

  - Sequence containers: vector, list, deque, arrays, forward_list
  - Container Adaptors: queue, priority_queue, stack
  - Associative Containers: set, multiset, map, multimap
  - Unordered Associative Containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap

- References
  - [GeeksforGeeks](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

## Java

- Primitive (atomic) data types: byte, short, int, long, float, double, boolean, char
- Collection
  - List: LinkedList, Stack, Vector, ArrayList
  - Set: HashSet, SortedSet, TreeSet
- Map: Hashtable, HashMap, SortedMap, TreeMap

## Kotlin

- Basic types: number, character, boolean, array, string
- Collections

  - Immutable: List, Set, Map
  - Mutable: MutableList, MutableSet, MutableMap

- References
  - [Kotlin Collections Overview](https://kotlinlang.org/docs/reference/collections-overview.html)

## Scala

- scala.collection
  - Seq: IndexedSeq, LinearSeq
  - Set: SortedSet
  - Map: SortedMap
- scala.collection.immutable
  - Seq: IndexedSeq, LinearSeq
  - Set: HashSet, ListSet, SortedSet
  - Map: HashMap, ListMap, SortedMap
- scala.collection.mutable

  - Seq: Stack, ArrayStack, LinearSeq, IndexedSeq, Buffer

- References
  - [MUTABLE AND IMMUTABLE COLLECTIONS](https://docs.scala-lang.org/overviews/collections/overview.html)

## Haskell

## R

- Six basic data types: character, numeric, integer, logical, complex
- Data structures: atomic vector, list, matrix, data frame, factors
