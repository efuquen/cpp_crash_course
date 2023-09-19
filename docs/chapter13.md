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

## Niche Sequential Containers

### Dequeue

### Lists

### Stacks

### Queues

### Priority Queues (Heaps)

### Bitsets

### Special Sequential Boost Containers

# Associative Containers

## Sets

## Multisets

## Maps

## Multimaps

# Graphs and Property Trees

# The Boost Graph Library

# Boost Property Trees

# Initializer Lists
