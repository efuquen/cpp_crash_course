---
title: Ch3 - Reference Types
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

# Pointers

Pointers encode an object's **address** and it's **type** to interact with it.
Low-level construct used often in C, but higher-level constructs in C++ reduce
use, but are still a foundational concept.

Section summary:
- Find address of an object and assigne to a pointer variable.
- *Dereferencing* a pointer to get the underlying object.
- Managing *arrays* and what can go wrong with array & pointer-based programs.
- Two special pointers, `void` and `std::byte` pointers.
- Encode empty pointers with `nullptr`.
- Pointers in Boolean expressions.

## Addressing Variables

Use the *address-of operator (&)* to obtain the address of a pointer, see
[`src/ch3/listings/3-1.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch3/listings/3-1.cpp).
Multiple runs will return different addresses dueo to
*address space layout randomization*.

### Address Space Layout Randomization

Malicuous code can be placed as input into a program to execute (i.e. Buffer
Overflow), but data is marked as non-executable. Using 
*return-oriented programs* system APIs could be forced to run to mark these
data payloads as executable. Randomizing the address space layout makes it
more difficult to do this.

## Dereferencing Pointers

The *dereference operator (*)* is used to access the underlying object in a
pointer. It can be used to assign new values to the object if it's on the
left-hand side (lhs) or read the actual values of the pointer if it's on the
right-hand side (rhs). See [`src/ch3/listing/3-2.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch3/listings/3-2.cpp) for example code.

## The Member-of-Pointer Operator

## Pointers and Arrays

### Handling Decay

### Pointer Arithmetic

## Pointers Are Dangerous

### Buffer Overflows

### Brackets and Pointer Arithmetic

## void & std::byte Pointers

## nullptr & Boolean Expressions

# References

# Usage of Pointers and References

## Forward-Linked Lists

## Employing References

## this Pointers

## const Correctness

### const Arguments

### const Methods

## const Member Variables

## Member Initializer Lists

# auto Type Deduction

## Initialization with auto

## auto and Reference Types

## auto and Code Refactorings




