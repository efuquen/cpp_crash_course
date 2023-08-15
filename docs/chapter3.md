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
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch3/listings/3-2.cpp)
for example code.

## The Member-of-Pointer Operator

Short description of how `clock_ptr->get_year()` is a notional short hand for
`(*clock_ptr).get_year()`.

## Pointers and Arrays

Arrays act similarly to pointers, just storing an extra piece of data, the
length of the array. Arrays can be passed into variables that expect a pointer,
'decaying' into a pointer and lossing it's length information. The pointed to
location is always the first element of the array.

### Handling Decay

Pass in the size of an array and it's pointers. Square brackets `[]` can also be
used on pointers.

### Pointer Arithmetic

Adding numeric values to a pointer is an alternatives to a square bracket and
dereferencing syntax. The compiler knows how large the pointer is and will
travel that far in memory to the next value.

## Pointers Are Dangerous

All the pointer manipulations above are dangerous.

### Buffer Overflows

You can go past the points of an array without any warning or error. Aside from getting garbage
data that can crash your program the far worse thing is this a common form of security
vulnerability.

More details on security vulnerability:

<https://owasp.org/www-community/vulnerabilities/Buffer_Overflow>

### Brackets and Pointer Arithmetic

This basically just shows the same vulnerability with pointer arthmetic, which as already
discussed is just a replacement for square bracket access.

**Question 3.1**: *There are a lot more reasons and examples that could be*
*given about the dangers of manipulating raw pointers, do you know some?*

## void & std::byte Pointers

You can use `void*` when you need to pass a pointer but the type doesn't matter. You cannnot
dereference or use pointer arthmetic.

If  you need to access the raw bytes use `std::byte`.

NOTE: Examples would be useful here.

## nullptr & Boolean Expressions

A `nullptr` indicates an empty pointer value and will evaluate to a `false` boolean expression,
while all other values would evaluate to `true`.

# References

References are safer then pointers, they cannot be assigned `null` 'easily' or
reassigned.

# Usage of Pointers and References

You would need to use pointers if you need to reassign the reference.

## Forward-Linked Lists

Text gives an example of linked lists implementaion that requires pointers.

See [`src/ch3/listing/3-10.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch3/listings/3-10.cpp)

**Question 3.2**: *Why use `char[2]` as the `prefix` instead of `char *`?*

**Question 3.3**: *Why is `Element` really not that generic and how could it*
*be made more generic?*

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




