## Simple Hardware Model
CPU and Memory (RAM)
- CPU storage consists of
	- Registers
	- CPU cache
- Memory RAM/DRAM?

## Requesting data from memory
Data to be used must be in a register
- if not in register, request it from memory

- __cache hit__: if data is in CPU cache; takes 2-20 cycles
- __cache miss__: if data not in cache; takes about 200 cycles

## Cache lines
Cache lines are sections of the CPU cache, typically 64 bytes
- when reading data from DRAM, an entire cache line is copied into cache
	- data remains in cache until replaced (according to cache replacement algorithm)

## Running time example: List Traversal
Assume: 4 cycles to read from cache line, 200 cycles to read from DRAM

#### Array
- elements are physically continuous in memory
Time to traverse 16 elements:
- 16 elements read into cache line at the same time
- 200 (read into cache) + 4 x 16 (read from cache) = 264
	- around 16 cycles per element

#### Linked List
- elements not physically continuous in memory
Time to traverse 16 elements:
- 200 * 16 = 3200
	- 12.5 times slower than array

## Cache Aware Algorithms
Two examples:
- Unrolled linked list
- B trees

