---
title: Ch13 - Containers
layout: page
---

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

All containers are RAII wrappers around content. Chapter looks a sample of
containers from the standard library and Boost.

# Sequence Containers

Container that allows access from one end to the other end. Wide range of
trade-offs and performance characteristics.

## Arrays

`std::array` is a fixed sequence, like a raw array, but with many conviences and
features provided by the standard library. Prefer this type to raw arrays.

### Constructing

`std:array<T, S>` where T is the type of elements and S is a integer literal
of size of array.

### Element Access

Three main operators:

- `operator[]` - out of bounds undefined
- `at` - out of bounds throws runtime error
- `get` - out of bounds throws compile time error, index must be known during
          compilation.

`front` and `back` methods, undefined if array is zero length.

### Storage Model

> Moves can be expensive, depending on whether the underlying type of the array
  also has move construction and move assignment, which are relatively
  inexpensive.

Unclear why this isn't known?

Using raw array underneath, use `.data` to get a pointer to first element.

### A Crash Course on Iterators

Expose simple pointer like operations on any container. Must support at least
following operations:

1. Get current element with `operator*`.
2. Go to next element with  `operator++`.
3. Assign to another iterator with `operator=`.

`begin()` returns an iterator pointing to first element and `end()` to after the
last element. Since all containers implement these function and use them in
range expressions.

## Vectors

Dynamically sized list of elements. Vector has a modest overhead over array
with the same operations, usually your go to sequential data structure.

### Constructing

`std::vector<T, Allocator>` where `Allocator` defaults to a `std::allocator<T>`.
Allocator necessary to dynamically create new elements. A fill constructor
allows you to populate vector with the same value. It's easisest to not use
brace initilization when using a fill constructor to not have ambiguity. Can
constructor with two iterators to copy over a slice of another container.

### Move and Copy Semantics

Copy supported, expensive with 1 by 1 deep copy of elements. But moves fast
as elements are in dynamic memory and ownership just passed.

### Adding Elements

Use `assign` to replace all elements in a vector. `insert` adds element to
right before where given iterator is. The used iterator become invalid
since the vector changed. `push_back` inserts element to end of vector.
`emplace` and `emplace_back` construct elements of vector in place in the
vector, avoiding an extra copy from caller to vector.

NOTE: Interesting exercise would be implementing these vector methods
from scratch.

[Item 42: Effective Modern C++](
  https://learning.oreilly.com/library/view/effective-modern-c/9781491908419/ch08.html#consider_emplacement_instead_of_insertio) has more info.

### Storage Model

A vector occupies a contingious block of memory (I thought would have been a
linked list) and the allocator manages the dynamic memory of this block. A 
vector keeps a larger block then necessary, when it needs a new block it
will allocate a whole new area of memory to keep it continuous, copying
elements to this new block.

Inserting at end of vector is fast, anywhere in the middle has an extra cost
of moving elements. If you remove elements you can ask the allocator to
shrink the extra capacity with `shrink_to_fit`.

This is for Java, but data structure comparison with vector vs linked list
apply just as well:

https://stackoverflow.com/questions/322715/when-to-use-linkedlist-over-arraylist-in-java

And another great explantion that explains why this matters more with modern
processors then it use to:

https://www.reddit.com/r/learnprogramming/comments/10hwrmy/comment/j5axfze/?utm_source=share&utm_medium=web2x&context=3

## Niche Sequential Containers

### Deque

Sequential container with fast insert/remove at front and back. Memory is
scattered about, not sequential like a vector. Some implementation details
[here](https://www.geeksforgeeks.org/how-deque-works-internally-in-cpp/).
TLDR: blocks of memory are allocated, so some elements are sequential in
memory, but when more is needed a new block is created and linked to the
front or end. So elements are never moved around and they are not
guranteed to be close together, but many will be.

### Lists

Fast insert/remove operations everywhere, but no fast random element access.
Is a doubly linked list.

### Bitsets

A space efficient way to store a set number of bits, size passed as a template
parameter. Also has some useful functions for dealing with bits.

# Associative Containers

## Sets

A sorted sequence of elements, iterated in the order specified by `Comparator`.
Thd default `Comparator` is `std::less` and `Allocator` is `std::allocator<T>`.

Use `find` to get an iterator pointing to found element, if it doesn't exist
will be an `end` iterator. Lot's of other methods to access based on the
ordering of the Set.

`emplace_hint` takes an extract iterator as a place to start the search in
the set to find where to insert. If you insert an element already in the set
it has no effect.

Implemented as a red-black tree, section in 
[Data Structures and Algorithms in C++](
  https://learning.oreilly.com/library/view/data-structures-and/9780470383278/ch10.html#red-black_trees).

Free description of read-black trees:

https://www.geeksforgeeks.org/introduction-to-red-black-tree/

### Multisets

Same as Set, but the keys don't have to be unique.

## Unordered Sets

Unique keys but **not** ordered. Without ordering the keys are stored as a hash
table. Semantics of access/insert are similar to a set, but fundamentally
different data structures result in different performance characteristics.

Chapter 7 The C++ Standard Library [section](
  https://learning.oreilly.com/library/view/c-standard-library/9780132978286/ch07a.html#ch07lev1sec9)
on implementing custom hash functions.

Can be fast, but lot's of tuning parameters that can effect performance of the
hashing based on bucket size.

## Maps

key-value pairs, can think of a special type of set with values attached. Both
use red-black trees internally. Main benefit over a `set` of `pair` is
associative array operations `operator[]` and `at`.

# Graphs and Property Trees

`Boost Graph Library` (BGL) has three containers to represent graphs.
Also has a `ptree` container for property trees. This is useful for
configuration files, i.e. easy transformation to JSON & XML.

# Initializer List

Can use `std::initializer_list` to create your own container constructors
that take initialization lists.
