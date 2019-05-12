# Linked List
- __dynamic__ data structure: adding new element (when list is full) is O(1)
	- as opposed to adding new element to full array (not dynamic) which takes O(n)

# Unrolled Linked List
List nodes consist of
- a half-filled (at least) array of elements
- a pointer to the next node

# Comparison: Array, Linked List, Unrolled Linked List

Assume
- n: number of elements
- cache hit: 5 cycles
- cache miss: 200 cycles
- item size: 4 bytes
- for unrolled linked list
	- pointer: 8 bytes
	- size variable: 4 bytes
	- metadata: 4 bytes

## Array
- cache misses = n/16

__Traversal cycles__ = 5n + 200n/16 = 17.5n

## Linked List
- cache misses = n

__Traversal cycles__ = 5n + 200n = 205n

## Unrolled Linked List
- cache misses = n/8 x (4 x 16 + 16)/64 ?? = 5n x32

__Traversal cycles__ = 5n + 200 x 5n/32 = 34n