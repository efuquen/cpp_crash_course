---
title: Ch4 - The Object Life Cycle 
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

# An Object's Storage Duration

## Allocation, Deallocation, and Lifetime

Object stages:

1. Storage allocated, duration begins.
2. Constructor called
3. Lifetime begins.
4. Do stuff
5. Lifetime ends.
6. Destructor called.
7. STorage deallocated, duration ends.

## Memory Manaement

Describes memory managed languages and how C++ does not do this for the
programmer for greater runtime performance.

**Question 4.1**: *The author glosses over the pros and cons, but memory
management of vital importance when choosing a language. Can you think of more
pros and cons of memory management and/or specific examples from lanugages? Why
would you (or **must**) you use a non-memory managed language like C/C++.*

## Automatic Storage Duration

Allocation at beginning and end of a code block, with function parameters
counting as within the function code block. Automatic variables also called
local variables.

## Static Storage Duration

`static` or `extern` variables at global scope, allocated on program start
and deallocated on program stop. `static` variables have 'internal linkage',
meaning they are not accessible from external translation units (essentially
a C++ source file). To access from external translation units use `extern`.

### Local Static Variables

`static` variables in a local scope storage duration begins when first defined
in that local scope but last until the end of the program. The static variable
is not accessible outside that local scope.

### Static Members

Members of a class declared static have separate lifetimes from the class,
having same duration as a global static variable, just namespaced by the
`Class` name.

## Thread-Local Storage Duration

A variable can have a `thread_local` modifier that keeps a separate copy for
each thread. Lot more to say about concurrency later.

## Dynamic Storage Duration

Dynamic objects allocated with `new` keyword and programmer has direct control
on their storage duration. The pointer returned by `new` can be deallocated
with a call to `delete`.

What happens to deallocated memory in dynamic storage is undefined, but the
compiler pratically won't overwrite it unless it needs it for performance
reasons. This is a major source of program errors and possible security
vulnerabilities, as this means the memory could accidentally continued to be
used (use-after-free).

A short description of a possible security vulnerability with Use-After-Free
<https://6point6.co.uk/insights/common-software-vulnerabilities-part-ii-explaining-the-use-after-free/>

**NOTE**: *You should really avoid using `new` and `delete` directly as much
as possible and use more advanced pointers introduced later.*

See a more complete warning and suggestion on this in this other books Memory
Management chapter:

<https://learning.oreilly.com/library/view/professional-c-5th/9781119695400/c07.xhtml#head-2-90>

### Dynamic Arrays

Examples using `new` to dynamic storage arrays. Array length can be specified
at runtime and hence can be a variable.

### Memory Leaks

Basic warning about memory leaks, could be more in-depth.

# Tracing the Object Life Cycle

A walk through of implementing a `Tracer` class that illustrates a number of the
lifecycle scenarios listed above.

See [`src/ch4/listings/4-6.cpp`](
    https://github.com/efuquen/cpp_crash_course/blob/main/src/ch4/listings/4-6.cpp).

# Exceptions

## The throw Keyword

## Using try-catch Blocks

## stdlib Exceptoin Classes

### Standard Exception Classes

### Logic Errors

### Runtime Errors

### Launguage Support Errors

## Handling Exceptions

## User-Defined Exceptions

## The noexcept Keyword

## Call Stacks and Exceptions

### Stacks

### Call Stacks and Exception Handling

### Throwing in Destructors

# A SimpleString Class

## Appending and Printing

## Using SimpleString

## Composing a SimpleString

## Call Stack Unwinding

## Exceptions and Performance

## Alternatives to Exceptions

# Copy Semantics

## Copy Constructors

## Copy Assignment

## Default Copy

## Copy Guidelines

# Move Semantics

## Copying Can Be Wasteful

## Value Categories

## lvalue and rvalue References

## The std::move Function

## Move Construction

## Move Assignment

## The Final Product

## Compiler Generated Methods