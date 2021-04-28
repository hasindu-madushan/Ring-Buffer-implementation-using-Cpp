# A ring buffer

In this effient queue implementation, items are inserted(Enqueue) at tail and items removed(Dequeue) at the head. Each time we enqueue an element, the index of the tail will be increased by one. 
And each time we dequeue an element the head will be increased by one. When the tail reaches the end of the fixed size array it will be wrapped back around to the index 0 of the
array.


REFERENCE:
  1. Game Programming Patterns. Robert Nystrom
