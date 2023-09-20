---
title: Ch14 - Iterators
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

# Iterator Categories

Categories determine operations iterator supports. Iterator types
tuse tempate parameters to distinguish them. Might never need to do this
directly, but need to understand what type of iterators needed in
libraries.

## Output Iterators

Write to and increment only. Write, increment, write, increment ...
After a write you must increment to write again. `*` and assign to
write, use `++` to increment.

### Insert Iterators

`back_inserter` uses `push_back`, `front_inserter` uses `push_front` and `inserter`
uses `insert` to add to the container. The relevant container must support
these functions to bild the respective iterator.

## Input Iterators

Opposite of output, you read and increment only in alternating order. Can only
iterate through it once. Necessary for range-based for loops. All containers
*at least* implement input iterators with `begin`, `cbegin`, `end`, and `cend`.

## Forward Iterators

Input iterator that can be traversed multiple times.

There are some references that imply forward iterators are *unquestionably*
mutable and output iterators:

https://www.geeksforgeeks.org/forward-iterators-in-cpp/

This is actually all pretty confusing, see this Stack Overflow answer:

https://stackoverflow.com/a/14058712

Also `forward_list` is a single-linked list as opposed to the double-linked
list of `std::list`:

https://cplusplus.com/reference/forward_list/forward_list/

## Bidirectional Iterators

Forward iterator that can go backwards, the iterator of `std::list` type.
Use `--` to go backwards.

## Random-Access Iterators

Bidirectional iterator that supports random access, using `[]`.

## Contiguous Iterators

Randomn access iterator with elements contiguous in memory.

## Mutable Iterators

Forward, bidirectinal, and randomn-access iterators **can** support read-only
or read-and-write modes. Such iterators types would be qualified as mutable.
You can extract a mutable iterator from a non-const container.

# Auxilary Iterator Functions

Prefer these auxilary functions in `<iterator>` to direct functions as they
will perform operations in most efficient method based on iterator type.

## std::advance

Advance an arbitraty amount into an iterator. Does **not** perform bound
checking.

## std::next and std::prev

Returns a new iterator at specified distance from current iterator without
changing the input iterator. Again, **no** bounds checking.

## std::distance

Get the distance between two iterators, `itr2` *should* come after `itr1`
to avoid any issue with not usinga random access iterator.

## std::iter_swap

Swap two iterator locations.

# Addtional Iterator Adapters

## Move Iterator Adapters

Changes iterator access to a move operation, clobbering origina values
in the original iterators container. Use `std::make_move_iterator` to
create the move iterators.

## Reverse Iterator Adapters

Passes in an iterator that goes in the opposite direction, with
`rbegin`, `rend`, `crbegin`, `crend`. Can also convert a normal iterator
to reverse with `std::make_reverse_iterator`.